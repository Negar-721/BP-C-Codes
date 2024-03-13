#include <stdio.h>
#include <math.h>
 
float ghabolii(int n,int T, int A[], int t[], int p[]){
    float res = 0.0;  
    int w = 0;    
    int z = 0;
    float arr[100] = {0};  

    for(int zir_majmooe = 0; zir_majmooe < ((pow(2, n))); zir_majmooe++){
        int time = 0;
        int nomre = 0;
        double ghaboli = 1.0;
        for(int i = 0; i < n; i++){
            if((zir_majmooe & (1 << i)) > 0){
                if(p[i] != 0){
                    time = time + t[i];
                    nomre = nomre + A[i];
                    ghaboli = ghaboli * (p[i] / 100.0);
                }
                else{
                   ghaboli *= (1 - p[i] / 100.0);
                }
            }
            else{
                continue;
            }
        }
        if((time <= T) && (nomre >= 10)){
            arr[w] = ghaboli;
            w = w + 1;
        }
    }
    int k = w;             
    for(int i = 0; i < k; i++){
        if(arr[i] > res){
            res = arr[i];
        }
    }

    return res;
}
int main(){
    int n, T;
    scanf("%d %d\n", &n, &T);
    int A[n], t[n], p[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]); 
    }

    printf("%f", ghabolii(n, T, A, t, p));
    return 0;
}