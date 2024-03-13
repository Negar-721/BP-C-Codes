#include <stdio.h>
#include <stdlib.h>

void merge(int* arr1 ,int n1, int* arr2, int n2, int* merged);

int main(){
    int n1,n2;
    scanf("%d\n" , &n1);
    // printf("\n");
    int* arr1 = malloc(n1 * sizeof(int));
    for(int i = 0 ; i < n1 ; i++){
        scanf("%d " , &(arr1[i]));
    }
    for(int i = 0 ; i < n1-1 ; i++){
            if(arr1[i] <= arr1[i+1]){
                continue;
            }
            else{
                printf("Not sorted\n");
                return -1;
            }
        }
    scanf("%d" , &n2);
    // printf("\n");
    int* arr2 = malloc(n2 * sizeof(int));
    for(int i = 0 ; i < n2 ; i++){
        scanf("%d" , &(arr2[i]));
    }
    for(int i = 0 ; i < n2-1 ; i++){
            if(arr2[i] <= arr2[i+1]){
                continue;
            }
            else{
                printf("Not sorted\n");
                return -1;
            }
        }
     int* merged = malloc((n1+n2) * sizeof(int));
     merge(arr1, n1, arr2, n2, merged);
     for(int i = 0 ; i < n1 + n2 ; i++){
        printf("%d\n" , merged[i]); 
     }
     return 0;
}
void merge(int* arr1 ,int n1, int* arr2, int n2, int* merged){
    int i, j, k;
    j = k = 0;
    for(i = 0 ; i < n1 + n2 ; ){
        if(j < n1 && k < n2){
            if(arr1[j] < arr2[k]){
                merged[i] = arr1[j];
                j++; 
            }
            else{
                merged[i] = arr2[k];
                k++;
            }
            i++;
        }
        else if(j == n1){
            while(i < n1 + n2){
                merged[i] = arr2[k];
            i++;
            k++;
            }
        }
        else if(k == n2){
            for( ; i < n1 + n2 ; ){
                merged[i] = arr1[j];
            i++;
            j++;
            }
        }
    }
}