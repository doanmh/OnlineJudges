/*
	Codeforces
	The least round way
*/

#include <cstdio>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main () {
	int n, zero_x, zero_y;
	long ans;
	bool zero = false;
	scanf("%d", &n);
	long two[n][n], five[n][n], matrix[n][n];
	char path_two[n][n], path_five[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%ld", &matrix[i][j]);
			if (matrix[i][j] == 0) {
				zero_x = i;
				zero_y = j;
				zero = true;
			}
			//compute two and five
			int temp = matrix[i][j];
			long count_two = 0, count_five = 0;
			do {
				if (temp % 2 == 0) {
					temp /= 2;
					count_two++;
				} else if (temp % 5 == 0) {
					temp /= 5;
					count_five++;
				} else {
					break;
				}
				
			} while (temp != 0);
			two[i][j] = count_two;
			five[i][j] = count_five;
		}
	}

	for (int i = 1; i < n; i++) {
		two[0][i] += two[0][i-1];
		path_two[0][i] = 'R';
		two[i][0] += two[i-1][0];
		path_two[i][0] = 'D';
		five[0][i] += five[0][i-1];
		path_five[0][i] = 'R';
		five[i][0] += five[i-1][0];
		path_five[i][0] = 'D';
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (two[i-1][j] < two[i][j-1]) {
				path_two[i][j] = 'D';
				two[i][j] += two[i-1][j];
			} else {
				path_two[i][j] = 'R';
				two[i][j] += two[i][j-1];
			}
			if (five[i-1][j] < five[i][j-1]) {
				path_five[i][j] = 'D';
				five[i][j] += five[i-1][j];
			} else {
				path_five[i][j] = 'R';
				five[i][j] += five[i][j-1];
			}
		}
	}

	ans = min(two[n-1][n-1], five[n-1][n-1]);
	char path[2*(n-1)];
	if (ans > 1 && zero) {
		ans = 1;
		int idx=0;
        for (int i = 0; i < zero_x; ++i) {
            path[idx++] = 'D';
        }
        for (int j = 0; j < zero_y; ++j) {
            path[idx++] = 'R';
        }
        for (int i = zero_x; i < n-1; ++i) {
            path[idx++] = 'D';
        }
        for (int j = zero_y; j < n-1; ++j) {
            path[idx++] = 'R';
        }
	} else {
		if (two[n-1][n-1] < five[n-1][n-1]) {
			int x = n-1, y = n-1;
			for (int i = 2*(n-1)-1; i >= 0; i--) {
				if (path_two[x][y] == 'R') {
					y--;
					path[i] = 'R';
				} else {
					x--;
					path[i] = 'D';
				}
			}
		} else {
			int x = n-1, y = n-1;
			for (int i = 2*(n-1)-1; i >= 0; i--) {
				if (path_five[x][y] == 'R') {
					y--;
					path[i] = 'R';
				} else {
					x--;
					path[i] = 'D';
				}
			}
		}
		
	}

	printf("%ld\n", ans);

	for (int i = 0; i < 2*(n-1); i++) {
		printf("%c", path[i]);
	}

	printf("\n");
	return 0;
}