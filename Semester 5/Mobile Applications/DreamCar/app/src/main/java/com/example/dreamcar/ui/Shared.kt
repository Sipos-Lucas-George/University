package com.example.dreamcar.ui

import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material.IconButton
import androidx.compose.material.Text
import androidx.compose.material3.CenterAlignedTopAppBar
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.runtime.Composable
import androidx.compose.runtime.MutableState
import androidx.compose.ui.Modifier
import androidx.compose.ui.draw.shadow
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.style.TextOverflow
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun GenericAppBar(
    title: String,
    onLeftIconClick: (() -> Unit)?,
    leftIcon: @Composable (() -> Unit)?,
    onRightIconClick: (() -> Unit)?,
    rightIcon: @Composable (() -> Unit)?,
    leftIconState: Boolean,
    rightIconState: MutableState<Boolean>
) {
    CenterAlignedTopAppBar(
        title = {
            Text(
                title,
                fontSize = 22.sp,
                maxLines = 1,
                overflow = TextOverflow.Ellipsis
            )
        },
        modifier = Modifier
            .shadow(2.dp)
            .background(Color.White),
        navigationIcon = {
            IconButton(
                onClick = { onLeftIconClick?.invoke() },
                content = {
                    if (leftIconState) {
                        leftIcon?.invoke()
                    }
                })
        },
        actions = {
            IconButton(
                onClick = { onRightIconClick?.invoke() },
                content = {
                    if (rightIconState.value) {
                        rightIcon?.invoke()
                    }
                })
        }
    )
}