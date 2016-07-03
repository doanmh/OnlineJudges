/*
Prime Generator 
SPOJ
Simple Algorithms

Minh Doan
*/

#include <cstdio>
#include <iostream>

using namespace std;

bool isPrime(int x) {
	if (x < 2) {
		return false;
	} else if (x == 2) {
		return true;
	} else {
		for (int i = 2; i*i <= x; i++) {
			if (x % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &m, &n);
		for (int j = m; j <= n; j++) {
			if (isPrime(j)) {
				printf("%d\n", j);
			} 
		}
	}
	return 0;
}
