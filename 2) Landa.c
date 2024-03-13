#include <stdio.h>

double landa(int n){
    double l=0;
        if(n % 2 == 0){
            for(double i = 2 ; i <= n ; i += 2.0){
                l += (double)i/(double)(i-1.0) + (double)i/(double)(i+1.0);
            }
        }
        else{
            for(int i = 2 ; i <= n-1 ; i += 2){
                l += (double)i/(double)(i-1.0) + (double)i/(double)(i+1.0);
            }
            l = l + (double)(n+1.0)/(double)n;
        }
        return l;
}
int main(){
    int n;
    scanf("%d" , &n);
    if(n < 5 || n > 55){
        printf("-100");
    }
    else{
        landa(n);
        printf("%lf", 2 * landa(n));
    }
    return 0;
}