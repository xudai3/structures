/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  list header
 *
 *        Version:  1.0
 *        Created:  07/27/2015 09:53:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _List_H
#define _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PrtToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif
