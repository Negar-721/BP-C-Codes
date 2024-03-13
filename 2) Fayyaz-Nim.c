#include <stdio.h>

int winner(int n, int m){
    if (n == 0 && m == 0){
        return 0;
    }

    else if(n == 0 && m <= 2){
        return 1;
    }

    else if(m == 0 && n <= 2){
        return 1;
    }

    else if((n > 0) && (winner(n - 1, m) == 0 || winner(n - 2, m) == 0)){
        return 1;
    }

    else if((m > 0) && (winner(n, m - 1) == 0 || winner(n, m - 2) == 0)){
        return 1;
    }

    return 0;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    winner(n, m);

    if(winner(n,m) == 1){
        printf("Fayaz");
    }
    else{
        printf("Armin");
    }

    return 0;
}