#include <stdio.h>
int main(){
    int x,y,t;
    scanf("%d\n%d" , &x,&y);
    if(x > y){
        t = x;
    }
    else{
        t = y;
    }
    for(int i = 2 ; i <= t -1 ; i++){
        if((y%i)==(x%i)){
            printf("%d\n" , i);
        }
    }

return 0;
}