/**
* @file header.h
* @brief Main header of our program where we can find the declaration of our functions.
*
* @author © Cocîrlã Cristian-Gabriel
*
* @date 26/05/2018
*/
#ifndef _EUL_H_
#define _EUL_H_



#include <stdio.h>
#include <malloc.h>
#define MAX 50 /*!< Maximum length of Graph */

struct Node {

       int info;
       struct Node *next;
};

struct Node *head, *ind, *c; /*! Our structure to check if the graph respect the parity */



int mat[MAX][MAX], visited[ MAX ]; /*!< Our array where we will store our graph, and visited nodes*/

int num_vertices, num_edges; /*! Our variables where we store our number of vertices and edges */

FILE *fin, *fout; /*! Stream for reading and outputting to file. */

/*!
 * Heads of our functions
 */
int connex();
int have_degree();
int add();
void readGraph(const char*);
void displayMatrix();
void dfs(int);
void cycle(struct Node *);
void addNumber(int, int);
#endif
