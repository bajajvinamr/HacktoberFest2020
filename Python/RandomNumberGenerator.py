import random
n = random.random()
print(n)
#%%
lis = []
def listofrandomnumbers():
    range_n = input("How many numbers do you want to generate?: ")
    minval = input("What is the minimum value you want to generate?: ")
    while len(lis) <= 10: 
        lis.append(int(range_n)*random.random()+int(minval))
        if len(lis) == 10 :
            break
    print(lis)
