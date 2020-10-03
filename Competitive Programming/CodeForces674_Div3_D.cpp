#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{

	//freopen("input.txt", "r", stdin);
	//freopen("ouput.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	ll n;
	cin >> n;
	unordered_set<ll> mp;
	ll sum = 0;
	ll m = 0;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++)
		cin >> arr[i];
	mp.insert(0);
	for (ll i = 0; i < n; i++)
	{
		sum += arr[i];
		if (mp.find(sum) != mp.end())
		{
			mp.clear();
			m++;
			sum = arr[i];
			mp.insert(0);
			mp.insert(sum);
		}
		else
			mp.insert(sum);
	}
	cout << m << endl;

	return 0;
}