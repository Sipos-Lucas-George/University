package com.example.dreamcar

import androidx.lifecycle.*
import com.example.dreamcar.model.Car
import com.example.dreamcar.database.CarsDao
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class CarsViewModel(
    private val database: CarsDao
) : ViewModel() {
    val cars: LiveData<List<Car>> = database.getCars()

    suspend fun getCar(id: Int): Car? {
        return database.getCarByID(id)
    }

    fun deleteCar(car: Car) {
        viewModelScope.launch(Dispatchers.IO) {
            database.deleteCar(car)
        }
    }

    fun updateCar(car: Car) {
        viewModelScope.launch(Dispatchers.IO) {
            database.updateCar(car)
        }
    }

    fun createCar(
        model: String, year: Int, fuelType: String, cc: Float?, hp: Int?,
        transmissionType: String, image: String?
    ) {
        val car = Car(
            model = model, year = year, fuelType = fuelType, cc = cc, hp = hp,
            transmissionType = transmissionType, image = image
        )
        viewModelScope.launch(Dispatchers.IO) {
            database.insertCar(car)
        }
    }
}

class CarsViewModelFactory(
    private val database: CarsDao
) : ViewModelProvider.NewInstanceFactory() {
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        return CarsViewModel(
            database = database
        ) as T
    }
}