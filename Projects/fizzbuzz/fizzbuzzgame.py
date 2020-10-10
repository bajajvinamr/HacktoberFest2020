import time
a=1
while a>=0:
 if(a%2!=0):
    if(a%5==0 and a%3==0):
        print('fizzbuzz')
        print('\n')
        a=a+1
        time.sleep(1)
    elif(a%3==0):
        print('fizz')
        print('\n')
        a=a+1
        time.sleep(1)
    elif(a%5==0):
        print('buzz')
        print('\n')
        a=a+1
        time.sleep(1)
    else:
        print(a)
        print('\n')
        a=a+1
        time.sleep(1)
 else:
    if(a%5==0 and a%3==0):
        print('\tfizzbuzz')
        print('\n')
        a=a+1
        time.sleep(1)
    elif(a%3==0):
        print('\tfizz')
        print('\n')
        a=a+1
        time.sleep(1)
    elif(a%5==0):
        print('\tbuzz')
        print('\n')
        a=a+1
        time.sleep(1)
    else:
        print('\t',a)
        print('\n')
        a=a+1
        time.sleep(1)


 