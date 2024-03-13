#include <stdio.h>
#include <stdlib.h>

typedef struct set{
    struct set* prev;
    int num;
    struct set* next;
}set;

set* createNode(int num){
    set* new = (set*)malloc(sizeof(set));
    new -> num = num;
    new -> next = NULL;
    new -> prev = NULL;
    return new;
}
void ascendInsert(set **head, int num){
    set* new = createNode(num);
    if(*head == NULL){
        *head = new;
        return;
    }
    set* curr = *head;
    while(curr->next != NULL){
        curr = curr -> next;
    }
    while(curr != NULL && curr -> num > num){
        curr = curr -> prev;
    }


    if(curr != NULL && curr->num == num){
        free(new);
        return;
    }
    if(curr == NULL){
        new -> next = *head;
        (*head) -> prev = new;
        *head = new;
    }
    else{
        new -> next = curr -> next;
        new -> prev = curr;
        if(curr -> next != NULL){
            curr -> next -> prev = new;
        }
        curr -> next = new;
    }
}

void printAscend(set* head){
    while(head != NULL){
        printf("%d\n" , head -> num);
        head = head -> next;
    }

    free(head);
}
int main(){
    int n, num;
    scanf("%d\n" , &n);
    set* head = NULL;
    for(int i = 0; i < n ; i++){
        scanf("%d" , &num);
        ascendInsert(&head, num);
    }
    printAscend(head);
    return 0;
}