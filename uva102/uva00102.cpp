//Ecological Bin Packing
#include <iostream>

using namespace std;

int main(){
  int B[3],G[3],C[3],temp,smallest;
  char first, second, third;
  while (cin >> B[0] >> G[0] >> C[0] >> B[1] >> G[1] >> C[1] >> B[2] >> G[2] >> C[2]){
     smallest = B[1] + B[2] + C[0] + C[2] + G[0] + G[1];
     first = 'B'; 
     second = 'C'; 
     third = 'G';
     temp = B[1] + B[2] + G[0] + G[2] + C[0] + C[1];
     if (temp < smallest){
      smallest = temp;
      first = 'B'; 
      second = 'G';
      third = 'C';
     }
     temp = B[0] + B[2] + G[0] + G[1] + C[1] + C[2];
     if (temp < smallest){
      smallest = temp;
      first = 'C'; 
      second = 'B';
      third = 'G';
     }
     temp = B[1] + B[0] + G[0] + G[2] + C[2] + C[1];
     if (temp < smallest){
      smallest = temp;
      first = 'C'; 
      second = 'G';
      third = 'B';
     }
     temp = B[0] + B[2] + G[1] + G[2] + C[0] + C[1];
     if (temp < smallest){
      smallest = temp;
      first = 'G'; 
      second = 'B';
      third = 'C';
     }
     temp = B[1] + B[0] + G[1] + G[2] + C[0] + C[2];
     if (temp < smallest){
      smallest = temp;
      first = 'G'; 
      second = 'C';
      third = 'B';
     }
     cout << first << second << third << " " << smallest << endl;
  }
  return 0;
}

