#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

const int N = 500 * 1000 + 13;

int n, k;
int a[N], b[N];

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n) scanf("%d", &a[i + 1]);
	a[0] = -1e9;
	a[n + 1] = 2e9;
	forn(i, n + 2) a[i] -= i;
	forn(i, k) scanf("%d", &b[i + 1]);
	b[k + 1] = n + 1;
	
	int ans = 0;
	forn(i, k + 1) {
		int l = b[i], r = b[i + 1];
		if (a[l] > a[r]) {
			puts("-1");
			return 0;
		}
		vector<int> lis;
		for (int j = l + 1; j < r; ++j) if (a[l] <= a[j] && a[j] <= a[r]) {
			auto pos = upper_bound(lis.begin(), lis.end(), a[j]);
			if (pos == lis.end()) lis.push_back(a[j]);
			else *pos = a[j];
		}
		ans += (r - l - 1) - int(lis.size());
	}
	
	printf("%d\n", ans);
}