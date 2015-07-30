/*
 * =====================================================================================
 *
 *       Filename:  queuear.c
 *
 *    Description:  queue array implement 
 *
 *        Version:  1.0
 *        Created:  07/29/2015 12:52:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "queuear.h"
#include "fatal.h"

#define MinQueueSize (5)

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q;

    if(MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Q = malloc(sizeof(struct QueueRecord));
    if(Q == NULL)
        FatalError("Out of space!!!");

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if(Q->Array == NULL)
        FatalError("Out of space!!!");
    Q->Capacity = MaxElements;
    MakeEmpty(Q);

    return Q;
}

void DisposeQueue(Queue Q)
{
    if(Q != NULL){
        free(Q->Array);
        free(Q);
    }
}

void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue(ElementType X, Queue Q)
{
    if(IsFull(Q))
        Error("Full Queue");
    else{
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    if(!IsEmpty(Q))
        return Q->Array[Q->Front];
    Error("Empty Queue");
    return 0;
}

void Dequeue(Queue Q)
{
    if(IsEmpty(Q))
        Error("Empty Queue");
    else{
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = 0;

    if(IsEmpty(Q))
        Error("Empty Queue");
    else{
        Q->Size--;
        X = Q->Array[Q->Front];
        Q->Front = Succ(Q->Front, Q);
    }
    return X;
}
