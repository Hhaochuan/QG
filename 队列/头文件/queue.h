#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

// ���нڵ�ṹ��
typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

// ���нṹ��
typedef struct Queue {
    QueueNode* front; // ����ָ��
    QueueNode* rear; // ��βָ��
    int size; // ���д�С
} Queue;

// ��ʼ������
void initQueue(Queue* queue);

// �ж϶����Ƿ�Ϊ��
bool isQueueEmpty(Queue* queue);

// ��ȡ���д�С
int getQueueSize(Queue* queue);

// ���
void enqueue(Queue* queue, void* data);

// ����
void* dequeue(Queue* queue);

// ��ն���
void clearQueue(Queue* queue);

// ���ٶ���
void destroyQueue(Queue* queue);

#endif // QUEUE_H_INCLUDED
