/*
 * =====================================================================================
 *
 *       Filename:  tree.h
 *
 *    Description:  binary search tree header file
 *
 *        Version:  1.0
 *        Created:  07/29/2015 03:33:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
typedef int ElementType;

#ifndef _Tree_H
#define _Tree_H 

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif
