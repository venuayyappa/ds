#include <stdbool.h>
#include <stdlib.h>

typedef struct StackItemBase {
    int value;
    struct StackItemBase* nextItemPtr;
} StackItem;

typedef struct {
    StackItem* head;
} MyStack;

MyStack* myStackCreate() {
    MyStack* newStack = (MyStack*)malloc(sizeof(MyStack));
    newStack->head = NULL;
    return newStack;
}

void myStackPush(MyStack* obj, int x) {
    StackItem* newHead = (StackItem*)malloc(sizeof(StackItem));
    newHead->value = x;
    newHead->nextItemPtr = obj->head;
    obj->head = newHead;
}

int myStackPop(MyStack* obj) {
    int result  = obj->head->value;
    StackItem* newHead = obj->head->nextItemPtr;
    free(obj->head);
    obj->head = newHead;
    return result;
}

int myStackTop(MyStack* obj) {
    return obj->head->value;
}

bool myStackEmpty(MyStack* obj) {
    return obj->head == NULL;
}

void myStackFree(MyStack* obj) {
    while (obj->head != NULL) {
        StackItem* newHead = obj->head->nextItemPtr;
        free(obj->head);
        obj->head = newHead;
    }
    free(obj);
}
