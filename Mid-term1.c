#include <stdio.h>
int fac(int dig){
    if(dig==0 || dig == 1){
        return 1;
    }
    else{
        return dig*fac(dig-1);
    }
} 

int digit(int i){
    int cnt=0;
   int t = i ;
   int m = t;
    while(i !=0){
        i = i/10;
        cnt = cnt + 1;
    }
    int dig[cnt];
    int sum= 0;
    for(int j = 0 ; t != 0; j++){
        dig[j] = t%10;
        sum += fac(dig[j]);
        t = t/10;
    }
    if(m == sum){
        
        return m;
    }
    else{
        return 0;
    }
}


 
int main(){
    int n;
    scanf("%d" , &n);
    int sum = 0;
    for(int i = 1; i < n; i++){
        sum += digit(i);
    }
    printf("%d" , sum);

return 0;
}