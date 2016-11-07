/*
	Code Fore
	Shortest Path for the King
*/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
	string s,t;
	cin >> s >> t;
	cout << max(abs(s[0] - t[0]), abs(s[1] - t[1])) << endl;

	while (s != t) {
		if (s[0] < t[0]) {
			cout << "R";
			s[0] += 1;
		} 
		if (s[0] > t[0]) {
			cout << "L";
			s[0] -= 1;
		}
		if (s[1] < t[1]) {
			cout << "U";
			s[1] += 1;
		}
		if (s[1] > t[1]) {
			cout << "D";
			s[1] -= 1;
		}
		cout << endl;
	}

	return 0;
}