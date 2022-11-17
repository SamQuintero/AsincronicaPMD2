//
// Created by Sam Q on 17/11/2022.

#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"

#include "orderElements.h"
typedef struct NodeStructO{
    int value;
    struct NodeStruct * next;
}Node;

struct ListStruct{
    Node * head;
    Node *tail;
    int size;
};

linkedList creatList(){
    linkedList newList=malloc(sizeof(struct ListStruct));
    newList->head=NULL;
    newList->tail=NULL;
    newList->size=0;
    return newList;
}
void printList(linkedList list){
    if (list->size==0){
        printf("Empty List\n");

    }
    else{
        Node * current=list->head;
        while(current!=NULL){
            printf("%d ",current->value);
            current=current->next;

        }
        printf("\n");
    }
}
void addInHead(linkedList list, int elem ){
    if (list->size==0){
        Node * newhead=malloc(sizeof(Node));
        newhead->value=elem;
        newhead->next=NULL;
        list->head=newhead;
        list->tail=newhead;
        list->size++;

    }
    else{
        Node * newhead=malloc(sizeof(Node));
        newhead->value=elem;
        newhead->next=list->head;
        list->head=newhead;
        list->size++;
    }
}
void addInTail(linkedList list, int elem)
{
    Node * newhead=malloc(sizeof(Node));
    newhead->value=elem;
    newhead->next=NULL;

    if (list->size==0){
        list->head=newhead;
    }
    else{
        list->tail->next = newhead;

    }
    list->tail=newhead;
    list->size++;

}


void addBefore(linkedList list, int elem, int i){

    if (i > list->size || i< 0){
        printf("Valor de indece no permitido");

    }
    else {
        if (i==0){
            addInHead(list, elem);
            return;

        }
        if (i==list->size){
            addInTail(list, elem);
            return;
        }
        Node* current=list->head;
        Node * newNode=malloc(sizeof(Node));
        for(int j=0; j< i-1;j++){
            current=current->next;
        }
        newNode->value=elem;
        newNode->next=current->next;
        current->next=newNode;
    }

}
void addAfter(linkedList list, int elem, int i){
    if (i > list->size || i< 0){
        printf("Valor de indece no permitido");
        return;
    }
    if (i==list->size){
        addInTail(list, elem);
        return;
    }
    Node* current=list->head;
    Node * newNode=malloc(sizeof(Node));
    for(int j=0; j< i;j++){
        current=current->next;
    }
    newNode->value=elem;
    newNode->next=current->next;
    current->next=newNode;

}
void orderInList(linkedList list, int elem){

    Node * current=list->head;
    if(list->size==0){
        addInHead(list, elem);
        return;
    }
    if(list->tail->value< elem){
        addInTail(list, elem);
        return;
    }
    int i=0;
    while(current->value < elem){
        current=current->next;
        i++;

    }
    addBefore(list, elem, i);
}
