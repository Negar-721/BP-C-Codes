#include <stdio.h>

 
int is_prime(int a){
    int n=0;
    for(int i = 2; i <=a/2 ; i++){
        if(a % i == 0){
                n++;
        }
    }
    return n;
}
 


int main(){
    int a[1000], m=0,i=0, b=0;
    char k;
    while(1){
        scanf("%d%c" , &a[i], &k);
        if(a[i] == 1){
            continue;
        }
        b = is_prime(a[i]);
        if(b==0){
            m++;
        }
        if(k == '\n'){
            break;
        }
        
        i++;
    }
    printf("%d" , m);
return 0;
}