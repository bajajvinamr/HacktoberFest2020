from colorama import Fore, Style, Back
import os
def regex():
    op = input('If you want to attach a file,type "file.open", else press Enter: ')
    if op == "file.open":
        path=input('Enter file path:')
        fl = open(path,"r+")
        fl.seek(0,os.SEEK_SET)
        l=fl.read()
        print("\nString read from the file:") 
        print(l)
        k = input('Enter key:')
        p=input('If you want to replace the key in text with something else, press 0:\n')
        if p =='0':
            r=input('Enter replacement character:')
            fl.seek(0, os.SEEK_SET)
            l2= map(lambda x: r if(x==k) else x,l)
            l2=''.join(l2)
            fl.write(l2)
            print("File has been written.")
            print('Original string:')
            highlight(k,l,k)
            print('Altered string:')
            highlight(k,l,r)

        else:
            highlight(k,l,k)


    else:
        k = input('Enter key:')
        l=input('Enter text:\n')
        p=input('If you want to replace the key in text with something else, press 0:\n')
        if p =='0':
            r=input('replacement character:')
            print('Original String:')
            highlight(k,l,k)
            print('Altered string:')
            highlight(k,l,r)
        else:
            highlight(k,l,k)

def highlight(k,l,r):
    if l.startswith(k) == False and l.endswith(k) == False:
        p= l.split(k)
        s=f'{Back.BLUE}{r}{Style.RESET_ALL}'
        print(s.join(p))
    elif(l.startswith(k)==False):
        p= l[0:-1].split(k)
        s=f'{Back.BLUE}{r}{Style.RESET_ALL}'
        print(s.join(p)+s)


    elif(l.endswith(k)==False):
        p= l[1:].split(k)
        s=f'{Back.BLUE}{r}{Style.RESET_ALL}'
        print(s+s.join(p))

    else:
        p= l[1:-1].split(k)
        s=f'{Back.BLUE}{r}{Style.RESET_ALL}'
        print(s+s.join(p)+s)
regex()
