#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t ,i,j;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int c=0;
        scanf("%d",&n);
        vector <int> v;
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        vector <int>::iterator ip;
        ip = unique(v.begin(),v.end());
        c=distance(v.begin(),ip);
        int key =0;
        if (find(v.begin(), v.end(), key) != v.end())
        {
            printf("%d\n",c-1);
        }
        else
        {
        printf("%d\n",c);
        }
    }
}