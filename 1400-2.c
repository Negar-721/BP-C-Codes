#include <stdio.h>
#include <math.h>

double ave(int d[], int sh[], int i, int n, int count){
    double sum = 0;
    for(int j = 0 ; j < n; j++){
        if(i==j){
            continue;
        }
        sum += abs(d[i] - d[j])*sh[j];
    }
    return sum / (count - 1);
}



int main(){
    int n;
    scanf("%d" , &n);
    int d[n];
    int sh[n];
    int count = 0;
    for(int i = 0 ; i < n; i++){
        scanf("%d %d" , &d[i], &sh[i]);
        count += sh[i];
    }
    double min_ave = ave(d, sh, 0, n, count);
    int index = 0;
    for(int i = 1 ; i < n ; i++){
        double temp_ave = ave(d, sh, i, n, count);
        if(temp_ave < min_ave){
            min_ave = temp_ave;
            index = i+1;
        }

    }
    printf("%d" , index);
    
return 0;
}