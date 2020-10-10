
#include <bits/stdc++.h> 
using namespace std; 
  
void tower(int n, char from_rod, 
                    char to_rod, char aux_rod)  
{  
    if (n == 1)  
    {  
        cout << "Move disk 1 from rod " << from_rod <<  
                            " to rod " << to_rod<<endl;  
        return;  
    }  
    tower(n - 1, from_rod, aux_rod, to_rod);  
    cout << "Move disk " << n << " from rod " << from_rod << 
                                " to rod " << to_rod << endl;  
    tower(n - 1, aux_rod, to_rod, from_rod);  
}  
  

int main()  
{  
    int n ;
    printf("number of discs in the tower:");
        scanf("%d",&n);
    tower(n, 'A', 'C', 'B'); 
    cout<<"the number of shifts of discs is  "<<pow(2,n)-1;
    return 0;  
}  
