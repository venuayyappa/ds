#include <stdio.h>
typedef struct {
    int s1[100];
    int s2[100];
    int cnt1;
    int cnt2;
} MyQueue;
MyQueue* myQueueCreate() {
    MyQueue* que = malloc(sizeof(MyQueue));
    que->cnt1 = 0;
    que->cnt2 = 0;
    return que;
}
void myQueuePush(MyQueue* obj, int x) { obj->s1[obj->cnt1++] = x; }
int myQueuePop(MyQueue* obj) {
    if (obj->cnt1 == 0 && obj->cnt2 == 0)
        return -1;
    if (obj->cnt2 == 0) {
        while (obj->cnt1 > 0) {
            obj->s2[obj->cnt2++] = obj->s1[--obj->cnt1];
        }
    }
    int a = obj->s2[--obj->cnt2];
    return a;
}
int myQueuePeek(MyQueue* obj) {
    if (obj->cnt2 == 0)
        return obj->s1[0];
    return obj->s2[obj->cnt2 - 1];
}
bool myQueueEmpty(MyQueue* obj) {
    if (obj->cnt1 == 0 && obj->cnt2 == 0)
        return true;
    return false;
}
void myQueueFree(MyQueue* obj) { free(obj); }
