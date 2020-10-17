#!/usr/bin/python3
'''
Using Python Script To Take Screenshot
------------------------------------------------------
1) Install a module "Pyautogui", use this command to install: pip install pyautogui
2) Create a file with python extension
3) import module "pyautogui"
4) Store pyautogui.screenshot() function in a variable
5) save variable: variable_name.save() by including path and image name where you'd like to store screenshot in between parenthesis. for eg. variable_name.save(r"/home/user/Desktop/screenshot.png")
6) run the file in your terminal/cmd.
-----------------------------------------------------------------------------------------
Note: For linux user you'll need scrot in order to run screenshot functionality. run sudo apt-get install scrot to install in a debian based distro probably.
'''
import pyautogui
image = pyautogui.screenshot()
image.save(r"/home/bhawesh/Desktop/screenshottaken.png")