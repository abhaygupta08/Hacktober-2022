package com.example.diceroller

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.diceroller.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        val view = binding.root
        setContentView(view)

        binding.button.setOnClickListener {

            var etTextVar: String = binding.etOne.text.toString()

            if (etTextVar == "harsh") {
                harsh()
            }
            else if (etTextVar == "rhythm") {
                rhythm()
            }
            else if(etTextVar == "rahul") {
                rahul()
            }
            else {
                rand()
            }
        }

    }

    private fun rahul() {
        when ((1..2).random()) {
            1 -> binding.imageView.setImageResource(R.drawable.dice_1)
            2 -> binding.imageView.setImageResource(R.drawable.dice_2)
        }
    }

    private fun rhythm() {
        when ((2..4).random()) {
            2 -> binding.imageView.setImageResource(R.drawable.dice_2)
            3 -> binding.imageView.setImageResource(R.drawable.dice_3)
            4 -> binding.imageView.setImageResource(R.drawable.dice_4)
        }
    }

    private fun harsh() {
        when ((4..6).random()) {
            4 -> binding.imageView.setImageResource(R.drawable.dice_4)
            5 -> binding.imageView.setImageResource(R.drawable.dice_5)
            6 -> binding.imageView.setImageResource(R.drawable.dice_6)
        }
    }

    private fun rand() {
        when ((1..6).random()) {
            1 -> binding.imageView.setImageResource(R.drawable.dice_1)
            2 -> binding.imageView.setImageResource(R.drawable.dice_2)
            3 -> binding.imageView.setImageResource(R.drawable.dice_3)
            4 -> binding.imageView.setImageResource(R.drawable.dice_4)
            5 -> binding.imageView.setImageResource(R.drawable.dice_5)
            6 -> binding.imageView.setImageResource(R.drawable.dice_6)
        }
    }
}
