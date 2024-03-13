#include <stdio.h>
int main(){
    int n,d, in_yaghob = 0, sum = 0;
    scanf("%d %d\n" , &n , &d);
    int barghi[n];
    int yaghob[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &barghi[i]);
    }
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &yaghob[i]);
    }
    for(int i = 0; i < n; i++){
        if(barghi[i] <= yaghob[i]){
            sum += barghi[i];
        }
        else{
        in_yaghob = 1;
        sum += yaghob[i];
        }
    } 
    if(in_yaghob==1){
        printf("%d" , sum + d);
    }
    else{
        printf("%d" , sum);
    }
return 0;
}