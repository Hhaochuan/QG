#include <stdlib.h>
#include "queue.h"

// ��ʼ������
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// �ж϶����Ƿ�Ϊ��
bool isQueueEmpty(Queue* queue) {
    return queue->size == 0;
}

// ��ȡ���д�С
int getQueueSize(Queue* queue) {
    return queue->size;
}

// ���
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

// ����
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

// ��ն���
void clearQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        dequeue(queue);
    }
}

// ���ٶ���
void destroyQueue(Queue* queue) {
    clearQueue(queue);
    queue->front = NULL;
    queue->rear = NULL;
}
