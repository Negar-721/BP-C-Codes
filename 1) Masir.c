#include <stdio.h>

int main(){
    long long int k, n, t = 0, x=0;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i < n; ++i) {
        long long int d, r, g;
        scanf("%lld%lld%lld", &d, &r, &g);
        t += d - x;
        x = d;
        if (t % (r+g) < r){
            t += r - (t % (r+g));
        }
    }
    t += k-x;
    printf("%lld\n", t);
    return 0;
}