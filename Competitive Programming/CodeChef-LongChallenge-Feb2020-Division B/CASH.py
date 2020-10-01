def func(s):
    return s == s[::-1]
s = "pikachuchu"
ans = func(s)
if ans:
    print("Yes")
else:
    print("No")
