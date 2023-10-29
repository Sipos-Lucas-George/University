package com.example.dreamcar.database

import androidx.lifecycle.LiveData
import androidx.room.*
import com.example.dreamcar.model.Car

@Dao
interface CarsDao {
    @Query("select * from cars where cars.id=:id")
    suspend fun getCarByID(id: Int): Car?

    @Query("select * from cars")
    fun getCars(): LiveData<List<Car>>

    @Delete
    fun deleteCar(car: Car)

    @Update
    fun updateCar(car: Car)

    @Insert
    fun insertCar(car: Car)
}