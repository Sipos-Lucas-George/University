import 'dart:io';

import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:image_picker/image_picker.dart';
import 'package:provider/provider.dart';

import 'car.dart';

class CarEditPage extends StatefulWidget {
  const CarEditPage({super.key});

  int getID(BuildContext context) {
    final id = ModalRoute.of(context)!.settings.arguments as int;
    return id;
  }

  CarRepositoryProvider getCars(BuildContext context) {
    return Provider.of<CarRepositoryProvider>(context);
  }

  @override
  _CarEditPageState createState() => _CarEditPageState();
}

class _CarEditPageState extends State<CarEditPage> {
  bool initialized = false;
  late File _image = File("");
  ImagePicker picker = ImagePicker();

  late int id = widget.getID(context);
  late CarRepositoryProvider cars = widget.getCars(context);
  late TextEditingController _currentModelController;
  late TextEditingController _currentYearController;
  late TextEditingController _currentCCController;
  late TextEditingController _currentHPController;
  late TextEditingController _currentFuelController;
  late TextEditingController _currentTransController;

  late FocusNode _focusNode;
  final List<String> fuelTypes = [
    "Any",
    "Gasoline",
    "Diesel",
    "Bio diesel",
    "Electric"
  ];
  final List<String> transTypes = ["Any", "Automatic", "Manual", "CVT"];

  @override
  void initState() {
    super.initState();
    _currentModelController = TextEditingController();
    _currentYearController = TextEditingController();
    _currentCCController = TextEditingController();
    _currentHPController = TextEditingController();
    _currentFuelController = TextEditingController(text: "Any");
    _currentTransController = TextEditingController(text: "Any");
    _focusNode = FocusNode();
  }

  void initFields() {
    if (initialized) {
      return;
    }
    initialized = true;
    Car car = cars[id];
    _currentModelController.text = car.model;
    _currentYearController.text = (car.year != null) ? car.year.toString() : "";
    _currentCCController.text = (car.cc != null) ? car.cc.toString() : "";
    _currentHPController.text = (car.hp != null) ? car.hp.toString() : "";
    _currentFuelController.text = car.fuelType;
    _currentTransController.text = car.transmissionType;
    _image = File(car.image);
  }

  Future _pickImageFromGallery() async {
    final pickedFile = await picker.pickImage(source: ImageSource.gallery);

    setState(() {
      _image = (pickedFile != null) ? File(pickedFile.path) : File("");
    });
  }

  @override
  Widget build(BuildContext context) {
    initFields();
    return Scaffold(
      appBar: AppBar(
        centerTitle: true,
        title: const Text(
          "Update Car",
          style: TextStyle(
            color: Colors.black,
            fontWeight: FontWeight.w400,
            fontSize: 25,
          ),
        ),
        backgroundColor: Colors.white,
        leading: IconButton(
          icon: const Icon(
            Icons.arrow_back,
            color: Colors.black,
          ),
          onPressed: () {
            Navigator.pop(context);
          },
        ),
        actions: [
          IconButton(
            icon: const Icon(
              Icons.save,
              color: Colors.black,
            ),
            onPressed: () {
              cars.updateCar(id, Car(
                  model: _currentModelController.text.isNotEmpty
                      ? _currentModelController.text
                      : "Unknown",
                  year: _currentYearController.text.isNotEmpty
                      ? int.parse(_currentYearController.text)
                      : null,
                  fuelType: _currentFuelController.text,
                  transmissionType: _currentTransController.text,
                  hp: _currentHPController.text.isNotEmpty
                      ? int.parse(_currentHPController.text)
                      : null,
                  cc: _currentCCController.text.isNotEmpty
                      ? double.parse(_currentCCController.text)
                      : null,
                  image: _image.path));
              Navigator.pop(context);
            },
          ),
        ],
      ),
      body: Column(
        children: [
          Expanded(
            child: SingleChildScrollView(
              child: GestureDetector(
                onTap: () {
                  _focusNode.unfocus();
                },
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: [
                        Expanded(
                          flex: 8,
                          child: Padding(
                            padding: const EdgeInsets.all(4),
                            child: TextField(
                              controller: _currentModelController,
                              decoration:
                                  const InputDecoration(labelText: 'Model'),
                              onSubmitted: (_) {
                                _focusNode.unfocus();
                              },
                              inputFormatters: <TextInputFormatter>[
                                LengthLimitingTextInputFormatter(50),
                              ],
                            ),
                          ),
                        ),
                        Expanded(
                          flex: 2,
                          child: Padding(
                            padding: const EdgeInsets.all(4),
                            child: Focus(
                              child: TextField(
                                controller: _currentYearController,
                                keyboardType: TextInputType.number,
                                decoration:
                                    const InputDecoration(labelText: 'Year'),
                                onSubmitted: (_) {
                                  _focusNode.unfocus();
                                },
                                inputFormatters: <TextInputFormatter>[
                                  LengthLimitingTextInputFormatter(4),
                                  FilteringTextInputFormatter.allow(
                                      RegExp("[0-9]*")),
                                ],
                              ),
                              onFocusChange: (hasFocus) {
                                if (!hasFocus) {
                                  final enteredYear = int.tryParse(
                                          _currentYearController.text) ??
                                      0;
                                  if (enteredYear < 1900 ||
                                      enteredYear > 2023) {
                                    _currentYearController.text = "";
                                  }
                                }
                              },
                            ),
                          ),
                        ),
                      ],
                    ),
                    const SizedBox(height: 8),
                    Focus(
                      child: Padding(
                        padding: const EdgeInsets.all(4),
                        child: TextField(
                          controller: _currentCCController,
                          decoration: const InputDecoration(labelText: 'CC'),
                          keyboardType: TextInputType.number,
                          focusNode: _focusNode,
                          inputFormatters: <TextInputFormatter>[
                            FilteringTextInputFormatter.allow(
                                RegExp("[0-9.]*")),
                          ],
                          onSubmitted: (_) {
                            _focusNode.unfocus();
                          },
                        ),
                      ),
                      onFocusChange: (hasFocus) {
                        if (hasFocus) {
                          return;
                        }
                        if (!RegExp(r"^0[.][1-9]|[1-9][.][0-9]$")
                            .hasMatch(_currentCCController.text)) {
                          _currentCCController.text = "";
                        }
                      },
                    ),
                    const SizedBox(height: 8),
                    Padding(
                      padding: const EdgeInsets.all(4),
                      child: TextField(
                        controller: _currentHPController,
                        decoration: const InputDecoration(labelText: 'HP'),
                        keyboardType: TextInputType.number,
                        onSubmitted: (_) {
                          _focusNode.unfocus();
                        },
                        inputFormatters: <TextInputFormatter>[
                          LengthLimitingTextInputFormatter(7),
                          FilteringTextInputFormatter.allow(
                              RegExp(r"^([0-9]|[1-9][0-9]*)$")),
                        ],
                      ),
                    ),
                    const SizedBox(height: 8),
                    CupertinoPicker(
                      itemExtent: 50,
                      children: fuelTypes
                          .map((fuelType) => Center(child: Text(fuelType)))
                          .toList(),
                      onSelectedItemChanged: (index) {
                        _currentFuelController.text = fuelTypes[index];
                      },
                    ),
                    const SizedBox(height: 20),
                    CupertinoPicker(
                      itemExtent: 50,
                      children: transTypes
                          .map((transType) => Center(child: Text(transType)))
                          .toList(),
                      onSelectedItemChanged: (index) {
                        _currentTransController.text = transTypes[index];
                      },
                    ),
                    const SizedBox(height: 20),
                    ElevatedButton(
                      onPressed: () {
                        _pickImageFromGallery();
                      },
                      style: ElevatedButton.styleFrom(
                        backgroundColor: Colors.white,
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(50),
                        ),
                        padding: const EdgeInsets.symmetric(
                            vertical: 10, horizontal: 25),
                        shadowColor: Colors.black.withOpacity(0.4),
                        elevation: 4,
                      ),
                      child: const Text(
                        "Upload image",
                        style: TextStyle(
                          color: Colors.black,
                          fontWeight: FontWeight.bold,
                          fontSize: 16,
                        ),
                      ),
                    ),
                    const SizedBox(height: 8),
                    if (_image.path != "")
                      Image.file(
                        _image,
                        height: 200,
                      )
                    else
                      Image.asset(
                        'assets/img.png',
                        height: 200,
                      ),
                    const SizedBox(height: 8),
                  ],
                ),
              ),
            ),
          ),
          SizedBox(
            width: double.infinity,
            child: ElevatedButton(
              onPressed: () {
                cars.updateCar(id, Car(
                    model: _currentModelController.text.isNotEmpty
                        ? _currentModelController.text
                        : "Unknown",
                    year: _currentYearController.text.isNotEmpty
                        ? int.parse(_currentYearController.text)
                        : null,
                    fuelType: _currentFuelController.text,
                    transmissionType: _currentTransController.text,
                    hp: _currentHPController.text.isNotEmpty
                        ? int.parse(_currentHPController.text)
                        : null,
                    cc: _currentCCController.text.isNotEmpty
                        ? double.parse(_currentCCController.text)
                        : null,
                    image: _image.path));
                Navigator.pop(context);
              },
              style: ElevatedButton.styleFrom(
                backgroundColor: Colors.white,
                shape: RoundedRectangleBorder(
                  borderRadius: BorderRadius.circular(50),
                ),
                padding: const EdgeInsets.all(10),
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
        ],
      ),
    );
  }

  @override
  void dispose() {
    _currentModelController.dispose();
    _currentCCController.dispose();
    _currentHPController.dispose();
    _currentFuelController.dispose();
    _currentFuelController.dispose();
    _focusNode.dispose();
    super.dispose();
  }
}
