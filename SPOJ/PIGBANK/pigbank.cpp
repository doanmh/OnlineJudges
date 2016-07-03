/* 
	PIGBANK - Piggy Bank Solution
	SPOJ Online Judge

	Dynamic Programming
*/

#include <cstdio>

using namespace std;

int main() {
	int t, e, f, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &e, &f);
		scanf("%d", &n);
		int money = f - e;
		int w[n], p[n], dp[money+1];
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p[i], &w[i]);
		}
		dp[0] = 0;
		for (int i = 1; i <= money; i++) {
			dp[i] = -1;
			for (int j = 0; j < n; j++) {
				if (i >= w[j] && (dp[i - w[j]] != -1) && (dp[i] == -1 || (p[j] + dp[i - w[j]] <= dp[i]))) {
					dp[i] = p[j] + dp[i - w[j]];
				}
			}
		}
		if (dp[money] == -1) {
			printf("This is impossible.\n");
		} else {
			printf("The minimum amount of money in the piggy-bank is %d.\n", dp[money]);
		}
	}
	return 0;
}