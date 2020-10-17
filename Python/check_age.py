from datetime import date

current_date = date.today()

print("Hello I will check your age")
print("===========================")

born_year = int(input("What year you were born: "))
current_year = int(input("What year is it now: "))

check = current_year-born_year

if(born_year > current_date.year):
    print("you're lying, you can't")
elif(current_year != current_date.year):
    print("You're lying right, it's", current_date.year)
else:
    print("So your age now is: " + str(check) + " year")
