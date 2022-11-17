//
// Created by Sam Q on 17/11/2022.
//

#include "CircleDList.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct NodeStruct{
    int value;
    struct NodeStruct *next;
    struct NodeStruct *prev;
}Node2;

struct ListStruct{
    Node2 *head;
    Node2 *tail;
    int size;
};

CircleDList createDList(){
    CircleDList new_list = malloc(sizeof(struct ListStruct));
    new_list->head = new_list->tail;
    new_list->tail = new_list->head;
    new_list->size = 0;
    return new_list;
}

void AddToHead(int value, CircleDList dlist) {
    Node2 *new_node = malloc(sizeof(Node2));
    new_node->value = value;

    new_node->next = dlist->head;
    new_node->prev = dlist -> tail;
    if(dlist->size>0){
        dlist->head->prev = new_node;
    }
    else{
        dlist->tail = new_node;
    }
    dlist->head = new_node;
    dlist->size += 1;
}

void AddToTail(int value, CircleDList dlist) {
    Node2 *new_node = malloc(sizeof(Node2));
    new_node->value = value;
    new_node->next = dlist -> head;
    dlist->head->prev=new_node;

    new_node->prev = dlist -> tail;


    if (dlist->size == 0) {
        dlist->head = new_node;
    }
    else {
        dlist->tail->next = new_node;
    }
    dlist->tail = new_node;
    dlist->size += 1;

}

void addBeforeNode(CircleDList list, int i, int new_value){
    if(i > list->size || i < 0){
        printf("Node index out of bounds\n");
        return;
    }
    else if(i == list->size){
        AddToTail(new_value,list);
        return;
    }
    else if(i == 0){

        AddToHead(new_value,list);
        return;
    }
    Node2 *current = list -> head;
    for(int j=0; j<i; j++){
        current = current -> next;
    }
    Node2 *new_node = (Node2*)malloc(sizeof(Node2));
    new_node -> value = new_value;
    new_node -> next = current;
    new_node -> prev = current -> prev;
    current -> prev -> next = new_node;
    current -> prev = new_node;
    list -> size = list -> size + 1;
}

void printDList(CircleDList list){
    if(list->size == 0){
        printf("Empty List\n");
    }
    else{
        printf("List size: %i\n",list->size);
        Node2 *current = list->head;
        while(current!=NULL){
            printf("%d\t",current->value);
            if(current == list->tail){
                break;
            }
            current = current->next;
        }
    }
    printf("\n");
}

void prooveDConection(CircleDList list){
    printf("El valor de la cabeza es: %d",list->head->value);
    printf("\nEl previo de la cabeza es: %d",list->head->prev->value);
    printf("\nEl valor de la cola es: %d",list->tail->value);
    printf("\nEl valor del next de la cola es: %d",list->tail->next->value);
    printf("\n:)");
}
