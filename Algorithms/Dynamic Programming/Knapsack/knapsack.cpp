#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};

int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=size;j++){
            if (weights[i-1]<=j){
                matrix[i][j] = max(matrix[i-1][j],1+matrix[i-1][j-weights[i-1]]);
            }
            else{
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

int main(){
    int nItems = 4;
    int knapsackSize = 4;
    int weights[4] = {3,1,2,1};
    int values[4] = {10,40,30,50};
    int i,j;

    printf("Max value = %d\n",knapsack(nItems,knapsackSize,weights,values));

    return 0;
}