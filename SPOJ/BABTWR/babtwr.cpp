/* 
Tower of Babylon
SPOJ Online Judge

Box stacking problem

Minh Doan
*/

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n, a, b, c, x[90], y[90], z[90], dp[90];

	while (true) {
		//Read data
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			//Generate combination of width, height, depth			
			x[3*i] = a; y[3*i] = b; z[3*i] = c;
			x[3*i + 1] = b; y[3*i + 1] = c; z[3*i + 1] = a;
			x[3*i + 2] = c; y[3*i + 2] = a; z[3*i + 2] = b;
		}		
		int N = 3*n;
		//Sort the box in increasing order of base 
		//Can use quicksort here
		for (int i = 0; i < N; i++) {
			for (int j= i+1; j < N; j++) {
				if ((x[j] < x[i] && y[j] < y[i]) || (y[j] < x[i] && x[j] < y[i])) {
					swap(x[i], x[j]);
					swap(y[i], y[j]);
					swap(z[i], z[j]);
				}
			}
		}
		int ans = -1;
		//Dynamic programming solution
		for (int i = 0; i < N; i++) {
			dp[i] = z[i];
			for (int j = 0; j < i; j++) {
				if ((x[j] < x[i] && y[j] < y[i]) || (y[j] < x[i] && x[j] < y[i])) {
					dp[i] = max(dp[i], dp[j] + z[i]);
				}
				ans = max(ans, dp[i]);
			}
		}
		//Print the result
		printf("%d\n", ans);
	}
	return 0;
}