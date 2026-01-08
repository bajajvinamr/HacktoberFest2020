#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 || i == 5)
        {
            for (int j = 1; j <= n; j++)
                cout << "*";
        }
        else
        {
            cout << "*";
            for (int j = 1; j <= n - 2; j++)
                cout << " ";
            cout << "*";
        }

        cout << endl;
    }
}