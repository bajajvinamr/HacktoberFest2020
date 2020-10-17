def rainbow():
    print("Rainbow comprises of VIBGYOR")
    print("Each letter stands for a specific color")
    print("To know the color name, enter that specific letter.")
    code=input("Enter the colour code :")
    if (code=='V' or code=='v'):
        print ("VIOLET")
    elif (code=='I' or code=='i'):
        print ("INDIGO")
    elif (code=='B' or code=='b'):
        print ("BLUE")
    elif (code=='G' or code=='g'):
        print ("GREEN")
    elif (code=='Y' or code=='y'):
        print ("YELLOW")
    elif (code=='O' or code=='o'):
        print ("ORANGE")
    elif (code=='R' or code=='r'):
        print ("RED")
    else:
        print ("INVALID INPUT")
rainbow()
