/* 
Minimum coin change solution
Dynamic Programmming Solution

Minh Doan
May 28th 
*/

#include <iostream>
#include <climits>

using namespace std;

int minCoinChange(int coins[], int m, int V) {
	int coinNumber[V+1];
	
	for (int i = 1; i <= V; i++) {
		coinNumber[i] = INT_MAX;
	}

	coinNumber[0] = 0;

	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < m; j++) {
			if (coins[j] <= i) {
				int subResult = coinNumber[i - coins[j]];
				if (subResult != INT_MAX && subResult + 1 < coinNumber[i]) {
					coinNumber[i] = 1 + subResult;		
				}
			}
		}
	}

	return coinNumber[V];
}

int main() {
	int coins[] =  {9, 6, 5, 1};
  int m = sizeof(coins)/sizeof(coins[0]);
  int V = 11;
  cout << "Minimum coins required is " << minCoinChange(coins, m, V) << endl;
  return 0;
}