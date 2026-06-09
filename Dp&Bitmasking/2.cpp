#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;
char sl[nax];
int main() {
	scanf("%s", sl);
	int ans = 0, pre = 0, n = strlen(sl);
	assert(1 <= n && n <= 100 * 1000);
	for(int i = 0; i < n; ++i) {
		int here = 'Z' - sl[i];
		assert(0 <= here && here < 26);
		ans = (ans + here + (long long) pre * here) % mod;
		pre = (here + 26LL * pre) % mod;
	}
	printf("%d\n", ans);
}
