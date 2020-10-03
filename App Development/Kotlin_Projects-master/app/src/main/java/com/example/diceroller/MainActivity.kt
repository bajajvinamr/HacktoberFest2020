package com.example.diceroller

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import kotlin.random.Random.Default

class MainActivity : AppCompatActivity() {

    lateinit var diceImage: ImageView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val rollbutton: Button = findViewById(R.id.roll_button)
        rollbutton.setOnClickListener {
            rollDice()
        }

        diceImage=findViewById(R.id.dice_image)
    }

    private fun rollDice() {


        val randomInt = kotlin.random.Random.nextInt(6) + 1
        val drawableResourse = when (randomInt) {
            1 -> R.drawable.dice_1
            2 -> R.drawable.dice_2
            3 -> R.drawable.dice_3
            4 -> R.drawable.dice_4
            5 -> R.drawable.dice_5
            else -> R.drawable.dice_6
        }

        diceImage.setImageResource(drawableResourse)

        Toast.makeText(this,"Dice Rolled!",Toast.LENGTH_SHORT).show()
    }
}
