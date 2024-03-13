#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct NumberMap {
    char *word;
    int number;
};

int findNumber(struct NumberMap *map, int size, char *word) {
    for (int i = 0; i < size; ++i) {
        if (strcmp(map[i].word, word) == 0) {
            return map[i].number;
        }
    }
    return -1;
}

int main() {
    struct NumberMap map[] = {
            {"sefr", 0}, {"yek", 1}, {"do", 2}, {"se" , 3}, {"chahar" , 4}, {"panj" , 5}, {"shesh", 6}, {"haft", 7}, {"hasht", 8}, {"noh", 9}, {"dah", 10}, {"yazdah", 11}, {"davazdah", 12}, {"sizdah", 13},
            {"chahardah", 14}, {"panzdah", 15}, {"shanzdah", 16}, {"hefdah", 17}, {"hejdah", 18}, {"nozdah", 19}, {"bist", 20}, {"si", 30}, {"chehel", 40}, {"panjah", 50}, {"shast", 60}, {"haftad", 70},
            {"hashtad", 80}, {"navad", 90}, {"sad", 100}, {"devist", 200}, {"sisad", 300}, {"chaharsad", 400}, {"pansad", 500}, {"sheshsad", 600}, {"haftsad", 700}, {"hashtsad", 800}, {"nohsad",900},
            {"hezar", 1000}, {"hezar", 1000}
    };
    int mapSize = sizeof(map) / sizeof(map[0]);
    int n;
    scanf("%d\n", &n);

    char line[201];
    for(int i = 0; i < n; i++) {
        int flag = 0;
        fgets(line, 201, stdin);
        line[strcspn(line, "\n")] = 0;

        char *word = strtok(line, " ");
        int total = 0;
        int currentNumber = 0;
        while (word != NULL) {
            if (strcmp(word, "va") == 0) {
                total = total + currentNumber;
                currentNumber = 0;
            } else if (findNumber(map, mapSize, word) == 1000) {
                if(flag == 1){
                    currentNumber = (total + currentNumber) * 1000;
                    total = 0;
                }
                else{
                    currentNumber = currentNumber + 1000;
                }
            } else {
                int number = findNumber(map, mapSize, word);
                if (number >= 0) {
                    currentNumber = currentNumber + number;
                    flag = 1;
                }
            }
            word = strtok(NULL, " ");
        }
        total = total + currentNumber;

        printf("%d\n", total);
    }


    return 0;
}
