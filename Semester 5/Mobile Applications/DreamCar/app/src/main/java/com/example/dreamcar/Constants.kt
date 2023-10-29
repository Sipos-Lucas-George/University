package com.example.dreamcar

import com.example.dreamcar.model.Car

object Constants {
    const val TABLE_NAME = "cars"
    const val DATABASE_NAME = "carsDatabase"
    const val NAVIGATION_CAR_LIST = "carList"
    const val NAVIGATION_CAR_CREATE = "carCreate"
    const val NAVIGATION_CAR_EDIT = "carEdit/{carID}"
    const val NAVIGATION_CAR_ID_ARG = "carID"

    fun carEditNavigation(carID: Int) = "carEdit/$carID"

    val carDetailPlaceHolder = Car(
        id = 0, model = "Cannot find car details", year = 0, fuelType = "Cannot find car details",
        transmissionType = "Cannot find car details"
    )

    fun List<Car>?.orPlaceHolderList(): List<Car> {
        return if (!this.isNullOrEmpty()) this else listOf(carDetailPlaceHolder)
    }
}