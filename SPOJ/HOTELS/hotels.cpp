/* 
	Problem HOTELS

	SPOJ
	Minh Doan
*/

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int m, n;
	int current = 0;
	scanf("%d %d", &n, &m);
	int h[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int index = 0;
	int ans = h[0];
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			current = current - h[i-1];
		}
		while (index <= n-1 && current < m) {
			current += h[index];
			//printf("current: %d\n", current);
			index++;
		}
		if (current == m) {
			printf("%d\n", current);
			return 0;
		} else if (current > m) {
			index--;
			current = current - h[index];
		}
		if (ans < current) {
			ans = current;
		}
	}
	printf("%d\n", ans);
	return 0;
}
