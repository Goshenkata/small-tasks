package com.example.cards

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.RowScope
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import com.example.cards.ui.theme.CardsTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            CardsTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    Cards();
                }
            }
        }
    }
}

@Composable
fun Card(title: String, content: String, color: Color, modifier: Modifier) {
    Column(
        modifier = modifier
            .fillMaxSize()
            .background(color = color)
            .padding(16.dp),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally,
    ) {
        Text(
            modifier = Modifier.padding(bottom = 16.dp),
            text = title,
            fontWeight = FontWeight.Bold,
        );
        Text(
            text = content,
            textAlign = TextAlign.Justify,
        );
    }
}

@Composable
fun Cards(modifier: Modifier = Modifier) {
    Column(Modifier.fillMaxWidth()) {
        Row(Modifier.weight(1f, true)) {
            Card(
                "Text composable",
                "Displays text and follows the recommended Material Design guidelines.",
                Color(0xFFEADDFF),
                modifier = Modifier.weight(1f, true)
            )
            Card(
                "Image composable",
                "Creates a composable that lays out and draws a given Painter class object.",
                Color(0xFFD0BCFF),
                modifier = Modifier.weight(1f, true)
            )
        }
        Row(Modifier.weight(1f, true)) {
            Card(
                "Row composable",
                "A layout composable that places its children in a horizontal sequence.",
                Color(0xFFB69DF8),
                Modifier.weight(1f, true)
            )
            Card(
                "Column composable",
                "A layout composable that places its children in a vertical sequence.",
                Color(0xFFF6EDFF),
                Modifier.weight(1f, true)
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    CardsTheme {
        Cards()
    }
}