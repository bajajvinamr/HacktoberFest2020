from functools import lru_cache  

@lru_cache(maxsize=1000)  #stores the values of calculate fibonacci numbers for faster excecution in cache
def fib(n):
 if n == 1:
   return 0
 elif n == 2:
   return 1
 else:
   return fib(n - 1) + fib(n - 2)
   
# lets call this for some values 
for i in range(1, 50):
  print(fib(i))
