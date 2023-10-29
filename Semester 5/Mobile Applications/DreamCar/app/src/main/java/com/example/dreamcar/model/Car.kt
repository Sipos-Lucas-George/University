package com.example.dreamcar.model

import android.graphics.Bitmap
import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.Index
import androidx.room.PrimaryKey
import com.example.dreamcar.Constants

@Entity(tableName = Constants.TABLE_NAME, indices = [Index(value = ["id"], unique = true)])
data class Car(
    @PrimaryKey(autoGenerate = true) var id: Int? = null,
    @ColumnInfo(name = "model") var model: String,
    @ColumnInfo(name = "year") var year: Int,
    @ColumnInfo(name = "fuelType") var fuelType: String,
    @ColumnInfo(name = "cc") var cc: Float? = null,
    @ColumnInfo(name = "hp") var hp: Int? = null,
    @ColumnInfo(name = "transmissionType") var transmissionType: String,
    @ColumnInfo(name = "image") var image: String? = null
) {
    fun getTitle(): String {
        return "$model $year"
    }

    fun getDetails(): List<Pair<String, String>> {
        return listOfNotNull(
            Pair("Fuel:", fuelType),
            cc?.let { Pair("CC:", "$it") },
            hp?.let { Pair("HP:", "$it") },
            Pair("Trans:", transmissionType),
        )
    }
}