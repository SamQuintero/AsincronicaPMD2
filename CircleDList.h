//
// Created by Sam Q on 17/11/2022.
//

#ifndef MAIN_C_CIRCLEDLIST_H
#define MAIN_C_CIRCLEDLIST_H
typedef struct ListStruct *CircleDList;
CircleDList createDList();
void AddToHead(int value, CircleDList dlist);
void AddToTail(int value, CircleDList dlist);
void printDList(CircleDList list);
void addBeforeNode(CircleDList list, int i, int new_value);
void deleteValue(CircleDList list,int i);
void prooveDConection(CircleDList list);
#endif //MAIN_C_CIRCLEDLIST_H
