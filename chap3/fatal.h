/*
 * =====================================================================================
 *
 *       Filename:  fatal.h
 *
 *    Description:  fatal header file
 *
 *        Version:  1.0
 *        Created:  07/28/2015 03:30:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xd (cn), xudai3@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit(1)
