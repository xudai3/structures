/*
 * =====================================================================================
 *
 *       Filename:  stackar.c
 *
 *    Description:  stack array implement file
 *
 *        Version:  1.0
 *        Created:  07/28/2015 09:49:10 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "stackar.h"
#include "fatal.h"

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
    return S->TopOfStack == S->Capacity - 1;
}

Stack CreateStack(int MaxElements)
{
    Stack S;

    if(MaxElements < MinStackSize)
        Error("Stack size is too small");

    S = malloc(sizeof(struct StackRecord));
    if(S == NULL)
        FatalError("Out of space!!!");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if(S->Array == NULL)
        FatalError("Out of space!!!");
    S->Capacity = MaxElements;
    MakeEmpty(S);

    return S;
}

void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}

void DisposeStack(Stack S)
{
    if(S != NULL){
        free(S->Array);
        free(S);
    }
}

void Push(ElementType X, Stack S)
{
    if(IsFull(S))
        Error("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    Error("Empty Stack");
    return 0;
}

void Pop(Stack S)
{
    if(IsEmpty(S))
        Error("Empty Stack");
    else
        S->TopOfStack--;
}

ElementType TopAndPop(Stack S)
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    Error("Empty Stack");
    return 0;
}
