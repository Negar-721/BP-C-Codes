#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int isDelimeter(char string) {
    return (string == '.' || string == '?' || string == '!' || string == ',' || string == ';' || string == ':' || string == '%' || string == '(' || string == ')' || string == '\"' || string == '-');
}

int checkBeforeAndAfter(char *str, int index) {
    return index == 0 || isDelimeter(str[index - 1]) || str[index - 1] == ' ';
}
int isUrlDelimeter(char string) {
    return (string == ' ' ||  string == ',' || string == '(' || string == ')' || string == '\0');
}
void process_int(char *str) {
    int length = strlen(str);
    char *new_str = malloc((length * 5 + 1) * sizeof(char)); // افزایش طول برای جداسازی احتمالی عدد و کلمه
    int i = 0, j = 0;
    bool is_digit = false, is_float = false;

    while (str[i] != '\0') {
        if ((isdigit(str[i]) && (checkBeforeAndAfter(str, i))) || (str[i] == '.' && i + 1 < length && isdigit(str[i + 1]))) {
            is_digit = true;
            is_float = (str[i] == '.');

            while (i < length && (isdigit(str[i]) || (str[i] == '.' && isdigit(str[i + 1])))) {
                if (str[i] == '.' && isdigit(str[i + 1])) {
                    is_float = true;
                }
                i++;
            }

            if (is_digit) {
                // اضافه کردن فضای خالی قبل از عدد در صورت لزوم
                if (j > 0 && new_str[j - 1] != ' ') {
                    new_str[j++] = ' ';
                }

                if (is_float) {
                    strcpy(&new_str[j], "FLOAT");
                    j += strlen("FLOAT");
                } else {
                    strcpy(&new_str[j], "INT");
                    j += strlen("INT");
                }

                // اضافه کردن فضای خالی بعد از عدد در صورت لزوم
                if (str[i] != ' ' && str[i] != '\0') {
                    new_str[j++] = ' ';
                }
            }
            is_digit = false;
            is_float = false;
        } else {
            new_str[j++] = str[i];
            i++;
        }
    }

    new_str[j] = '\0';
    printf("%s", new_str);
    free(new_str);
}

char* process_chars(char *str){
    int length = strlen(str);
    char *new_str = malloc((length * 4 + 1) * sizeof(char));
    int i, j = 0;

    for(i = 0; i < length; i++){
        if(str[i] == ':' || str[i] == ';' || str[i] == '.' && !isdigit(str[i-1]) || str[i] == ',' || str[i] == '?' || str[i] == '!' || str[i] == '(' || str[i] == ')' || str[i] == '%' ||
           str[i] == '"'){
            if(i > 0 && str[i-1] != ' '){
                new_str[j++] = ' ';
            }
            new_str[j++] = str[i];
            if(i < length - 1 && str[i+1] != ' '){
                new_str[j++] = ' ';
            }
        }
        else if(str[i] == '.' && isdigit(str[i-1]) && !isdigit(str[i+1]) && i < length -1){
            if(i > 0 && str[i-1] != ' '){
                new_str[j++] = ' ';
            }
            new_str[j++] = str[i];
            if(i < length - 1 && str[i+1] != ' '){
                new_str[j++] = ' ';
            }
        }
        else if(str[i] == '-'){
            if(isdigit(str[i-1]) && isdigit(str[i+1])){
                if(i > 0 && str[i-1] != ' '){
                    new_str[j++] = ' ';
                }
                new_str[j++] = str[i];
                if(i < length - 1 && str[i+1] != ' '){
                    new_str[j++] = ' ';
                }
                else{
                    new_str[j++] = str[i];
                }
            }
            else{
                new_str[j++] = str[i];
            }
        }
        else{
            new_str[j++] = str[i];
        }
    }

    new_str[j] = '\0';
    process_int(new_str);
}

char* process_link(char *str){
    int length = strlen(str);
    char *new_str = malloc((length * 4 + 1) * sizeof(char));
    int i = 0, j = 0;


    while (str[i] != '\0') {
        if (strncmp(&str[i], "http://", 7) == 0 || strncmp(&str[i], "https://", 8) == 0) {
            strcpy(&new_str[j], "LINK");
            j += strlen("LINK");
            while (i < length && !isUrlDelimeter(str[i]) && str[i] != '\n') {
                i++;
            }
        } else {
            new_str[j++] = str[i];
            i++;
        }
    }
    new_str[j] = '\0';
    process_chars(new_str);
}

int main() {
    char str[5000];
    fgets(str, sizeof(str), stdin);

    process_link(str);
    return 0;
}
