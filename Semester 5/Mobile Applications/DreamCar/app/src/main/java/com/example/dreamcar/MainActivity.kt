package com.example.dreamcar

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.ui.Modifier
import androidx.compose.ui.geometry.Offset
import androidx.compose.ui.graphics.Brush
import androidx.compose.ui.graphics.Color
import androidx.navigation.NavType
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import androidx.navigation.navArgument
import com.example.dreamcar.ui.CarCreate.CarCreatePage
import com.example.dreamcar.ui.CarEdit.CarEditPage
import com.example.dreamcar.ui.CarList.CarListPage

class MainActivity : ComponentActivity() {

    private lateinit var viewModel: CarsViewModel

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val modifier = Modifier.background(
            brush = Brush.linearGradient(
                0.1f to Color.White,
                1.0f to Color(0xFF9DBDFC),
                start = Offset(0f, Float.POSITIVE_INFINITY),
                end = Offset(Float.POSITIVE_INFINITY, 0f)
            )
        )
        viewModel = CarsViewModelFactory(DreamCarApp.getDao()).create(CarsViewModel::class.java)
        setContent {
            val navController = rememberNavController()
            NavHost(
                navController = navController,
                startDestination = Constants.NAVIGATION_CAR_LIST
            ) {
                composable(Constants.NAVIGATION_CAR_LIST) {
                    CarListPage(
                        navController = navController, viewModel = viewModel, modifier = modifier
                    )
                }
                composable(
                    Constants.NAVIGATION_CAR_EDIT,
                    arguments = listOf(navArgument(Constants.NAVIGATION_CAR_ID_ARG) {
                        type = NavType.IntType
                    })
                ) { navBackStackEntry ->
                    navBackStackEntry.arguments?.getInt(Constants.NAVIGATION_CAR_ID_ARG)?.let {
                        CarEditPage(
                            carID = it, navController = navController, viewModel = viewModel,
                            modifier = modifier
                        )
                    }
                }
                composable(Constants.NAVIGATION_CAR_CREATE) {
                    CarCreatePage(
                        navController = navController, viewModel = viewModel, modifier = modifier
                    )
                }
            }
        }
    }
}