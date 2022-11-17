//
// Created by Sam Q on 17/11/2022.
//

#ifndef MAIN_C_ORDERELEMENTS_H
#define MAIN_C_ORDERELEMENTS_H

typedef struct ListStruct * linkedList;
linkedList creatList();
void printList(linkedList list);
void addInHead(linkedList list, int elem);
void addInTail(linkedList list, int elem);
void addBefore(linkedList list, int elem, int i);
void addAfter(linkedList list, int elem, int i);
void orderInList(linkedList list, int elem);



#endif //MAIN_C_ORDERELEMENTS_H
