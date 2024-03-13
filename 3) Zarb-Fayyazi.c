#include <stdio.h>
#include <string.h>

int zarb_chart[10][10];
// jadval zarb ro 10 dar 10 tarif mikonim ke zarb 0 ro ham dar nazar begire
char num1[200], num2[200];
// in moteghayer haro global tarif mikonim ke be 0 initialize shan
int zarb[300];

// memmove function = baraye hazf alamat va shift dadan baghiye araye ha 
void hazf_plus_minus(char *str){
    if(str[0] == '+' ||  str[0] == '-'){
        memmove(str, str + 1, strlen(str));
    }
}
int check_manfi(char *str){
    if(str[0] == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            scanf("%d", &zarb_chart[i][j]);
        }
    }

    scanf("%s%s", num1, num2);
    if((check_manfi(num1) || check_manfi(num2)) && (!(check_manfi(num1) && check_manfi(num2)))){
        printf("-");
    }
    hazf_plus_minus(num1);
    hazf_plus_minus(num2);

    int len_num1 = strlen(num1);
    int len_num2 = strlen(num2);
    
    for(int i = len_num1 - 1; i >= 0; i--){
        for(int j = len_num2 - 1; j >= 0; j--){
            int X = num1[i] - '0';
            int Y = num2[j] - '0';
            zarb[i + j + 1] = zarb[i + j + 1] + zarb_chart[X][Y];
        }
    }
    for(int i = len_num1 + len_num2 - 1; i >= 0; i--){
        zarb[i] = zarb[i] + zarb[i + 1] / 10;
        zarb[i + 1] = zarb[i + 1] % 10;
    }
    int i = 0;
    while(i < len_num1 + len_num2 && zarb[i] == 0){
        i++; // ye counter ke bebine chand ragham baiad print kone
    }
    

    if(i == len_num1 + len_num2){
        printf("0");
    }
    else{
        for( ; i < len_num1 + len_num2; i++){
            printf("%d", zarb[i]); // print kone v num2a ali
        }
    }

    return 0;
}