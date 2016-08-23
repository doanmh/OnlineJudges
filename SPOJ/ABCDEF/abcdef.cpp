/* 
	Problem ABCDEF 

	SPOJ
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int s[100], n, low, high;
	long long ans = 0LL;
	vector<int> lhs, rhs;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (s[k] != 0) {
					rhs.push_back((s[i] + s[j]) * s[k]);
				}
				lhs.push_back(s[i]*s[j] + s[k]);
			}
		}
	}
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());
	for (int i = 0; i < lhs.size(); i++) {
		low = lower_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		high = upper_bound(rhs.begin(), rhs.end(), lhs[i]) - rhs.begin();
		ans += high - low;
	}
	printf("%lld\n", ans);
	return 0;
}		