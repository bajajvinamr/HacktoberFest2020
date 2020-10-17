from os import system, name 
  
# import sleep to show output for some time period 
from time import sleep 
  
# define our clear function 
def clear(): 
  
    # for windows 
    if name == 'nt': 
        _ = system('cls') 
  
    # for mac and linux(here, os.name is 'posix') 
    else: 
        _ = system('clear') 
clear()
str1="."
str2="."
str3="."
str4="."
str5="."
str6="."
str7="."
str8="."
str9="."
Player1=input("\n\n\t\t\t\tEnter the name of the first player:")
Player2=input("\n\n\t\t\t\tEnter the name of the second player:")

def End_Check():
    if(str1!="." and str2!="." and str3!="." and str4!="." and str5!="." and str6!="." and str7!="." and str8!="." and str9!="."):
        print("\n\n\t\t\t\tIT IS A DRAW!!!")
        return 1
def show_Board():
    print("\n\n")
    print("\t\t\t\t        ",str1,"|     ",str2,"|    ",str3)
    print("\t\t\t\t-------------------------------")
    print("\t\t\t\t        ",str4,"|     ",str5,"|    ",str6)
    print("\t\t\t\t-------------------------------")
    print("\t\t\t\t        ",str7,"|     ",str8,"|    ",str9)
show_Board()
def Check_win():
    win="VICTORY"
    lose="LOST"
    if ((str1==str2 and str2==str3 and str2!=".") or (str1==str4 and str4==str7 and str4!=".") or (str1==str5 and str5==str9 and str5!=".") or (str2==str4 and str4==str8 and str4!=".") or (str3==str6 and str6==str9 and str6!=".") or (str7==str8 and str8==str9 and str8!=".") or (str4==str5 and str5==str6 and str5!=".") or (str3==str5 and str5==str7 and str5!=".")):
        return (win)
    else:
        return(lose)
print("\n\t\t\t\t*********WELCOME PLAYERS!*********\n\n")
while(1):
    n=int(input("\n\n\t\t\t\t" + Player1 + ": Enter number:"))
    if n==1 and str1==".":
        str1="X"
    elif n==2 and str2==".":
        str2="X"
    elif n==3 and str3==".":
        str3="X"
    elif n==4 and str4==".":
        str4="X"
    elif n==5 and str5==".":
        str5="X"
    elif n==6  and str6==".":
        str6="X"
    elif n==7 and str7==".":
        str7="X"
    elif n==8 and str8==".":
        str8="X"
    elif n==9 and str9==".":
        str9="X"
    else:
        print("\n\t\t\t\tPlease enter only numbers between 1-9 which are not filled yet")
        n=int(input("\n\n\t\t\t\t" + Player1 + ": Enter number:"))
        if n==1 and str1==".":
            str1="X"
        elif n==2 and str2==".":
            str2="X"
        elif n==3 and str3==".":
            str3="X"
        elif n==4 and str4==".":
            str4="X"
        elif n==5 and str5==".":
            str5="X"
        elif n==6 and str6==".":
            str6="X"
        elif n==7 and str7==".":
            str7="X"
        elif n==8 and str8==".":
            str8="X"
        elif n==9 and str9==".":
            str9="X"
    show_Board()
    str=Check_win()
    if(str=="VICTORY"):
        print("\n\n\t\t\t\t"+ Player1 +  " WINS")
        break 
    if(End_Check()):
        break
    m=int(input("\n\t\t\t\t"+ Player2 + ": Enter number:"))
    if m==1 and str1==".":
        str1="O"
    elif m==2 and str2==".":
        str2="O"
    elif m==3 and str3==".":
        str3="O"
    elif m==4 and str4==".":
        str4="O"
    elif m==5 and str5==".":
        str5="O"
    elif m==6 and str6==".":
        str6="O"
    elif m==7 and str7==".":
        str7="O"
    elif m==8 and str8==".":
        str8="O"
    elif m==9 and str9==".":
        str9="O"
    else:
        print("\t\t\t\tPlease enter only numbers between 1-9 which are not been chosen already.")
        m=int(input("\n\n\t\t\t\t" + Player2 + ": Enter number:"))
        if m==1 and str1==".":
            str1="X"
        elif m==2 and str2==".":
            str2="X"
        elif m==3 and str3==".":
            str3="X"
        elif m==4 and str4==".":
            str4="X"
        elif m==5 and str5==".":
            str5="X"
        elif m==6 and str6==".":
            str6="X"
        elif m==7 and str7==".":
            str7="X"
        elif m==8 and str8==".":
            str8="X"
        elif m==9 and str9==".":
            str9="X"
    show_Board()
    str=Check_win()
    if(str=="VICTORY"):
        print("\t\t\t\t" + Player2 +  " WINS")
        break 
    if(End_Check()):
        break