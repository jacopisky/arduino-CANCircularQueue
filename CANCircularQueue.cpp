
#include "CANCircularQueue.h"

bool initQueue(CANCircularQueue *queue, int capacity) {
    if (capacity > CAN_QUEUE_MAX_SIZE) {
        return false;
    }
    queue->queue = malloc(sizeof(can_frame) * capacity);
    if (!queue->queue) {
        return false;
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    return true;
}

int size(CANCircularQueue *queue) {
	if (queue->rear >= queue->front) {
		return (queue->rear - queue->front);
	}
    return (queue->capacity - queue->front + queue->rear);
}

bool isEmpty(CANCircularQueue *queue) {
    return (size(queue) == 0);
}

bool isFull(CANCircularQueue *queue) {
    return (size(queue) == queue->capacity);
}

bool enqueue(CANCircularQueue *queue, can_frame data) {
    if (isFull(queue)) {
        return false;
    }
    else if (queue->rear == queue->capacity) {
    	queue->rear = 0;
	}
    queue->queue[queue->rear++] = data;
    return true;
}

can_frame dequeue(CANCircularQueue *queue) {
    can_frame data;s
    if (isEmpty(queue)) {
        return data;
    }
	if (queue->front == queue->capacity) {
    	queue->front = 0;
	}
    data = queue->queue[queue->front++];
    return data;
}
