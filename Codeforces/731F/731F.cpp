#include<bits/stdc++.h>

using namespace std;

#define MAXN 400100
typedef long long ll;

int n, x, c[MAXN], f[MAXN];
ll ans;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		c[x]++;
	}
	for (int i = 200000; i; i--) {
		f[i] = f[i+1] + c[i]; 
	}
	for (int i = 1; i <= 200000; i++) {
		if (c[i]) {
			ll sum = 0;
			for (int j = i; j <= 200000; j+=i) {
				sum += (ll)(f[j] - f[j+i])*j;
			}
			ans = max(ans, sum);
		}		
	}

	cout << ans << endl;

	return 0;
}