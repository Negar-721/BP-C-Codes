#include <stdio.h>

int search_alive(int x, int y, int alive[][6], int n_alive){
    for(int i = 0; i < n_alive; i++){
        if(alive[i][2] == x && alive[i][3] == y){
            return i;
        }
    }
    return -1;
}
int search_weapon(int weap[][3], int gun_id, int n_weap){
    for(int i = 0; i < n_weap; i++){
        if(weap[i][1] == gun_id){
            return i;
        }
    }
    return -1;
}
int calculate(int alive[][6], int n_alive, int r, int c){
    int sum = 0;
    for(int i = 0 ; i < n_alive; i++){
        if(alive[i][2] >= 0 && alive[i][2] < r && alive[i][3] >= 0 && alive[i][3] < c && alive[i][5] == 1 && alive[i][4] > 0){
            sum += alive[i][4];
        }
    }
    return sum;
}
int print(int alive[][6], int n_alive, int r, int c){
    for(int i = 0 ; i < n_alive; i++){
        if(alive[i][2] >= 0 && alive[i][2] < r && alive[i][3] >= 0 && alive[i][3] < c && alive[i][5] != 0 && alive[i][4] > 0){
            printf("%d(%d)\n" , alive[i][1] , alive[i][4]);
        }

    }
}
int main(){
    int r, c , n_alive;
    scanf("%d %d" , &r, &c);
    scanf("%d" , &n_alive);
    // 0 = kind, 1 = id, 2 = x, 3 = y , 4 = worth, 5 = dead or alive;
    int alive[n_alive][6];
    for(int i = 0; i < n_alive; i++){
        char kind;
        scanf(" %c" , &kind);
        alive[i][0] = kind;
        scanf("%d ", &alive[i][1]);
        scanf("(%d,%d) ", &alive[i][2], &alive[i][3]);
        scanf("%d" , &alive[i][4]);
        alive[i][5] = 1;
    }
    int n_weap;
    scanf("%d" , &n_weap);
    int weap[n_weap][3];
    for(int i = 0; i < n_weap; i++){
        char kind;
        scanf(" %c" , &kind);
        weap[i][0] = kind;
        scanf("%d ", &weap[i][1]);
        scanf("%d" , &weap[i][2]);
    }
    int n_command;
    scanf("%d" , &n_command);
    for(int i = 0; i < n_command ; i++){
        char command;
        scanf(" %c" , &command);
        if(command == 'S'){
            int gun_id, x, y;
            scanf("%d (%d,%d)" , &gun_id, &x, &y);
            int index_gun = search_weapon(weap, gun_id, n_weap);
            if(index_gun >= 0){
                if(weap[index_gun][2] > 0){
                    weap[index_gun][2] -= 1;
                    int index_alive = search_alive(x , y , alive, n_alive);
                    if(index_alive >= 0){
                        if(weap[index_gun][0] == 'M' || weap[index_gun][0] == 'G' && alive[index_alive][0] == 'S'){
                            alive[index_alive][5] = 0;
                        }
                    }
                }
            }
        }
        else if(command == 'C'){
            printf("%d\n" , calculate(alive, n_alive, r, c));

        }
        else if(command == 'P'){
            print(alive, n_alive, r, c);
        }
    }








return 0;
}