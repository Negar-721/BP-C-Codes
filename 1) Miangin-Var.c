#include <stdio.h>
#include <math.h>
int main(){
    int n;
    double average, c, sum2 = 0, var, sum1 = 0;
    scanf("%d" , &n);
    float arr[n];
    for(int i = 0 ; i < n ; i++){
        scanf("%f" , &arr[i]);
        sum1 += arr[i];
        average = sum1/n;
    }
    for(int i = 0 ; i < n ; i++){
        c = pow((arr[i] - average) , 2);
        sum2 += c;
        var = sum2/n;
    }
    
    printf("%.3lf\n%.3lf" , average , sqrt(var));


return 0;
}
