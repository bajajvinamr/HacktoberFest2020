            #QUOTE SCRAPPING PROJECT !!
    #STEPS TO FOLLOW :
#STEP 01 : MAKE REQUEST AND GET O.K RESPONSE
#STEP 02 : EXTRACT THE HTML DATA BEAUTIFULSOUP
#STEP 03 : ORGNIZE THE DATA (LOOP WITH ARRAY,DICTIONARY ..ETC)
#STEP 04 : CREATE YOUR GAME LOGIC
#STEP 05 : APPEND THE DATA INTO A CSV FILE 
#STEP 06 : REFACTOR YOUR CODE 
            #PART I : LIBRARIES NEEDED
import requests
from bs4 import BeautifulSoup
from csv import writer
from time import sleep 
import random
from random import choice
            #PART II : THE CODE 
all_quotes = []
the_URL = "http://quotes.toscrape.com"
url = "/page/1/"

while url:
    response = requests.get(f"{the_URL}{url}")
    print(f"We are scraping {the_URL}{url}")
    soup = BeautifulSoup(response.text, "html.parser")
    quotes = soup.find_all(class_="quote")

    for qt in quotes :
        all_quotes.append({
            "Quote":qt.find(class_="text").get_text(),
            "Author": qt.find(class_="author").get_text(),
            "Bio" : qt.find("a")['href']
        })
        next_page = soup.find(class_="next")
        url = next_page.find("a")['href'] if next_page else None
                    #GAME LOGIC !!
def start_game():
    the_quote = choice(all_quotes)
    remaining_guesses = 4
    print(f"Here's the Quote of the day \n : ")
    print(the_quote["Quote"]) 
    guess = ''
    while guess.lower() != the_quote["Author"].lower() and remaining_guesses != 0:
        guess = input(f"Who said this Quote? Guesses remaining are {remaining_guesses}! \n")
        if guess.lower() == the_quote["Author"].lower():
            print("Guessed it right!!!")
            break
        remaining_guesses -=1
        if remaining_guesses == 3 :
            res = requests.get(f"{the_URL}{the_quote['Bio']}")
            soup = BeautifulSoup(res.text, "html.parser")
            author_born_date = soup.find(class_="author-born-date").get_text()
            author_born_place = soup.find(class_="author-born-location").get_text()
            print(f"Here is a hint --> :\n The author was born on {author_born_date}, {author_born_place}")
        elif remaining_guesses == 2:
            print(f"Here is another Hint --> : \nThe author's first name starts with : {the_quote['Author'][0]}")
        elif remaining_guesses == 1:
            last_initial = the_quote['Author'].split(" ")[1][0]
            last_last = the_quote['Author'][len(the_quote['Author'])-1]
            print(f"Okay, Another hint --> :\n The author's last name starts with {last_initial} and it ends with : {last_last}")
        else :
            print(f"you ran out of guesses!! :( \n The answer was : {the_quote['Author']}")
start_game()
again = ""
while again.lower() not in ('y', 'n', 'yes', 'no'):
    again = input("Would you like to play again Y/N?")
if again.lower() in ('y', 'yes') :
    print("Let's GOOO!!!")
    start_game()
else :
    print("Ok, Farewell!!!")

print("EXIIIIT")
    #WRITING INTO THE CSV FILE
with open("quotes.csv", "w") as csv_file:
    csv_write = writer(csv_file)
    csv_write.writerow(['Quote', "Author", "bio"])
    for qt in all_quotes:
        csv_write.writerow([qt["Quote"], qt["Author"], qt["Bio"]])
