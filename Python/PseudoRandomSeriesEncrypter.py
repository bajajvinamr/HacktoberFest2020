# this a highly secure encrypter using pseudo random series logic
# Author: cyberGhoulK

import time
def ceaser_cipher(msg, key1):
    a = "abcdefghijklmnopqrstuvwxyz"
    c = a.upper()
    b = "!@#$%^&*(){}[] ?><.,:;|/*-+_\'\""
    enc = ''
    key = int(key1 % 26)
    for char in msg:
        if char in b:
            enc += char
        elif char in c:
            pos = c.find(char)
            newpos = (pos + key) % 26
            newchar = c[newpos]
            enc += newchar
        else:
            pos = a.find(char)
            newpos = (pos + key) % 26
            newchar = a[newpos]
            enc += newchar
    return enc


def ceaser_cipher_d(msg, key):
    a = "abcdefghijklmnopqrstuvwxyz"
    c = a.upper()
    b = "!@#$%^&*() {}[]?><.,:;|/*-+_\'\""
    de = ''
    key = int(key % 26)
    for char in msg:
        if char in b:
            de += char
        elif char in c:
            pos = c.find(char)
            newpos = (pos - key) % 26
            newchar = c[newpos]
            de += newchar
        else:
            pos = a.find(char)
            newpos = (pos - key) % 26
            newchar = a[newpos]
            de += newchar

    return de


def generateNxtNumber(seed):
    seed = int(seed)
    if seed == 0 or seed == 1:
        seed = seed + 2
    new_num = seed * seed
    string_num = str(new_num)
    if len(string_num) > 4:
        while len(string_num) <= 8:
            string_num = '0' + string_num
        final_num = string_num[2:6]  # 01 2345 67
    else:
        while len(string_num) != 4:
            string_num = '0' + string_num
        final_num = string_num
    return final_num


def encrypt(msg, seed):
    enc = ""
    enc_key = ""
    for i, ch in enumerate(msg):
        if ch == " ":
            enc += ch
            continue
        if i % 2 == 0:
            enc_key = generateNxtNumber(seed)
            key = int(enc_key[:2])
            enc += ceaser_cipher(ch, key)
        else:
            key = int(enc_key[2:])
            enc += ceaser_cipher(ch, key)
            seed = int(enc_key)
    return enc


def decrypt(enc, seed):
    mesg = ""
    enc_key = ""
    for i, ch in enumerate(enc):
        if ch == " ":
            mesg += ch
            continue
        if i % 2 == 0:
            enc_key = generateNxtNumber(seed)
            key = int(enc_key[:2])
            mesg += ceaser_cipher_d(ch, key)
        else:
            key = int(enc_key[2:])
            mesg += ceaser_cipher_d(ch, key)
            seed = int(enc_key)
    return mesg


def re():
    sc_key = 0
    m = input("Encrypt(enter:e)\nDecode(enter:d)\n")
    m = m.lower()
    if m == "e":
        message = input("Enter Message to be encrypted:\n")
        seed = int(input("Enter a encryption seed(pin) : "))
        encrypted_out = encrypt(message, seed)
        print("Encrypted_message:\n%s" % (encrypted_out))
    elif m == "d":
        encrypted_in = input("Enter Message to be decrypted:\n")
        seed = int(input("Enter a decryption seed(pin) : "))
        mesg = decrypt(encrypted_in, seed)
        print("decoded_message:\n%s" % (mesg))
    repeat = input("\nAny thing else?\n")
    repeat = repeat.lower()
    if repeat == "ya" or repeat == "yes" or repeat == "yeah" or repeat == "y":
        re()
    else:
        print("Happy to serve you.")
    return


print('Welcome to the Engima')
time.sleep(1.0)
print("\nHello, what do you want to do today?")
re()
