//
// Created by Sam Q on 17/11/2022.
//

#ifndef MAIN_C_CIRCLELIST_H
#define MAIN_C_CIRCLELIST_H
typedef struct ListStruct *CircleList;
CircleList createList();
void printListl(CircleList list);
void addInHeadl(CircleList list, int elem );
void addNode_tail(CircleList list, int value);
void addBeforel(CircleList list, int value, int i);
void addCAfter(CircleList list, int elem, int i);
void prooveConection(CircleList list);

#endif //MAIN_C_CIRCLELIST_H
