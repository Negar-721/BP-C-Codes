 #include <stdio.h>
#include <stdlib.h>


typedef struct node{
    long double num;
    struct node *next;
}node;

node* create(long double num){
    node* head = (node*)malloc(sizeof(node));
    if(head == NULL){
        return NULL;
    }
    head -> num = num;
    head -> next = NULL;
    return head;
}

node* insert_the_end(node* head, long double num){
    node* new_node = create(num);
    node *p = head;
    while(p -> next != NULL){
        p = p -> next;
    }
    p -> next = new_node;
    return head;
}
long double calculate_average(node* head, int n){
    long double sum = 0.0;
    while(head != NULL){
        sum += head -> num;
        head = head -> next;
    }
    return sum / n*1.0;
}
node* delete_index(node* head, int index){
    node *p = head;
    node *q = head -> next;
    for(int i = 1 ; i < index - 1; i++){
        p = p -> next;
        q = q -> next;
    }
    p -> next = q -> next;
    printf("%.5Lf\n" , q -> num);

    free(q);
    return head;

}
int main(){
    int n;
    scanf("%d" , &n);
    long double tmp;
    scanf("%Lf" , &tmp);
    node * head = create(tmp);
    for(int i = 1; i < n; i++){
        scanf("%Lf" , &tmp);
        insert_the_end(head, tmp);
    }
    delete_index(head, n/2 + 1);
    printf("%.5Lf", calculate_average(head, n-1));
return 0;
}