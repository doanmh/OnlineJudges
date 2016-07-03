/* 
	NHAY - A Needle in the Haystack
	SPOJ Online Judge

	KMP Algorithm
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void partialFunction(int *T, string pattern) {
	int pos = 2;
	int cnd = 0;
	T[0] = -1;
	T[1] = 0;
	while (pos <= pattern.length()) {
		if (pattern[pos - 1] == pattern[cnd]) {
			T[pos] = cnd + 1;
			cnd++;
			pos++;
		} else if (cnd > 0) {
			cnd = T[cnd];
		} else {
			T[pos] = 0;
			pos++;
		}
	}
}

void kmp(int *T, string text, string pattern) {
	int m = 0;
	int i = 0;
	bool found = false;
	while (m + i < text.length()) {
		if (pattern[i] == text[m+i]) {
			if (i == (pattern.length() - 1)) {
				found = true;
				cout << m << "\n";
				i = 0;
				m++;
				continue;
			}
			i++;
		} else {
			if (T[i] > -1) {
				m = m + i - T[i];
				i = T[i];
			} else {
				m = m + 1;
				i = 0;
			}
		}
	}
	if(!found) cout << "\n";
	cout << "\n";
}

int main() {
	int n;
	while (scanf("%d", &n) == true) {
		string text, pattern;
		cin >> pattern >> text;
		int T[pattern.length()];
		partialFunction(T, pattern);
		kmp(T, text, pattern);
	} 
	return 0;
}