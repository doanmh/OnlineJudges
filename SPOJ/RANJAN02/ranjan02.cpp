/* 
	Tower of Hanoi - RANJAN02
	SPOJ
	Minh Doan
*/
#include <cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		unsigned long long c[n+1];
		c[1] = 2;
		for (int j = 2; j <= n; j++) {
			c[j] = 3*c[j-1] + 2;
		}
		printf("%llu\n", c[n]);
	}
}