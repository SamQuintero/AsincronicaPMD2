#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"
#include "merch.h"
#include "orderElements.h"
#include "CircleDList.h"
#include "CircleList.h"

int main() {
    printf("\n-----------EJERCICIO 1-----------\n");
    printf("\n\nLISTA SIMPLE\n\n");
    CircleList  Clist = createList();
    printList(Clist);
    addInHeadl(Clist,10);
    addInHeadl(Clist,20);
    addInHeadl(Clist,90);
    addCAfter(Clist,70,2);
    addNode_tail(Clist,55);
    addNode_tail(Clist,60);
    addBeforel(Clist,40,3);
    printListl(Clist);

    prooveConection(Clist);

    printf("\n\nLISTA DOBLE\n\n");
    CircleDList dClist = createDList();
    printDList(dClist);
    addBeforeNode(dClist,3,30);
    AddToHead(50,dClist);
    AddToHead(20,dClist);
    AddToTail(5,dClist);
    addBeforeNode(dClist,2,-20);
    addDAfter(dClist,80,2);
    printDList(dClist);
    prooveDConection(dClist);

    printf("\n-----------EJERCICIO 2-----------\n");
    linkedList list= creatList();
    int elem;
    do{
        printf("Ingrese un numero para agregar a la lista:");
        scanf("%d", &elem);
        orderInList( list, elem);
        printList(list);
    }
    while(elem!=0);

    printf("\n-----------EJERCICIO 3-----------\n");
    LinkedListM Hello = createListM();
    LinkedListM Goodbye = createListM();
    addNode(Hello, 9);
    addNode(Hello, 12);
    addNode(Hello, 14);
    addNode(Hello, 15);
    addNode(Goodbye, 1);
    addNode(Goodbye, 13);
    addNode(Goodbye, 100);

    printListM(Hello);
    printListM(Goodbye);
    LinkedListM sorted = Merge2Sort(Hello, Goodbye);
    printListM(sorted);
}
