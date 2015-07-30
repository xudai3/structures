/*
 * =====================================================================================
 *
 *       Filename:  queuear.h
 *
 *    Description:  queue array implement header file
 *
 *        Version:  1.0
 *        Created:  07/29/2015 12:43:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int ElementType;

#ifndef _Queue_h
#define _Queue_h 

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif
