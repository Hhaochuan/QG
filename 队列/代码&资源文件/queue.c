#include <stdlib.h>
#include "queue.h"

// 初始化队列
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// 判断队列是否为空
bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// 获取队列大小
int getQueueSize(Queue* queue) {
    return queue->size;
}

// 入队
void enqueue(Queue* queue, void* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// 出队
void* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode* tempNode = queue->front;
    void* data = tempNode->data;
    queue->front = tempNode->next;
    free(tempNode);
    queue->size--;
    if (isQueueEmpty(queue)) {
        queue->rear = NULL;
    }
    return data;
}

// 清空队列
void clearQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

// 销毁队列
void destroyQueue(Queue* queue) {
    clearQueue(queue);
    queue->front = NULL;
    queue->rear = NULL;
}
