  #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>

 int check(char word[], char name[]){
    int len_name = strlen(name);
    int len_word = strlen(word);

    for(int i = 0, j = 0 ; i < len_name; i++){
        if(name[i] == word[j]){
            if(len_name == len_word){
                if(j == len_name - 1){
                    return 1;
                }
                j = j + 1;
            }
            else{
                j = j + 1;
                if(j == len_name - 1){
                    return 1;
                }
            }

        }
        else{
            continue;
        }
        
    }
    return 0;
 }

 int main(){
    char name[200];
    scanf("%s" , name);
    int n, cnt = 0;
    scanf("%d" , &n);
    char word[200];
    for(int i = 0; i < n; i++){
        scanf("%s" , word);
        if(strlen(name) < strlen(word) || strlen(name) - strlen(word) > 1){
            continue;
        }
        cnt += check(word, name);
    }
    
        printf("%d " , cnt);
    
 return 0;
 }