/* 
Prime Generator 
SPOJ

Segmented Sieve of Eratosthenes

Minh Doan 
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	int t, m, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++){
		scanf("%d %d", &m, &n);
		vector<int> initPrime;
		int SIZE = ceil(sqrt(n)) + 1;
		bool iPrime[34000];
		for (int i = 0; i<SIZE; i++) {
			iPrime[i] = true;
		}
		for (int p = 2; p*p <= sqrt(n); p++) {
			if (iPrime[p]) {
				for (int k = p*2; k <= sqrt(n); k += p) {
					iPrime[k] = false;
				}
			}
		}
		for (int j = 2; j <= SIZE; j++) {
			if (iPrime[j]) {
				initPrime.push_back(j);
			}
		}
		int len = initPrime.size();
		bool prime[n-m+1];
		memset(prime, true, sizeof(prime));
		if (m == 0) {
			prime[0] = false; prime[1] = false;
		} 
		if (m == 1) {
			prime[0] = false;
		}
		for (int j = 0; j < len; j++) {
			int s;
			if (initPrime[j] > m) {
				s = initPrime[j];
			} else {
				s = initPrime[j]*floor(m/initPrime[j]);
			} 
			for (int h = s; h <= n; h += initPrime[j]) {
				if (h < m) {
					continue;
				} else if (h == m) {
					if (h/initPrime[j] == 1) {
						continue;
					}
				} else {
					if (h == initPrime[j]) {
						continue;
					}
				}
				prime[h-m] = false;
			}
		}
		for (int k = 0; k < n-m+1; k++) {
			if (prime[k]) {
				printf("%d\n", k+m);
			}
		}
	}
	return 0;
}