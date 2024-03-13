 #include <stdio.h>

int seq(int x) {
    int a = 1; 
    int current_value = 1;

    while (current_value != x) {
        a++;  
        current_value = current_value + 2 * a; 
        if (current_value > x) {
            return -1;  
        }
    }

    return a;
}

int main() {
    int x;
    scanf("%d", &x);

    int result =seq(x);
    printf("%d" , result);

    return 0;
}