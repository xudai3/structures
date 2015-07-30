/*
 * =====================================================================================
 *
 *       Filename:  stackar.h
 *
 *    Description:  stack array implement header file
 *
 *        Version:  1.0
 *        Created:  07/28/2015 09:33:48 PM
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

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif
