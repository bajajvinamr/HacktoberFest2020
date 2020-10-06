SECURE = (('s','$') , ('and','&'), ('a','@'), ('o','0'), ('i','!') , ('I','|') , ('T','7') , ('b','6') , ('c','(') , ('E','3') , ('L','1') )

def securePassword(password):
    for a,b in SECURE:
        password = password.replace(a,b)

    return password

if __name__ == "__main__":
    password = input("Enter your password: ")
    password = securePassword(password)
    print(f"Your secured password is : {password}")
