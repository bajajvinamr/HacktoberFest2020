/* Descending Order using Insertion Sort with C++ */
#include<iostream>
using namespace std;
main()
{
	int i,t,j,k;
	int x =5;
	int numbers[] = {3,1,4,2,8}; // contains a list of 5 numbers in the form of an array
	cout<<" Insertion Sort - Descending Order \n";
 
    cout<<" before data sorted in descending :";
    for(i=1;i<=x;i++)
    {
        cout<<"  "<<numbers[i];
    }

    cout<<endl;
    
    for(i=1;i<=x;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(numbers[i]>numbers[j])
            {
                t = numbers[i];
                    numbers[i]=numbers[j];
                    numbers[j]=t;
                }
            }
            cout<<"\n # "<<i<<" : ";
        for(k=1;k<=i;k++)
        {
            cout<<"  "<<numbers[k];
        }
    }
    
    cout<<"\n\n after data sorted in descending : ";
   
    for(i=1;i<=x;i++)
    {
        cout<<" "<<numbers[i];
    }
}