#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter size";
    cin>>n;
    int arr[n];
    cout<<"enter elements in array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {     int s=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                 s=-1;
                 break;
            }
            
        }
        if(s==1)
        {
            cout<<arr[i]<<" ";
        }
    }

}