arr = list()
size=int(input("Input the size of list :"))
for i in range(0,size):
    ele=int(input("Input element no. %d : "%(i+1)))
    arr.append(ele)
print("\nThe inputted list is = {}".format(arr))
flag=int(input("\nEnter the element to be searched for :")) 
count=0
print()
for i in range(len(arr)):
    if(arr[i]==flag):
        count=count+1
        print("Element %d found at location %d"%(flag,i+1))
if (count == 0):
    print("Element %d is not present in the list"%flag)
print("\nThus, element %d is found %d times in the inputted list."%(flag,count))
