/*
 * =====================================================================================
 *
 *       Filename:  stackli.c
 *
 *    Description:  stack linklist implement
 *
 *        Version:  1.0
 *        Created:  07/28/2015 09:04:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include "stackli.h"
#include "fatal.h"

struct Node {
    ElementType Element;
    PtrToNode   Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;

    S = malloc(sizeof(struct Node));
    if(S == NULL)
        FatalError("Out of space!!!");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
        Error("Must use Create first");
    else
        while(!IsEmpty(S))
            Pop(S);
}

void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
        FatalError("Out of space!!!");
    else{
        TmpCell->ElementType = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if(!IsEmpty(S))
        return S->Next->ElementType;
    Error("Empty Stack!");
    return 0;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;

    if(IsEmpty(S))
        Error("Empty Stack!");
    else{
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}
