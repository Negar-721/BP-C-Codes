#include <stdio.h>
#include <stdbool.h>

int WandB(char rang1, char rang2){
    if ((rang1 == 'W' && rang2 == 'B') || (rang1 == 'B' && rang2 == 'W')){
        return 1;
    }
    else{
        return 0;
    }
}

void jaygasht(int n, char rang[3], char tarkib[n], int divar){
    if(divar == n){
        int temp = 1;
        for (int i = 0; i < n - 1; i++){
            if(WandB(tarkib[i], tarkib[i + 1])){
                temp = 0;
                break;
            }
        }
        if(temp){
            for (int i = 0; i < n; i++){
                printf("%c", tarkib[i]);
            }
            printf("\n");
        }
    return;
    }

    for (int i = 0; i < 3; i++){
        tarkib[divar] = rang[i];
        jaygasht(n, rang, tarkib, divar + 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char rang[3] = {'W', 'B', 'R'};
    char tarkib[n];
    jaygasht(n, rang, tarkib, 0);

    return 0;
}