#include <stdio.h>

int fibo(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}

long factoriel(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return factoriel(n-1)*fibo(n);
    }
}

int main(){
    int n;
    scanf("%d" , &n);
    fibo(n);
    factoriel(n);
    printf("%ld" , factoriel(n));


return 0;
}