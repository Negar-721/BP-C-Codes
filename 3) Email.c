 #include <stdio.h>
#include <string.h>
// in function baraye inke 2 ta _ ya - ya . kenare ham nabashan.
int check2(char letter){
    return letter == '_' || letter == '-' || letter == '.';
}

// biad az index @ be baad chack knoe shart ro baraye harf ha va charecter haye - _ .
int second_part_check(char email[], int len_email, int j){
    int cnt_dot = 0;
    for(int i = j + 1; i < len_email; i++){
        if((email[i] <= 'z' && email[i] >= 'a') || check2(email[i])){
            if(check2(email[i])){
                if(check2(email[i - 1]) || i == j + 1){
                    printf("No");
                    return 0;
                }
            }
            if(email[i] == '.'){
                cnt_dot += 1;
            }
        }
        else{
            printf("No");
            return 0;
        }
        
    }
    if(cnt_dot == 0){
        printf("No");
        return 0;
    }
    else{
        printf("Yes");
    }
}

// in function beraye in ke _ va . kenare ham nabashan
int check1(char letter) {
    return letter == '_' || letter == '.';
}
// baraye ghabl as @ biad check kone ke 2 ta _ ya . kenare ham nabashan va inke harf ha kochik ya capital bashan.
int first_part_check(char email[], int len_email){
    if(email[0] >= '0' && email[0] <= '9' || check1(email[0])){
        printf("No");
        return 0;
    }
    int i = 0;
    //shart while mishe vaghti be @ resid bas kone
    while(email[i] != '@'){
        if((email[i] <= 'z' && email[i] >= 'a') || (email[i] <= 'Z' && email[i] >= 'A') || (email[i] >= '0' && email[i] <= '9') || check1(email[i])){
            if(check1(email[i])){
                if(check1(email[i + 1])){
                    printf("No");
                    return 0;
                }
            }
        }
        else{
            printf("No");
            return 0;
        }
        i++;
    }
    // parameter i index @ ro barmigardone ke index ro midim be funtion second_part_check
    second_part_check(email, len_email, i);
}
// function at_check baraye in ke motmaen bashim hatman 1 @ dar emial hast.
int at_check(char email[], int len_email){
    int cnt_at = 0;
    for(int i = 0; i < len_email; i++){
        if(email[i] == '@'){
            cnt_at = cnt_at + 1;
        }
    }
    if(cnt_at == 1){
        first_part_check(email, len_email);
    }
    else{
        printf("No");
        return 0;
    }
}

int main(){
    char email[2000];
    scanf("%s" , email);
    int len_email = strlen(email);
    at_check(email, len_email);



    return 0;
}
