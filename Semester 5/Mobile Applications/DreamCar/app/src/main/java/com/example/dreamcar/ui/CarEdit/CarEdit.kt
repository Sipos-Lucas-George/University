package com.example.dreamcar.ui.CarEdit

import android.annotation.SuppressLint
import android.net.Uri
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.Image
import androidx.compose.foundation.clickable
import androidx.compose.foundation.interaction.MutableInteractionSource
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxHeight
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.foundation.text.KeyboardOptions
import androidx.compose.material.Icon
import androidx.compose.material.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.OutlinedTextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.rememberCoroutineScope
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.shadow
import androidx.compose.ui.focus.FocusRequester
import androidx.compose.ui.focus.focusRequester
import androidx.compose.ui.focus.onFocusChanged
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.input.key.Key
import androidx.compose.ui.input.key.key
import androidx.compose.ui.input.key.onKeyEvent
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.platform.LocalFocusManager
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.res.vectorResource
import androidx.compose.ui.text.font.FontFamily
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.input.KeyboardType
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import coil.compose.rememberAsyncImagePainter
import coil.request.ImageRequest
import com.example.dreamcar.CarsViewModel
import com.example.dreamcar.Constants
import com.example.dreamcar.DreamCarApp
import com.example.dreamcar.R
import com.example.dreamcar.model.Car
import com.example.dreamcar.ui.GenericAppBar
import com.example.dreamcar.ui.theme.DreamCarTheme
import com.sd.lib.compose.wheel_picker.FHorizontalWheelPicker
import com.sd.lib.compose.wheel_picker.FVerticalWheelPicker
import com.sd.lib.compose.wheel_picker.FWheelPickerFocusHorizontal
import com.sd.lib.compose.wheel_picker.FWheelPickerFocusVertical
import com.sd.lib.compose.wheel_picker.rememberFWheelPickerState
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.android.awaitFrame
import kotlinx.coroutines.launch
import okhttp3.internal.wait
import kotlin.math.absoluteValue

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun CarEditPage(
    carID: Int,
    navController: NavController,
    viewModel: CarsViewModel,
    modifier: Modifier
) {
    val scope = rememberCoroutineScope()
    val car = remember { mutableStateOf(Constants.carDetailPlaceHolder) }

    val currentModel = remember { mutableStateOf("") }
    val currentYear = remember { mutableIntStateOf(2023) }
    val currentFuelType = remember { mutableStateOf("Any") }
    val currentCC = remember { mutableStateOf("") }
    val currentHP = remember { mutableStateOf("") }
    val currentTransType = remember { mutableStateOf("Any") }
    val currentImage = remember { mutableStateOf("") }
    val saveButtonState = remember { mutableStateOf(false) }

    val fuelTypeList = listOf("Any", "Gasoline", "Diesel", "Bio diesel", "Electric")
    val transTypeList = listOf("Any", "Automatic", "Manual", "CVT")

    val focusRequester = remember { FocusRequester() }
    val focusManager = LocalFocusManager.current

    val getImageRequest = rememberLauncherForActivityResult(
        contract = ActivityResultContracts.OpenDocument(),
        onResult = { uri ->
            if (uri != null) {
                DreamCarApp.getUriPermission(uri)
            }
            currentImage.value = uri.toString()
            currentImage.value = uri?.toString() ?: ""
        }
    )

    val yearIndex = rememberFWheelPickerState(0)
    val fuelTypeIndex = rememberFWheelPickerState(0)
    val transTypeIndex = rememberFWheelPickerState(0)

    LaunchedEffect(key1 = true) {
        scope.launch(Dispatchers.IO) {
            car.value = viewModel.getCar(carID) ?: Constants.carDetailPlaceHolder
            currentModel.value = if (car.value.model == "Unknown") "" else car.value.model
            currentYear.intValue = car.value.year
            currentFuelType.value = car.value.fuelType
            currentTransType.value = car.value.transmissionType
            currentCC.value = if (car.value.cc == null) "" else car.value.cc.toString()
            currentHP.value = if (car.value.hp == null) "" else car.value.hp.toString()
            currentImage.value = if (car.value.image == null) "" else car.value.image!!
        }
        awaitFrame()
        yearIndex.scrollToIndex(2023 - car.value.year)
        fuelTypeIndex.scrollToIndex(fuelTypeList.indexOf(car.value.fuelType))
        transTypeIndex.scrollToIndex(transTypeList.indexOf(car.value.transmissionType))
    }

    currentYear.intValue = 2023 - yearIndex.currentIndex
    currentFuelType.value =
        if (0 <= fuelTypeIndex.currentIndex) fuelTypeList[fuelTypeIndex.currentIndex] else "Any"
    currentTransType.value =
        if (0 <= transTypeIndex.currentIndex) transTypeList[transTypeIndex.currentIndex] else "Any"

    fun getSaveButtonState(): Boolean {
        if ((car.value.model == "Unknown" && currentModel.value != "") ||
            (car.value.model != "Unknown" && currentModel.value != car.value.model)
        ) {
            return true
        }
        if (car.value.fuelType != currentFuelType.value ||
            car.value.year != currentYear.intValue || car.value.transmissionType != currentTransType.value
        )
            return true
        if (currentCC.value.isEmpty() && car.value.cc != null) {
            return true
        } else if (currentCC.value.isNotEmpty() && currentCC.value.matches(Regex("0[.][1-9]|[1-9][.][0-9]"))
            && currentCC.value.toFloat() != car.value.cc
        ) {
            return true
        }
        if (currentHP.value.isEmpty() && car.value.hp != null) {
            return true
        } else if (currentHP.value.isNotEmpty() && currentHP.value.matches(Regex("[0-9]|[1-9][0-9]*"))
            && currentHP.value.toInt() != car.value.hp
        ) {
            return true
        }
        if (currentImage.value.isEmpty() && car.value.image != null && car.value.image != "") {
            return true
        } else if (currentImage.value.isNotEmpty() && currentImage.value != car.value.image) {
            return true
        }
        return false
    }

    saveButtonState.value = getSaveButtonState()

    DreamCarTheme {
        Scaffold(
            topBar = {
                GenericAppBar(
                    title = stringResource(id = R.string.edit_car),
                    onLeftIconClick = { navController.popBackStack() },
                    leftIcon = {
                        Icon(
                            imageVector = ImageVector.vectorResource(id = R.drawable.baseline_arrow_back_24),
                            contentDescription = stringResource(R.string.back),
                            tint = Color.Black
                        )
                    },
                    onRightIconClick = {
                        viewModel.updateCar(
                            Car(
                                id = car.value.id,
                                model = currentModel.value.ifEmpty { "Unknown" },
                                year = currentYear.intValue,
                                fuelType = currentFuelType.value,
                                cc = if (currentCC.value.isEmpty()) null else currentCC.value.toFloat(),
                                hp = if (currentHP.value.isEmpty()) null else currentHP.value.toInt(),
                                transmissionType = currentTransType.value,
                                image = if (currentImage.value == "null") null else currentImage.value
                            )
                        )
                        navController.popBackStack()
                    },
                    rightIcon = {
                        Icon(
                            imageVector = ImageVector.vectorResource(id = R.drawable.baseline_save_24),
                            contentDescription = stringResource(R.string.save_car),
                            tint = Color.Black
                        )
                    },
                    leftIconState = true,
                    rightIconState = saveButtonState
                )
            },
        ) {
            Column(
                horizontalAlignment = Alignment.CenterHorizontally,
                verticalArrangement = Arrangement.Center,
                modifier = modifier
                    .fillMaxSize()
                    .clickable(
                        indication = null,
                        interactionSource = remember { MutableInteractionSource() }) { focusManager.clearFocus() }
            ) {
                Row(modifier = Modifier.fillMaxWidth(0.9f)) {
                    OutlinedTextField(
                        value = currentModel.value,
                        onValueChange = {
                            currentModel.value = it
                        },
                        label = { Text("Model") },
                        singleLine = true,
                        modifier = Modifier
                            .align(Alignment.CenterVertically)
                            .fillMaxWidth(0.85f)
                            .padding(end = 4.dp)
                            .focusRequester(focusRequester)
                            .onKeyEvent {
                                if (it.key == Key.Enter) {
                                    focusManager.clearFocus()
                                }
                                false
                            },
                    )
                    FVerticalWheelPicker(
                        count = 123,
                        focus = {
                            FWheelPickerFocusVertical(dividerColor = Color.Gray, dividerSize = 2.dp)
                        },
                        modifier = Modifier
                            .width(50.dp)
                            .align(Alignment.CenterVertically),
                        state = yearIndex
                    ) {
                        Text(text = (2023 - it).toString())
                    }
                }
                Spacer(modifier = Modifier.padding(bottom = 8.dp))
                OutlinedTextField(
                    value = currentCC.value,
                    onValueChange = { currentCC.value = it },
                    label = { Text("CC") },
                    singleLine = true,
                    modifier = Modifier
                        .fillMaxWidth(0.9f)
                        .onFocusChanged {
                            if (!it.isFocused and !currentCC.value.matches(Regex("0[.][1-9]|[1-9][.][0-9]")))
                                currentCC.value = ""
                        }
                        .focusRequester(focusRequester)
                        .onKeyEvent {
                            if (it.key == Key.Enter) {
                                focusManager.clearFocus()
                            }
                            false
                        },
                    keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number)
                )
                Spacer(modifier = Modifier.padding(bottom = 8.dp))
                OutlinedTextField(
                    value = currentHP.value,
                    onValueChange = { currentHP.value = it },
                    label = { Text("HP") },
                    singleLine = true,
                    modifier = Modifier
                        .fillMaxWidth(0.9f)
                        .onFocusChanged {
                            if (!it.isFocused and !currentHP.value.matches(Regex("[0-9]|[1-9][0-9]*")))
                                currentHP.value = ""
                        }
                        .focusRequester(focusRequester)
                        .onKeyEvent {
                            if (it.key == Key.Enter) {
                                focusManager.clearFocus()
                            }
                            false
                        },
                    keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Number)
                )
                Spacer(modifier = Modifier.padding(bottom = 8.dp))
                FHorizontalWheelPicker(
                    count = 5,
                    itemWidth = 100.dp,
                    focus = {
                        FWheelPickerFocusHorizontal(dividerColor = Color.Gray, dividerSize = 2.dp)
                    },
                    modifier = Modifier.height(30.dp),
                    state = fuelTypeIndex
                ) {
                    Text(text = fuelTypeList[it])
                }
                Spacer(modifier = Modifier.padding(bottom = 20.dp))
                FHorizontalWheelPicker(
                    count = 4,
                    itemWidth = 100.dp,
                    focus = {
                        FWheelPickerFocusHorizontal(dividerColor = Color.Gray, dividerSize = 2.dp)
                    },
                    modifier = Modifier.height(30.dp),
                    state = transTypeIndex
                ) {
                    Text(text = transTypeList[it])
                }
                Spacer(modifier = Modifier.padding(bottom = 20.dp))
                Button(
                    onClick = {
                        getImageRequest.launch(arrayOf("image/*"))
                    },
                    colors = ButtonDefaults.buttonColors(containerColor = Color.White),
                    modifier = Modifier
                        .padding(vertical = 4.dp, horizontal = 8.dp)
                        .fillMaxWidth(0.4f)
                        .shadow(4.dp, RoundedCornerShape(50.dp)),
                    shape = RoundedCornerShape(50.dp)
                ) {
                    Text(
                        text = "Upload image",
                        color = Color.Black,
                        fontWeight = FontWeight(500),
                        fontFamily = FontFamily.Serif
                    )
                }
                Spacer(modifier = Modifier.padding(bottom = 8.dp))
                if (currentImage.value.isNotEmpty()) {
                    Image(
                        painter = rememberAsyncImagePainter(
                            ImageRequest
                                .Builder(LocalContext.current)
                                .data(data = Uri.parse(currentImage.value))
                                .build()
                        ),
                        contentDescription = null,
                        modifier = Modifier
                            .fillMaxHeight(0.8f)
                            .padding(6.dp),
                        contentScale = ContentScale.Crop
                    )
                } else {
                    Image(
                        painter = painterResource(id = R.drawable.img),
                        contentDescription = "Car Image",
                        modifier = Modifier.fillMaxSize(0.8f)
                    )
                }
                Button(
                    onClick = {
                        viewModel.updateCar(
                            Car(
                                id = car.value.id,
                                model = currentModel.value.ifEmpty { "Unknown" },
                                year = currentYear.intValue,
                                fuelType = currentFuelType.value,
                                cc = if (currentCC.value.isEmpty()) null else currentCC.value.toFloat(),
                                hp = if (currentHP.value.isEmpty()) null else currentHP.value.toInt(),
                                transmissionType = currentTransType.value,
                                image = if (currentImage.value == "null") null else currentImage.value
                            )
                        )
                        navController.popBackStack()
                    },
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
}