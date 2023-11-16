import 'package:dream_car_non_native/pages/edit.dart';
import 'package:flutter/material.dart';
import 'package:dream_car_non_native/pages/car.dart';
import 'package:dream_car_non_native/pages/home.dart';
import 'package:dream_car_non_native/pages/create.dart';
import 'package:provider/provider.dart';

void main() => runApp(
      ChangeNotifierProvider(
        create: (context) => CarRepositoryProvider(),
        child: MaterialApp(
          initialRoute: "/",
          routes: {
            "/": (context) => const Home(),
            "/create": (context) => const CarCreatePage(),
            "/edit": (context) => const CarEditPage()
          },
        ),
      ),
    );
