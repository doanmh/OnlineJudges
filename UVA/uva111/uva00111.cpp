//uva111: history grading
/* 
Longest Increasing Subsequence Problem
Dynamic Programming 

Minh Doan
*/
#include <iostream>
#include <cmath>

using namespace std;

void lis(int X[],int n){
	int P[n], M[n+1];
	int L = 0;
	for (int i=0; i<n; i++){
		int low = 1;
		int high = L;
		while (low <= high){
			int mid = ceil((low + high)/2);
			if (X[M[mid]] < X[i]){
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		int newL = low;

		P[i] = M[newL - 1];
		M[newL] = i;

		if (newL > L){
			L = newL;
		}
	}
	int S[L];
	int k = M[L];
	for (int i=L-1; i>=0; i--){
		S[i] = X[k];
		k = P[k];
	}
	cout << L << endl;
}

int main(){
	int N;
	cin >> N;
	int correct[N],answer[N];
	for (int i=0; i<N; i++){
		cin >> correct[i];
	}
	int temp;
	while (cin >> temp){
		temp = temp -1;
		answer[temp] = correct[0];
		for (int i=1; i<N; i++){
			cin >> temp;
			temp = temp -1;
			answer[temp] = correct[i];
		}
		lis(answer,N);
	}
	return 0;
}