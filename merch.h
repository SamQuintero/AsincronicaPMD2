//
// Created by Sam Q on 16/11/2022.
//

#ifndef MAIN_C_MERCH_H
#define MAIN_C_MERCH_H

typedef struct ListStruct * LinkedListM;
LinkedListM  createListM();
void printListM(LinkedListM list);
void addNode(LinkedListM list, int value);
LinkedListM Merge2Sort(LinkedListM list1, LinkedListM list2);

#endif //MAIN_C_MERCH_H
