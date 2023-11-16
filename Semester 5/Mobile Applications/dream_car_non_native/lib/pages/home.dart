import 'dart:io';

import 'package:flutter/material.dart';
import 'package:dream_car_non_native/pages/car.dart';
import 'package:provider/provider.dart';

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  _HomeState createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    CarRepositoryProvider carsProvider =
        Provider.of<CarRepositoryProvider>(context);
    CarRepository cars = carsProvider.carRepository;
    return Scaffold(
        appBar: AppBar(
          centerTitle: true,
          title: const Text(
            "Dream Car",
            style: TextStyle(
              color: Colors.black,
              fontWeight: FontWeight.w400,
              fontSize: 25,
            ),
          ),
          backgroundColor: Colors.white,
        ),
        body: Column(
          children: [
            Expanded(
              child: Scrollbar(
                child: ListView.builder(
                  itemBuilder: (context, index) {
                    return Padding(
                      padding: const EdgeInsets.symmetric(
                          vertical: 4, horizontal: 8),
                      child: CarListItem(
                        car: cars[index],
                        openDialog: ValueNotifier<bool>(false),
                        deleteText: ValueNotifier<String>(""),
                        cars: carsProvider,
                      ),
                    );
                  },
                  itemCount: cars.length,
                ),
              ),
            ),
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 8),
              child: Container(
                color: Colors.transparent,
                width: double.infinity,
                child: ElevatedButton(
                  onPressed: () {
                    Navigator.pushNamed(context, "/create");
                  },
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.white,
                    shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(50)),
                    padding: const EdgeInsets.symmetric(
                      vertical: 10,
                      horizontal: 25,
                    ),
                    maximumSize: const Size(double.infinity, double.infinity),
                    shadowColor: Colors.black.withOpacity(0.7),
                    elevation: 4,
                  ),
                  child: const Icon(
                    Icons.add,
                    color: Colors.black,
                    size: 30,
                  ),
                ),
              ),
            ),
          ],
        ));
  }
}

Widget CarListItem({
  required Car car,
  required ValueNotifier<bool> openDialog,
  required ValueNotifier<String> deleteText,
  required CarRepositoryProvider cars,
}) {
  if (car.id == 0) return const Text("");

  ValueNotifier<bool> expanded = ValueNotifier<bool>(false);

  ValueNotifier<Pair<double, double>> sizeImage =
      ValueNotifier<Pair<double, double>>(
    expanded.value ? Pair(180, 98.1) : Pair(99, 54),
  );

  ValueNotifier<double> sizeFont = ValueNotifier<double>(
    expanded.value ? 18 : 22,
  );

  ValueNotifier<int> sizeFill = ValueNotifier<int>(
    expanded.value ? 5 : 7,
  );

  ValueNotifier<double> sizeRound = ValueNotifier<double>(
    expanded.value ? 30 : 50,
  );
  expanded.addListener(() {
    sizeFont.value = expanded.value ? 18 : 22;
    sizeRound.value = expanded.value ? 30 : 50;
    sizeFill.value = expanded.value ? 5 : 7;
    sizeImage.value = expanded.value ? Pair(180, 98.1) : Pair(99, 54);
  });

  return ValueListenableBuilder<double>(
      valueListenable: sizeRound,
      builder: (BuildContext context, double sizeRound, Widget? child) {
        return ElevatedButton(
          onPressed: () {
            expanded.value = !expanded.value;
          },
          style: ElevatedButton.styleFrom(
            backgroundColor: Colors.white,
            shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(sizeRound)),
            padding: const EdgeInsets.symmetric(
              vertical: 10,
              horizontal: 25,
            ),
            maximumSize: const Size(double.infinity, double.infinity),
            shadowColor: Colors.black.withOpacity(0.4),
            elevation: 4,
          ),
          child: AnimatedContainer(
            duration: const Duration(milliseconds: 200),
            curve: Curves.easeInOut,
            constraints: const BoxConstraints(
              maxWidth: double.infinity,
            ),
            child: ValueListenableBuilder<int>(
                valueListenable: sizeFill,
                builder: (BuildContext context, int sizeFill, Widget? child) {
                  return Column(
                    mainAxisSize: MainAxisSize.max,
                    children: [
                      Row(
                        children: [
                          Expanded(
                            flex: sizeFill,
                            child: Column(
                              crossAxisAlignment: CrossAxisAlignment.start,
                              children: [
                                ValueListenableBuilder<double>(
                                    valueListenable: sizeFont,
                                    builder: (BuildContext context, double size,
                                        Widget? child) {
                                      return Text(
                                        car.getTitle(),
                                        style: TextStyle(
                                          color: Colors.black,
                                          fontSize: size,
                                        ),
                                      );
                                    }),
                                ValueListenableBuilder<bool>(
                                  valueListenable: expanded,
                                  builder: (BuildContext context,
                                      bool isExpanded, Widget? child) {
                                    if (isExpanded) {
                                      return Column(
                                        children: [
                                          for (var pair in car.getDetails())
                                            Row(
                                              crossAxisAlignment:
                                                  CrossAxisAlignment.start,
                                              children: [
                                                Expanded(
                                                  flex: 3,
                                                  child: Text(pair.keys.first,
                                                      style: const TextStyle(
                                                        color: Colors.black,
                                                        fontSize: 18,
                                                      )),
                                                ),
                                                Expanded(
                                                  flex: 5,
                                                  child: Text(pair.values.first,
                                                      style: const TextStyle(
                                                        color: Colors.black,
                                                        fontWeight:
                                                            FontWeight.w400,
                                                        fontSize: 18,
                                                      )),
                                                ),
                                              ],
                                            ),
                                        ],
                                      );
                                    } else {
                                      return const SizedBox.shrink();
                                    }
                                  },
                                ),
                              ],
                            ),
                          ),
                          Expanded(
                            flex: 10 - sizeFill,
                            child: ValueListenableBuilder<Pair<double, double>>(
                              valueListenable: sizeImage,
                              builder: (BuildContext context,
                                  Pair<double, double> imageSize,
                                  Widget? child) {
                                return SizedBox(
                                    width: imageSize.first,
                                    height: imageSize.second,
                                    child: ClipRRect(
                                      borderRadius: BorderRadius.circular(16.0),
                                      child: car.image.isNotEmpty
                                          ? Image.file(
                                              File(car.image),
                                              fit: BoxFit.cover,
                                            )
                                          : Image.asset(
                                              'assets/img.png',
                                              fit: BoxFit.cover,
                                            ),
                                    ));
                              },
                            ),
                          ),
                        ],
                      ),
                      ValueListenableBuilder<bool>(
                        valueListenable: expanded,
                        builder: (BuildContext context, bool isExpanded,
                            Widget? child) {
                          if (isExpanded) {
                            return Row(
                              children: [
                                Expanded(
                                  flex: 5,
                                  child: ElevatedButton(
                                    onPressed: () {
                                      Navigator.pushNamed(context, "/edit",
                                          arguments: car.id);
                                    },
                                    style: ElevatedButton.styleFrom(
                                      backgroundColor: Colors.white,
                                      shape: RoundedRectangleBorder(
                                          borderRadius:
                                              BorderRadius.circular(sizeRound)),
                                      padding: const EdgeInsets.symmetric(
                                        vertical: 10,
                                        horizontal: 25,
                                      ),
                                      maximumSize: const Size(
                                          double.infinity, double.infinity),
                                      shadowColor:
                                          Colors.black.withOpacity(0.4),
                                      elevation: 4,
                                    ),
                                    child: const Text('Edit',
                                        style: TextStyle(
                                          color: Colors.black,
                                          fontSize: 18,
                                        )),
                                  ),
                                ),
                                const SizedBox(width: 8),
                                Expanded(
                                  flex: 5,
                                  child: ElevatedButton(
                                    onPressed: () async {
                                      bool confirm = await showDialog(
                                        context: context,
                                        builder: (context) {
                                          return DeleteConfirmationDialog(
                                            message:
                                                'Are you sure you want to delete this car?\n${car.getTitle()}',
                                          );
                                        },
                                      );
                                      if (confirm) {
                                        cars.deleteCar(car.id!);
                                      }
                                    },
                                    style: ElevatedButton.styleFrom(
                                      backgroundColor: Colors.white,
                                      shape: RoundedRectangleBorder(
                                          borderRadius:
                                              BorderRadius.circular(sizeRound)),
                                      padding: const EdgeInsets.symmetric(
                                        vertical: 10,
                                        horizontal: 25,
                                      ),
                                      maximumSize: const Size(
                                          double.infinity, double.infinity),
                                      shadowColor:
                                          Colors.black.withOpacity(0.4),
                                      elevation: 4,
                                    ),
                                    child: const Text('Delete',
                                        style: TextStyle(
                                          color: Colors.black,
                                          fontSize: 18,
                                        )),
                                  ),
                                ),
                              ],
                            );
                          } else {
                            return const SizedBox.shrink();
                          }
                        },
                      ),
                    ],
                  );
                }),
          ),
        );
      });
}

class DeleteConfirmationDialog extends StatelessWidget {
  final String message;

  const DeleteConfirmationDialog({Key? key, required this.message})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      title: const Text('Delete Confirmation'),
      content: Text(message),
      actions: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            Expanded(
              flex: 5,
              child: ElevatedButton(
                onPressed: () {
                  Navigator.of(context).pop(false);
                },
                child: const Text('No'),
              ),
            ),
            Expanded(
              flex: 5,
              child: ElevatedButton(
                onPressed: () {
                  Navigator.of(context).pop(true);
                },
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.red,
                ),
                child: const Text('Yes'),
              ),
            ),
          ],
        )
      ],
    );
  }
}
