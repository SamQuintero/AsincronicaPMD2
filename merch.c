//
// Created by Sam Q on 16/11/2022.
//
#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include "merch.h"

typedef struct NodeStruct{
    int value;
    struct NodeStruct *next;
}Node;

struct ListStruct{
    Node *head;
    Node *tail;
    int size;
};

LinkedListM  createListM(){
    LinkedListM new_list = malloc(sizeof(struct ListStruct));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

void printListM(LinkedListM list){
    if(list->size == 0){
        printf("Empty List\n");
    }
    else{
        printf("List size: %i\n",list->size);
        Node *current = list->head;
        while(current!=NULL){
            printf("%d\t",current->value);
            current = current->next;
        }
    }
    printf("\n");
}
void addNode(LinkedListM list, int value){
    if(list->head==NULL){
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->next = NULL;
        list->head=new_node;
        list->size++;
        list->tail=new_node;
    }
    else{
        Node *new_node = (Node*)malloc(sizeof(Node));
        new_node->value = value;
        new_node->next = NULL;
        list->tail->next=new_node;
        list->tail=new_node;
        list->size++;
    }
}

LinkedListM Merge2Sort(LinkedListM list1, LinkedListM list2) {
    if (list1->size == 0 && list2->size == 0) {
        return createListM();
    };
    if(list1->size==0){
        return list2;
    }
    if(list2->size==0){
        return list1;
    }
    Node *list1Head = list1->head;
    Node *list2Head = list2->head;
    Node *cur;
    Node *dummy = cur;
    while(list1Head!=NULL || list2Head!=NULL){
        if(list1Head==NULL){
            cur->next=list2Head;
            cur=cur->next;
            list2Head=list2Head->next;
            continue;
        }
        else if(list2Head==NULL){
            cur->next=list1Head;
            cur=cur->next;
            list1Head=list1Head->next;
            continue;
        }
        if(list1Head->value<list2Head->value){
            cur->next=list1Head;
            cur=cur->next;
            list1Head=list1Head->next;
            continue;
        }
        if(list1Head->value>list2Head->value){
            cur->next=list2Head;
            cur=cur->next;
            list2Head=list2Head->next;
            continue;
        }
        if(list1Head->value==list2Head->value){
            cur->next=list1Head;
            cur=cur->next;
            list1Head=list1Head->next;
            continue;
        }

    }
    LinkedListM sorted = createListM();
    dummy = dummy->next;
    addNode(sorted, dummy->value);
    if(sorted->head!=NULL){
        sorted->size=1;
    }
    dummy=dummy->next;
    while(dummy!=NULL){
        addNode(sorted, dummy->value);
        dummy=dummy->next;
        sorted->size++;
    }
    return sorted;
}