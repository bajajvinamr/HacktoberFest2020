user_list=[]
n=int(input("enter the number"))
print("\n")
for i in range(0,1):

    j=0

    for j in range(0,n):
        print("number at {} location is".format(j))

        item=int(input())


        user_list.append(item)


        print("user list is :",user_list)
    j=int(input())



    if user_list[j]==max(user_list):
      print("winner")
    elif user_list[j]==max(user_list)-1:
      print("runner up")
    else:
      print("you are too  far behind")
