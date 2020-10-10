def leapyear(year):
	if year % 4 == 0:
		print("Its a leap year")
	elif year % 100 == 0:
		print("Its a leap year")
	elif year % 400 == 0:
		print("Its a leap year")
	else:
		print("Its not a leap year")
year = int(input("Enter a Year"))
leapyear(year)
