/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  stack linklist implement header file
 *
 *        Version:  1.0
 *        Created:  07/28/2015 08:47:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int ElementType;

#ifndef _Stack_h
#define _Stack_h 

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif
