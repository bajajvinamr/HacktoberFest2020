#include <iostream>
using namespace std;

int pattern_matching(string s2, string p2)
{
    int l_s = s2.length();
    int l_p = p2.length();
    bool flag;

    int max = l_s - l_p + 1;

    for (int i = 0; i < l_s; i++)
    {
        int j = 0;
        while (j < l_p && s2[i + j] == p2[j])
        {
            j++;
            if (j == l_p)
                return i + 1; //pattern found
        }
    }
    return 0;
}

int main()
{
    string s1, p1;
    cout << "Enter String";
    cin >> s1;
    cout << "Enter pattern";
    cin >> p1;
    int val = pattern_matching(s1, p1);

    if (val == 0)
    {
        cout << "Pattern not found";
    }
    else
    {
        cout << "Pattern found at " << val;
    }

    return 0;
}
