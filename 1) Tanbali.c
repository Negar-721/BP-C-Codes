#include <stdio.h>
int main(){
    int max1=0 , max2=0 , max3 = 0 , x;
    int n;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &x);
        if(x >= max1){
            max3 = max2;
            max2 = max1;
            max1 = x;
        }
        else if(x >= max2){
            max3 = max2;
            max2 = x;
        }
        else if(x >= max3){
            max3 = x;
        }
    }
    printf("%d" , max3);


return 0;
}