from itertools import accumulate 
def summ(input): 
      print ("The Sum is", list(accumulate(input))) 
if __name__ == "__main__": 
    input = [4, 6, 12] 
    summ(input) 
