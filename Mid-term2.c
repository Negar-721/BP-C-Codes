#include <stdio.h>

void sort(int L, int R, int x, int arr[]){
    int arr1[1000];
     
    int min1 = arr1[R-L];
    int index = 0;
     for(int i = L ; i <= R; i++){
        arr1[i]= arr[i];
     }
    for(int i = 0 ; i <= 100; i++){
            
        for(int j = L ; j < R; j++){
            if(arr1[j] > arr1[j+1]){
                int t = arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1] = t;
            }
        }
    }
    printf("%d\n", arr1[x+L-1]);
}
int main(){
    int n,q,L,R,x;
    scanf("%d %d\n" , &n, &q);
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d ", &arr[i]);
    }
    //char c1,c2,c3,c4;
    for(int j = 0; j < q ; j++){
        scanf(" (%d,%d,%d)" ,&L,&R,&x);
        sort(L,R,x,arr);
    }

return 0;
}