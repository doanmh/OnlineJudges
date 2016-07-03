/*
Buidling Bridge
SPOJ

Minh Doan

Longest Increasing Subsequence Problem
*/


#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

void bubblesort(int *data, int *array, int size) {
	int n = size;
  	bool swap = true;
  	while (swap){
    	swap = false;
    	for (int i = 1; i < n; i++){
	      	if (data[i-1] > data[i]){
	        	int temp = data[i-1];
	        	data[i-1] = data[i];
	        	data[i] = temp;
	        	temp = array[i-1];
	        	array[i-1] = array[i];
	        	array[i] = temp;
	        	swap = true;
	      	}
	      	if (data[i-1] == data[i]) {
	      		if (array[i-1] > array[i]) {
		      		int	temp = data[i-1];
		        	data[i-1] = data[i];
		        	data[i] = temp;
		        	temp = array[i-1];
		        	array[i-1] = array[i];
		        	array[i] = temp;
		        	swap = true;
	      		}
	      	}
    	}
  	}
}

void lis(int X[],int n){
	int P[n], M[n+1];
	int L = 0;
	for (int i=0; i<n; i++){
		int low = 1;
		int high = L;
		while (low <= high){
			int mid = ceil((low + high)/2);
			if (X[M[mid]] <= X[i]){
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
	printf("%d\n", L);
}

int main() {
	int t, n;
	scanf("%d", &t);
	for (int  i = 0; i < t; i++) {
		scanf("%d", &n);
		int north[n], south[n], sorted[n];
		for (int j = 0; j < n; j++) {
			scanf("%d", &north[j]);
			sorted[j] = north[j];
		}
		for (int k = 0; k < n; k++) {
			scanf("%d", &south[k]);

		}
		bubblesort(south, sorted, n);
		lis(sorted, n);
	}
	return 0;
}