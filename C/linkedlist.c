#include <stdio.h> 

typedef struct Node{
    int item;
    struct Node *next;
} node_t;

typedef struct List{
    node_t *head;
    node_t *tail;
} list_t;

list_t new(void){
    list_t list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}

int length(list_t *list){
    node_t *node;
    int count;
    for ( node = list->head; node!=NULL; node = node->next){
        ++count;
    }
    return count;
}

int empty(list_t *list){
    /* return true if the list contains no items*/
    return list->head == NULL;
}

int contains(list_t *list, int item){
    node_t *node = list->head; /* node pointer points to head of list*/
    while(node!=NULL){ /* while node does not equal null*/
        if(node->item == item){ /* if node item is equal to item return true*/
            return 1;
        }
        node = node->next;  /* increment node */
    }
    return 0;
}

int pop(list_t *list){

}

void clear(list_t *list){
    while(!empty(list)){
        pop(list);
    }
}

void push(list_t *list, int item){

}

void append(list_t *list, int item){

}

void remove(list_t *list, int item){

}

int main(void){
    
}