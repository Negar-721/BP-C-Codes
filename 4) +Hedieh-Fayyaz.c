#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char alpha;
}node;

typedef struct{
    node* data;
    int size;
    int cursor;
}list;

list* makeList(){
   list* Editor = (list*)malloc(sizeof(list));
   Editor -> data = NULL;
   // aval texte ma hich harfi tosh nist pas size va cursor 0 hastan
   Editor -> size = 0;
   Editor -> cursor = 0; 
   return Editor;
}

void insert(list* Editor, char charecter){
    node* new = (node*)malloc(sizeof(node));
    new -> alpha = charecter;
    Editor -> size++;
    Editor -> data = (node*)realloc(Editor -> data, Editor -> size * sizeof(node)); 
    for(int i = Editor -> size - 1; i > Editor -> cursor; i--){
        Editor -> data[i] = Editor -> data[i-1];
    }
    Editor -> data[Editor -> cursor] = *new;
    free(new);
    Editor -> cursor++;
}

void Delete(list* Editor){
    if(Editor -> cursor > 0){
        for(int i = Editor -> cursor - 1 ; i < Editor -> size - 1; i++){
        Editor -> data[i] = Editor -> data[i+1];
        }
        Editor -> size--;
        Editor -> data = (node*)realloc(Editor -> data, Editor -> size *sizeof(node));
        Editor -> cursor--;
    }
}

void replaceOldNew(list* Editor, char old, char new){
    for(int i = 0; i < Editor -> size; i++){
        if(Editor -> data[i].alpha == old){
            Editor -> data[i].alpha = new;
        }
    }
}
void print(list * Editor){
    for (int i = 0; i < Editor -> size; i++)
    {
        printf("%c", Editor->data[i].alpha);
    }
}
int main(){
    int n;
    scanf("%d" , &n);
    list* Editor = makeList();
    for(int i = 0; i < n; i++){
        char op, c, old, new;
        scanf(" %c", &op);
        switch(op){
        case 'L':
            if(Editor -> cursor > 0){
                Editor -> cursor--;
            }
            else{
                continue;
            }
            break;
        case 'R':
            if(Editor -> cursor < Editor -> size){
                Editor->cursor++;
            }
            else{
                continue;
            }
            break;
        case 'I':
            getchar();
            scanf("%c", &c);
            insert(Editor, c);
            break;
        case 'D':
            if(Editor -> cursor > 0){
                Delete(Editor);
            }
            else{
                continue;
            }
            break;
        case 'C':
            getchar();
            scanf("%c", &old);
            getchar();
            scanf("%c", &new);
            replaceOldNew(Editor, old, new);
            break;
        }
    }

    print(Editor);
    printf("\n");
    free(Editor -> data);
    free(Editor);



return 0;
}