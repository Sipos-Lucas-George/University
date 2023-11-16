import 'package:flutter/material.dart';

class CarRepositoryProvider extends ChangeNotifier {
  final CarRepository carRepository = CarRepository();

  void addCar(Car car) {
    carRepository.addCar(car);
    notifyListeners();
  }

  void updateCar(int id, Car car) {
    carRepository.updateCar(id, car);
    notifyListeners();
  }

  void deleteCar(int id) {
    carRepository.deleteCar(id);
    notifyListeners();
  }

  List<Car> getAllCars() {
    return carRepository.getAllCars();
  }

  Car operator [](int index) {
    return carRepository.getAllCars().firstWhere((car) => car.id == index);
  }
}

class CarRepository {
  List<Car> _cars = [];
  int identity = 1;

  CarRepository() {
    _cars = List.generate(2, (index) {
      if (index % 2 == 0) {
        return Car(
            id: identity++,
            model: 'Model $index',
            year: 2023 - index,
            fuelType: 'Gas',
            cc: 2.0 + index,
            hp: 150 + index * 10,
            transmissionType: 'Automatic',
            image: "");
      } else {
        return Car(
            id: identity++,
            model: 'Model $index',
            year: 2023 - index,
            fuelType: 'Gas',
            transmissionType: 'Automatic',
            image: "");
      }
    });
  }

  int get length => _cars.length;

  Car operator [](int index) {
    if (index >= 0 && index < _cars.length) {
      return _cars[index];
    }
    throw RangeError("Index $index is out of bounds for CarRepository");
  }

  void addCar(Car car) {
    car.id = identity++;
    _cars.add(car);
  }

  void updateCar(int id, Car car) {
    Car updateCar = _cars.firstWhere((updateCar) => updateCar.id == id);
    if (updateCar.model != car.model) updateCar.model = car.model;
    if (updateCar.year != car.year) updateCar.year = car.year;
    if (updateCar.cc != car.cc) updateCar.cc = car.cc;
    if (updateCar.hp != car.hp) updateCar.hp = car.hp;
    if (updateCar.fuelType != car.fuelType) updateCar.fuelType = car.fuelType;
    if (updateCar.transmissionType != car.transmissionType) updateCar.transmissionType = car.transmissionType;
    if (updateCar.image != car.image) updateCar.image = car.image;
  }

  void deleteCar(int id) {
    _cars.removeWhere((car) => car.id == id);
  }

  List<Car> getAllCars() {
    return List.from(_cars);
  }
}

class Car {
  int? id;
  String model;
  int? year;
  String fuelType;
  double? cc;
  int? hp;
  String transmissionType;
  String image;

  Car({
    this.id,
    required this.model,
    this.year,
    required this.fuelType,
    this.cc,
    this.hp,
    required this.transmissionType,
    required this.image,
  });

  String getTitle() {
    return '$model ${year ?? ""}';
  }

  List<Map<String, String>> getDetails() {
    List<Map<String, String>> details = [
      if (cc != null) {'CC: ': '$cc'},
      if (hp != null) {'HP: ': '$hp'},
      {'Fuel: ': fuelType},
      {'Trans: ': transmissionType},
    ];
    return details;
  }
}

class Pair<T, U> {
  final T first;
  final U second;

  Pair(this.first, this.second);

  @override
  String toString() {
    return 'Pair($first, $second)';
  }
}
