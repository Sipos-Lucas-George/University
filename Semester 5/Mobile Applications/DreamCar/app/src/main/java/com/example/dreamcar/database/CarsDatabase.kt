package com.example.dreamcar.database

import androidx.room.Database
import androidx.room.RoomDatabase
import com.example.dreamcar.model.Car

@Database(entities = [Car::class], version = 5, exportSchema = false)
abstract class CarsDatabase : RoomDatabase() {
    abstract fun CarsDao(): CarsDao
}