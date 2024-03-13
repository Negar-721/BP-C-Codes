#include <stdio.h>
#include <math.h>
int main(){
    int x,y,z;
    scanf("%d %d %d" , &x , &y , &z);
    if(y == 2*sqrt(x)*sqrt(z) ){
        printf("1");
    }
    else{
        if(y == -2*sqrt(x)*sqrt(z)){
        printf("2");
        }
        else{
            if(y == 0 && x*z < 0){
            printf("3");
            }
            else{
            printf("None");
            }
        }
    }

return 0;
}