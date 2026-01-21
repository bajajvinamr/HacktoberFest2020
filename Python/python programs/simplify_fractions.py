# Python3 program to reduce a fraction x/y  
# to its lowest form 
from math import gcd  

def reduceFraction(x, y) : 
      
    d = gcd(x, y)
  
    x = x // d
    y = y // d 
  
    print("x =", x, ", y =", y) 
  
if __name__ == "__main__" : 
  
    x = int(input())
    y = int(input())
  
    reduceFraction(x, y)