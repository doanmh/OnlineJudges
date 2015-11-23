#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
  //input
  int n;
  cin >> n;
  int a[n][n];
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }
  int size = n*(n+1)/2;
  int b[n][size];
  for (int i=0; i<n; i++){
    for (int j=0; j<size; j++){
      b[i][j] = 0;
    }
  }  
  int m = 1;
  int s = 0;
  for (int i=0; i<n; i++){ //row
    for (int j=0; j<n-1; j++){ //col
      while (m<=n-j){
        for (int k=j; k<j+m; k++){
          b[i][s] = b[i][s] + a[i][k];    
        }
        s = s + 1;
        m = m + 1;
      }
      m = 1;  
    }
    s = 0;
    b[i][size-1] = a[i][n-1];
  }
  m = 1;
  s = 0;
  int sum = 0;
  int max = -1270000;
  for (int i=0; i<size; i++){ //col
    for (int j=0; j<=n-1; j++){ //row
      while (m<=n-j){
        for (int k=j; k<j+m; k++){
          sum = sum + b[k][i];
        }
        s = s + 1;
        m = m + 1;
        if (sum > max){
          max = sum;
        }
        sum = 0;
      }
      m = 1;
    }
    s = 0;
  }
  cout << max << endl;
}
