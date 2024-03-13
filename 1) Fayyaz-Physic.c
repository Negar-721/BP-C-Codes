#include <stdio.h>
#include <math.h>
int main(){
    int n, q;
    scanf("%d %d" , &n , &q);
    int zarib[n];
    for(int i = 0; i <= n; i++){
        scanf("%d" , &zarib[i]);
    }
    for(int i = 0; i < q; i++){
        int time;
        scanf("%d" , &time);
        long long sum = 0;
        for(int j = 0; j < n; j++){
            sum += (n - j) * (zarib[n - j] * pow(time, n - j - 1));
            
        }
        printf("%lld " , sum);
    }
     

return 0;
}