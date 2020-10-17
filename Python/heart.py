n = 6		
for row in range(0,n):
    for column in range(0,n+1):
        if(row == 0 and column%3 != 0) or (row == 1 and column%3 == 0) or (row-column == 2) or (row + column == 8):
            print('#',end='')
        else:
            print(' ',end='')
              
    print()
