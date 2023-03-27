#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

// 队列节点结构体
typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

// 队列结构体
typedef struct Queue {
    QueueNode* front; // 队首指针
    QueueNode* rear; // 队尾指针
    int size; // 队列大小
} Queue;

// 初始化队列
void initQueue(Queue* queue);

// 判断队列是否为空
bool isQueueEmpty(Queue* queue);

// 获取队列大小
int getQueueSize(Queue* queue);

// 入队
void enqueue(Queue* queue, void* data);

// 出队
void* dequeue(Queue* queue);

// 清空队列
void clearQueue(Queue* queue);

// 销毁队列
void destroyQueue(Queue* queue);

#endif // QUEUE_H_INCLUDED
