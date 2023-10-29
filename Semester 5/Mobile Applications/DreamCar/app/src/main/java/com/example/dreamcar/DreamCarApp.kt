package com.example.dreamcar

import android.app.Application
import android.content.Intent
import android.net.Uri
import androidx.room.Room
import com.example.dreamcar.database.CarsDatabase
import com.example.dreamcar.database.CarsDao

class DreamCarApp : Application() {
    private var database: CarsDatabase? = null

    init {
        instance = this
    }

    private fun getDatabase(): CarsDatabase {
        if (database != null) {
            return database!!
        } else {
            database = Room.databaseBuilder(
                instance!!.applicationContext,
                CarsDatabase::class.java,
                Constants.DATABASE_NAME
            ).fallbackToDestructiveMigration().build()
        }
        return database!!
    }

    companion object {
        private var instance: DreamCarApp? = null

        fun getDao(): CarsDao {
            return instance!!.getDatabase().CarsDao()
        }

        fun getUriPermission(uri: Uri) {
            instance!!.applicationContext.contentResolver.takePersistableUriPermission(
                uri,
                Intent.FLAG_GRANT_READ_URI_PERMISSION
            )
        }
    }
}