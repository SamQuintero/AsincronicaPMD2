//
// Created by Sam Q on 17/11/2022.
//

#include "CircleList.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct NodeStruct{
    int value;
    struct NodeStruct *next;
}Node1;

struct ListStruct{
    Node1 *head;
    Node1 *tail;
    int size;
};

CircleList createList(){
    CircleList new_list = malloc(sizeof(struct ListStruct));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void printListl(CircleList list){
    if(list->size == 0){
        printf("Empty List\n");
    }
    else{
        printf("List size: %i\n",list->size);
        Node1 *current = list->head;
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
void addInHeadl(CircleList list, int elem ){
    printf("Add in head: %d\n",elem );
    if (list->size==0){
        Node1 * newhead=malloc(sizeof(Node1));
        newhead->value=elem;
        newhead->next=list->head;
        list->head=newhead;
        list->tail=newhead;
        list->size++;

    }
    else{
        Node1 * newhead=malloc(sizeof(Node1));
        newhead->value=elem;
        newhead->next=list->head;
        list->head=newhead;
        list->size++;
    }
}

void addNode_tail(CircleList list, int value){
     printf("Add at tail: %d\n",value);
    Node1 *new_node = (Node1*)malloc(sizeof(Node1));
    new_node->value = value;
    new_node->next = list->head;
    if(list->head == NULL){
        list->head = new_node;
    }
    else{
        list->tail->next = new_node;
    }
    list->tail = new_node;
    list->size++;
}
void addBeforel(CircleList list, int value, int i){
    printf("Add %d before %d\n",value, i);
    if(i > list->size){
        printf("Valor no permitido\n");
        return;
    }
    else if(i == list->size){
        addNode_tail(list,value);
        return;
    }
    else if(i == 0){
        addInHeadl(list,value);
        return;
    }
    Node1 *current = list->head;
    for(int j=0; j < i-1; j++){
        current = current->next;
    }
    Node1 *new_node = (Node1*)malloc(sizeof(Node1));
    new_node -> value = value;
    new_node -> next = current -> next;
    current -> next = new_node;
    list -> size = list -> size + 1;
}
void addCAfter(CircleList list, int elem, int i){
    if (i > list->size || i< 0){
        printf("Valor de indece no permitido");
        return;
    }
    if (i+1==list->size){
        addNode_tail(list, elem);
        return;
    }
    Node1* current=list->head;
    Node1 * newNode=malloc(sizeof(Node1));
    for(int j=0; j< i;j++){
        current=current->next;
    }
    newNode->value=elem;
    newNode->next=current->next;
    current->next=newNode;
}

void prooveConection(CircleList list){
    printf("El valor de la cabeza es: %d",list->head->value);
    printf("\nEl valor de la cola es: %d",list->tail->value);
    printf("\nEl valor del next de la cola es: %d",list->tail->next->value);
}
