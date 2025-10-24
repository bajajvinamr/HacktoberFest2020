import time
a=1
while a>=0:
    if(a%5==0 and a%3==0):
        print('fizzbuzz')
        print('\n')
        a+=1
        time.sleep(1)
    elif(a%3==0):
        print('\tfizz')
        print('\n')
        a+=1
        time.sleep(1)
    elif(a%3==0):
        print('\tfbuzz')
        print('\n')
        a+=1
        time.sleep(1)
    else:
        print('\t',a)
        print('\n')
        a+=1
        time.sleep(1)
    