while True:
    def dectohex(N):
        bits = ""
        while N != 0:
            x = str(N%16)
            if x == str(10):
                x = "A"
                bits +=x
            elif x == str(11):
                x = "B"
                bits +=x
            elif x == str(12):
                x = "C"
                bits +=x
            elif x == str(13):
                x = "D"
                bits +=x
            elif x == str(14):
                x = "E"
                bits +=x
            elif x == str(15):
                x = "F"
                bits +=x
            else:
                bits+=x
            N = N//16
        print("Hex: " + bits[::-1])    


    num=eval(input("Please enter a whole number:  "))

    dectohex(num)
