# -*- coding: utf-8 -*-
"""
Created on Thu Apr 16 08:45:48 2020

@author: ferna
"""

b = int(input("Masukan Berat Badan (kg): "))
t = int(input("Masukan Tinggi Badan (cm): "))
b = float(b)
t = float(t) / 100

bmi = b / (t * t)

if bmi < 18:
    Ket = "underweight"
elif bmi >25:
    ket = "overweight"
else:
    ket = "normal"

print('Body Mass Index (BMI) atau Index Mass Tubuh (IMT) : ',round(bmi,1))