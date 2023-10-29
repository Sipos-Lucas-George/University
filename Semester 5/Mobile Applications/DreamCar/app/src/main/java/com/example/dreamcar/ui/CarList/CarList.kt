package com.example.dreamcar.ui.CarList

import android.annotation.SuppressLint
import android.net.Uri
import android.widget.Toast
import androidx.compose.animation.animateContentSize
import androidx.compose.animation.core.Spring
import androidx.compose.animation.core.spring
import androidx.compose.foundation.ExperimentalFoundationApi
import androidx.compose.foundation.Image
import androidx.compose.foundation.combinedClickable
import androidx.compose.foundation.interaction.MutableInteractionSource
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.shape.AbsoluteRoundedCornerShape
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material.AlertDialog
import androidx.compose.material.Icon
import androidx.compose.material.Scaffold
import androidx.compose.material.Text
import androidx.compose.material.ripple.rememberRipple
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.clip
import androidx.compose.ui.draw.shadow
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.res.vectorResource
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import coil.compose.rememberAsyncImagePainter
import coil.request.ImageRequest
import com.example.dreamcar.CarsViewModel
import com.example.dreamcar.Constants
import com.example.dreamcar.Constants.carDetailPlaceHolder
import com.example.dreamcar.Constants.orPlaceHolderList
import com.example.dreamcar.R
import com.example.dreamcar.model.Car
import com.example.dreamcar.ui.GenericAppBar
import com.example.dreamcar.ui.theme.DreamCarTheme

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun CarListPage(
    navController: NavController,
    viewModel: CarsViewModel,
    modifier: Modifier
) {
    val deleteText = remember { mutableStateOf("") }
    val openDialog = remember { mutableStateOf(false) }
    val carToDelete = remember { mutableStateOf(carDetailPlaceHolder) }
    val cars = viewModel.cars.observeAsState()

    DreamCarTheme {
        Scaffold(
            topBar = {
                GenericAppBar(
                    title = stringResource(id = R.string.app_name),
                    onLeftIconClick = { },
                    leftIcon = { },
                    onRightIconClick = { },
                    rightIcon = { },
                    leftIconState = false,
                    rightIconState = remember {
                        mutableStateOf(false)
                    }
                )
            },
        )
        {
            CarsList(
                cars = cars.value.orPlaceHolderList(),
                openDialog = openDialog,
                deleteText = deleteText,
                navController = navController,
                carToDelete = carToDelete,
                modifier = modifier
            )
            DeleteDialog(
                openDialog = openDialog,
                text = deleteText,
                action = {
                    viewModel.deleteCar(carToDelete.value)
                },
                carToDelete = carToDelete,
                navController
            )
        }
    }
}

@Composable
fun CarsList(
    cars: List<Car>,
    openDialog: MutableState<Boolean>,
    deleteText: MutableState<String>,
    navController: NavController,
    carToDelete: MutableState<Car>,
    modifier: Modifier
) {

    Box(modifier = modifier.fillMaxSize()) {
        LazyColumn {
            item {
                Spacer(modifier = Modifier.padding(bottom = 4.dp))
            }
            items(items = cars) { car ->
                CarListItem(car = car, openDialog, deleteText, navController, carToDelete)
            }
            item {
                Spacer(modifier = Modifier.padding(bottom = 72.dp))
            }
        }
        Column(
            modifier = Modifier
                .fillMaxWidth()
                .align(Alignment.BottomCenter),
        ) {
            Button(
                onClick = { navController.navigate(Constants.NAVIGATION_CAR_CREATE) },
                colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                modifier = Modifier
                    .padding(start = 8.dp, end = 8.dp, top = 10.dp, bottom = 8.dp)
                    .fillMaxWidth()
                    .shadow(4.dp, RoundedCornerShape(50.dp)),
                shape = RoundedCornerShape(50.dp),
                content = {
                    Icon(
                        imageVector = ImageVector.vectorResource(id = R.drawable.add_button),
                        contentDescription = stringResource(R.string.create_car)
                    )
                }
            )
        }
    }
}

@OptIn(ExperimentalFoundationApi::class)
@Composable
fun CarListItem(
    car: Car,
    openDialog: MutableState<Boolean>,
    deleteText: MutableState<String>,
    navController: NavController,
    carToDelete: MutableState<Car>
) {
    if (car.id == 0)
        return
    var expanded by remember { mutableStateOf(false) }
    val sizeImage = if (expanded) Pair(180.dp, 98.1f.dp) else Pair(99.dp, 54.dp)
    val sizeFont = if (expanded) 18.sp else 22.sp
    val sizeFill = if (expanded) 0.55f else 0.7f
    val sizeRound = if (expanded) 30.dp else 50.dp

    Button(
        onClick = { expanded = !expanded },
        colors = ButtonDefaults.buttonColors(containerColor = /*Color(0xFFD2E0FB)*/ Color.White),
        modifier = Modifier
            .padding(vertical = 4.dp, horizontal = 8.dp)
            .fillMaxSize(1f)
            .shadow(4.dp, RoundedCornerShape(sizeRound))
            .combinedClickable(interactionSource = remember {
                MutableInteractionSource()
            },
                indication = rememberRipple(bounded = false),
                onClick = { expanded = !expanded },
                onLongClick = {
                    openDialog.value = true
                    deleteText.value = "Are you sure you want to delete this car?\n${car.model}"
                    carToDelete.value = car
                }
            ),
        shape = RoundedCornerShape(sizeRound)
    ) {
        Row(
            modifier = Modifier
                .animateContentSize(
                    animationSpec = spring(
                        dampingRatio = Spring.DampingRatioLowBouncy,
                        stiffness = Spring.StiffnessLow
                    )
                )
                .fillMaxSize(1f)
        ) {
            Column(modifier = Modifier) {
                Row(verticalAlignment = Alignment.CenterVertically) {
                    Column(
                        modifier = Modifier
                            .fillMaxSize(sizeFill)
                    ) {
                        Text(
                            text = car.getTitle(),
                            color = Color.Black,
                            fontSize = sizeFont,
                            fontWeight = FontWeight(600),
                            fontFamily = FontFamily.Serif,
                            lineHeight = (sizeFont.value + 4).sp,
                        )
                        if (expanded) {
                            Spacer(modifier = Modifier.padding(top = 2.dp))
                            for (pair in car.getDetails()) {
                                Row {
                                    Text(
                                        text = pair.first,
                                        color = Color.Black,
                                        fontSize = sizeFont,
                                        fontWeight = FontWeight(400),
                                        fontFamily = FontFamily.Serif,
                                        modifier = Modifier.fillMaxSize(0.3f)
                                    )
                                    Text(
                                        text = pair.second,
                                        color = Color.Black,
                                        fontSize = sizeFont,
                                        fontWeight = FontWeight(400),
                                        fontFamily = FontFamily.Serif,
                                        modifier = Modifier.fillMaxSize(1f)
                                    )
                                }
                            }
                        }
                    }
                    Box(
                        modifier = Modifier
                            .size(sizeImage.first, sizeImage.second)
                            .clip(shape = AbsoluteRoundedCornerShape(10.dp))
                    ) {
                        if (!car.image.isNullOrEmpty()) {
                            Image(
                                painter = rememberAsyncImagePainter(
                                    model =
                                    ImageRequest
                                        .Builder(LocalContext.current)
                                        .data(Uri.parse(car.image))
                                        .build()
                                ),
                                contentDescription = "Car Image",
                                modifier = Modifier.fillMaxSize(1f),
                                contentScale = ContentScale.Crop
                            )
                        } else {
                            Image(
                                painter = painterResource(id = R.drawable.img),
                                contentDescription = "Car Image",
                                modifier = Modifier.fillMaxSize(1f)
                            )
                        }
                    }
                }
                if (expanded)
                    Row {
                        Button(
                            onClick = {
                                navController.navigate(
                                    Constants.carEditNavigation(car.id!!)
                                )
                            },
                            colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                            modifier = Modifier
                                .padding(vertical = 4.dp, horizontal = 8.dp)
                                .fillMaxSize(0.47f)
                                .shadow(4.dp, RoundedCornerShape(30.dp)),
                            shape = RoundedCornerShape(30.dp)
                        ) {
                            Text(text = "Edit", color = Color.Black)
                        }
                        Button(
                            onClick = {
                                openDialog.value = true
                                deleteText.value = "Are you sure you want to delete this car?"
                                carToDelete.value = car
                            },
                            colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                            modifier = Modifier
                                .padding(vertical = 4.dp, horizontal = 8.dp)
                                .fillMaxWidth()
                                .shadow(4.dp, RoundedCornerShape(30.dp)),
                            shape = RoundedCornerShape(30.dp)
                        ) {
                            Text(text = "Delete", color = Color.Black)
                        }
                    }
            }
        }
    }
}

@Composable
fun DeleteDialog(
    openDialog: MutableState<Boolean>,
    text: MutableState<String>,
    action: () -> Unit,
    carToDelete: MutableState<Car>,
    navController: NavController
) {
    if (openDialog.value) {
        AlertDialog(
            modifier = Modifier.shadow(10.dp),
            onDismissRequest = { openDialog.value = false },
            title = { Text(text = "Delete ${carToDelete.value.getTitle()}") },
            text = {
                Column {
                    Text(text = text.value)
                }
            },
            buttons = {
                Row(
                    Modifier
                        .padding(8.dp)
                        .fillMaxWidth(),
                    horizontalArrangement = Arrangement.Center
                ) {
                    Button(
                        modifier = Modifier
                            .fillMaxWidth(0.48f)
                            .shadow(2.dp, RoundedCornerShape(30.dp)),
                        colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                        onClick = {
                            action.invoke()
                            openDialog.value = false
                            Toast.makeText(
                                navController.context,
                                "${carToDelete.value.getTitle()} deleted",
                                Toast.LENGTH_SHORT
                            ).show()
                            carToDelete.value = carDetailPlaceHolder
                        }
                    ) {
                        Text(text = "Yes")
                    }
                    Spacer(modifier = Modifier.fillMaxWidth(0.07f))
                    Button(
                        modifier = Modifier
                            .fillMaxWidth()
                            .shadow(2.dp, RoundedCornerShape(30.dp)),
                        colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                        onClick = {
                            openDialog.value = false
                            carToDelete.value = carDetailPlaceHolder
                        }
                    ) {
                        Text(text = "No")
                    }
                }
            }
        )
    }
}