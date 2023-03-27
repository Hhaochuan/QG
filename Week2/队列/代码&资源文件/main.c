#include <stdio.h>
#include "queue.h"

int main() {
    Queue queue;
    initQueue(&queue);

    int data1 = 10;
    char data2 = 'a';
    double data3 = 2.5;

    enqueue(&queue, &data1);
    enqueue(&queue, &data2);
    enqueue(&queue, &data3);

    while (!isQueueEmpty(&queue)) {
        void* data = dequeue(&queue);
        if (data != NULL) {
            if (sizeof(data) == sizeof(int)) {
                printf("%d ", *(int*)data);
            }
            else if (sizeof(data) == sizeof(char)) {
                printf("%c ", *(char*)data);
            }
            else if (sizeof(data) == sizeof(double)) {
                printf("%.1f ", *(double*)data);
            }
        }
    }
    printf("\n");

    destroyQueue(&queue);

    return 0;
}
