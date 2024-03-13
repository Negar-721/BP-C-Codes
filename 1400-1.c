#include <stdio.h>

int check(int x, int z){
    if(x == z){
        printf("1");
    }
    else{
        printf("0");
    }
}

int main(){
    int n;
    scanf("%d\n" , &n);
    char par[n];
    for(int i = 0 ; i < n; i++){
        scanf("%c" , &par[i]);
    }
    int z = 0, x = 0;
    for(int i = 0 ; i < n ; i++){
        if(par[0]==par[n-1]){
            printf("0");
            break;
        }
        else{
            if(par[i]==')'){
                z++;
            }
            else if(par[i]=='('){
                x++;
            }
        }
        if(i == n-1){
            check(x,z);
        }
    }
    
    // int flag = 0;
    // for(int i = 0 ; i < n/2; i++){
    //     if(par[i] != 1 + par[n-i] || par[i]+1 != par[n-i]){
    //         flag = 0;
    //         break;
    //     }
    //     else{
    //         flag = 1;
    //     }
    // }
    // if(flag == 0){
    //     printf("0");
    // }
    // else{
    //     printf("1");
    // }
return 0;
}