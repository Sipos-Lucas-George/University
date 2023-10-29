package com.example.dreamcar.ui.CarCreate

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
import androidx.compose.material.Text
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.OutlinedTextField
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
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
import com.example.dreamcar.DreamCarApp
import com.example.dreamcar.R
import com.example.dreamcar.ui.GenericAppBar
import com.example.dreamcar.ui.theme.DreamCarTheme
import com.sd.lib.compose.wheel_picker.FHorizontalWheelPicker
import com.sd.lib.compose.wheel_picker.FVerticalWheelPicker
import com.sd.lib.compose.wheel_picker.FWheelPickerFocusHorizontal
import com.sd.lib.compose.wheel_picker.FWheelPickerFocusVertical
import com.sd.lib.compose.wheel_picker.rememberFWheelPickerState

@SuppressLint("UnusedMaterialScaffoldPaddingParameter")
@Composable
fun CarCreatePage(
    navController: NavController,
    viewModel: CarsViewModel,
    modifier: Modifier
) {
    val currentModel = remember { mutableStateOf("") }
    val currentCC = remember { mutableStateOf("") }
    val currentHP = remember { mutableStateOf("") }
    val currentImage = remember { mutableStateOf("") }

    val yearIndex = rememberFWheelPickerState(0)
    val fuelTypeIndex = rememberFWheelPickerState(0)
    val transTypeIndex = rememberFWheelPickerState(0)

    val focusRequester = remember { FocusRequester() }

    val currentYear = 2023 - yearIndex.currentIndex
    val fuelTypeList = listOf("Any", "Gasoline", "Diesel", "Bio diesel", "Electric")
    val transTypeList = listOf("Any", "Automatic", "Manual", "CVT")
    val currentFuelType =
        if (0 <= fuelTypeIndex.currentIndex) fuelTypeList[fuelTypeIndex.currentIndex] else "Any"
    val currentTransType =
        if (0 <= transTypeIndex.currentIndex) transTypeList[transTypeIndex.currentIndex] else "Any"

    val focusManager = LocalFocusManager.current

    val getImageRequest = rememberLauncherForActivityResult(
        contract = ActivityResultContracts.OpenDocument(),
        onResult = { uri ->
            if (uri != null) {
                DreamCarApp.getUriPermission(uri)
            }
            currentImage.value = uri?.toString() ?: ""
        }
    )

    DreamCarTheme {
        Scaffold(
            topBar = {
                GenericAppBar(
                    title = stringResource(id = R.string.create_car),
                    onLeftIconClick = { navController.popBackStack() },
                    leftIcon = {
                        Icon(
                            imageVector = ImageVector.vectorResource(id = R.drawable.baseline_arrow_back_24),
                            contentDescription = stringResource(R.string.back),
                            tint = Color.Black
                        )
                    },
                    onRightIconClick = {
                        viewModel.createCar(
                            currentModel.value.ifEmpty { "Unknown" }, currentYear, currentFuelType,
                            if (currentCC.value.isEmpty()) null else currentCC.value.toFloat(),
                            if (currentHP.value.isEmpty()) null else currentHP.value.toInt(),
                            currentTransType,
                            if (currentImage.value == "null") null else currentImage.value
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
                    rightIconState = remember { mutableStateOf(true) }
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
                        viewModel.createCar(
                            currentModel.value.ifEmpty { "Unknown" }, currentYear, currentFuelType,
                            if (currentCC.value.isEmpty()) null else currentCC.value.toFloat(),
                            if (currentHP.value.isEmpty()) null else currentHP.value.toInt(),
                            currentTransType,
                            if (currentImage.value == "null") null else currentImage.value
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