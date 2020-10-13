message = "This is my secret message."

key = 13

mode = "encrypt"

LETTERS = "ABCDEFGHIKLJMNOPQRSTUVWXYZ"

translated = ""

message = message.upper()

for symbol in message:
    if symbol in LETTERS:
        num = LETTERS.find(symbol)
        if mode == 'encrypt':
            num += key
        elif mode == 'decrypt':
            num -= key
        if num >= len(LETTERS):
            num -= len(LETTERS)
        elif num < 0:
            num += len(LETTERS)

        translated += LETTERS[num]
    else:
        translated += symbol

print(translated)
