/*
 * =====================================================================================
 *
 *       Filename:  avltree.h
 *
 *    Description:  avl tree header file
 *
 *        Version:  1.0
 *        Created:  07/30/2015 10:03:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int ElementType;

#ifndef _AvlTree_H
#define _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

#endif
