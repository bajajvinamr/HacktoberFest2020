#MaxwellOliveira01
num = int(input("Enter a number: "))
if num == 0 or num == 1: print(1)
else:
    ans = 1
    while num > 0:
        ans *= num
        num-=1
    print(ans)
