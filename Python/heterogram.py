string=input()
lst=[]
for i in string.lower():
    if ord(i)>=ord('a') and ord(i)<=ord('z'):
        lst.append(i)
s1=set(lst)
if len(s1)==len(lst):
    print("Heterogram string")
else:
    print("its not heterogram string")
