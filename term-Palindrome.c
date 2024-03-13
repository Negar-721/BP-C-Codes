#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int start, int end) {
    if(start >= end){
        return 1;
    }
    if(str[start] != str[end]){
        return 0;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main(){
    char str[100];
    scanf("%s", str);

    if(isPalindrome(str, 0, strlen(str) - 1)) {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}
