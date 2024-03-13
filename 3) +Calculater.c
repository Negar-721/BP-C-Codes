#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define MAX 10101

// function baraye mohasebe amaliat - va +
long double j(long double adad[], char op[], int n){
	long double ans = adad[0];
	for(int i = 0; i < n; i++){
		if(op[i] == '+'){
            ans += adad[i + 1];
        }
		if(op[i] == '-'){
            ans -= adad[i + 1];
        }
	}
	return ans;
}
// function baraye mohasebe amaliat * va /
long double z(long double adad[], char op[], int n){
	int idx = 0;
	for(int i = 0; i < n; i++){
		if(op[i] == '*'){
			adad[idx] *= adad[i + 1];
		}
		else if(op[i] == '/'){
			adad[idx] /= adad[i + 1];
		}
		else{
            op[idx] = op[i];
            adad[++idx] = adad[i + 1];
	    }
    }
    // seda zadan function j ke bareye mmohasebe + va - boud, bekhater tartib amaliat mibashad.
	return j(adad, op, idx);
}
long double f(char s[], int start, int end, long double g[], long double adad[], char op[], int END[]){
	char s_adad[MAX];
	int idx_adad = 0, idx_op = 0, idx = 0;
	for(int i = start; i <= end; i++){
		if(s[i] >= '0' && s[i] <= '9' || s[i] == '.'){
            s_adad[idx++] = s[i];
        }
        else if(idx){
            s_adad[idx] = '\0';
            adad[idx_adad++] = atof(s_adad);
            idx = 0;
        }
        if(s[i] == '('){
            adad[idx_adad++] = g[i];
            i = END[i];
        }
		if(s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/'){
            op[idx_op++] = s[i];
        }
	}
	if(idx_op == idx_adad){
		adad[0] *= -1;
		idx_op--;
		for(int i = 0; i < idx_op; i++){
            op[i] = op[i + 1];
        }
	}
	return z(adad, op, idx_op); 
}
int main(){
	char s[MAX], op[MAX];
	gets(s);
	int n = strlen(s), a[MAX], idx = 0, i, END[MAX];
	long double g[MAX] = {0}, adad[MAX] = {0};
	for(i = 0; i < n; i++){
        // miad dakheli tarin parantese haro peyda mikone
		if(s[i] == '('){
            a[idx] = i;
            idx++;
        }
		if(s[i] == ')'){
			idx--;
			END[a[idx]] = i;
            // ba anjam amaliat dar har parantese dakheli, be soragh parantes haye bironie baadi mire va on ro be function f mide
			g[a[idx]] = f(s, a[idx] + 1, i, g, adad, op, END);
		}
	}
	long double ans = f(s, 0, n, g, adad, op, END);
	char P[MAX];
	sprintf(P, "%.8Lf", ans);
	n = strlen(P);
	for(i = n - 1; i >= 0 && P[i] == '0'; i--);
	if(P[i] == '.'){
        i--;
    }    
	for(int j = 0; j <= i; j++){
        printf("%c", P[j]);
    }
	return 0;
}