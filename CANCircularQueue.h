#ifndef CAN_CIRCULAR_QUEUE_H
#define CAN_CIRCULAR_QUEUE_H

#include <Arduino.h>
#include <CAN.h>

#ifndef CAN_QUEUE_MAX_SIZE
	#define CAN_QUEUE_MAX_SIZE 50
#endif

typedef struct {
    can_frame *queue;
    int capacity;
    int front;
    int rear;
} CANCircularQueue;

void initQueue(CANCircularQueue *queue);
int size(CANCircularQueue *queue);
bool isEmpty(CANCircularQueue *queue);
bool isFull(CANCircularQueue *queue);
bool enqueue(CANCircularQueue *queue, can_frame data);
can_frame dequeue(CANCircularQueue *queue);

#endif  // CAN_CIRCULAR_QUEUE_H
