/**
* @file functions.c
* @brief This file contains all functions that are used in the main file.
*
* @author © Cocîrlã Cristian-Gabriel
*
* @date 26/05/2018
*/

#include "header.h"

//Function that reads from the file and creates our graph
//@param filename from where we can read the graph onto matrix of adjacence
//@return Void.
void readGraph(const char *filename){

     int i,j;

     fin = fopen( filename, "r" );

     fscanf(fin, "%d %d", &num_vertices, &num_edges);

     for(;num_edges; num_edges--) {

          fscanf(fin, "%d %d",&i,&j);
          mat[i][j] = mat[j][i] = 1;
     }

     fclose( fin );
}

//@fn displayMatrix() used to display the matrix adjacency
//display the matrix adjacency
//@param void
//@return void
void displayMatrix(){

     int i,j;

     for(i=1;i<=num_vertices;i++) {

         for(j=1;j<=num_vertices;j++) {

             printf("%d ", mat[i][j]);
         }
             printf("\n");
     }
}


//check if the graph is odd or not
int have_degree(){

    int sum, i, j, nots = 1;

    for(i = 1; i <= num_vertices; i++) {

        sum = 0;

        for(j = 1; j <= num_vertices; j++) {

            sum += mat[i][j];
        }

        if(sum & 1) nots = 0;

        if(!nots) return nots;
    }
    return nots;
}

//checks whether the graph is connected or not
int connex() {
    int i;

    dfs(1);

    for(i=1;i<=num_vertices;i++)

        if(!visited[i])

            return 0;

    return 1;
}

//Depth First Search Traversal for our Graph
void dfs(int node){

     int j;

     visited[ node ] = 1;

     for(j = 1; j <= num_vertices; j++) {

         if(mat[ node ][ j ]) {

                if(!visited[ j ]) {

                    dfs( j );
                }
         }
     }
}


//Function that adds to our struct if the graph respects the parity
int add(){

    int node, i, found = 0;

    struct Node *ind;

    ind = head;

    while(ind && !found) {

          for(i = 1; i <= num_vertices; i++) {

              if(mat[ind->info][ i ] == 1) found = 1;
          }

          if( !found ) ind = ind->next;
    }


    if( ind ){

       cycle( ind );

       return 1;
    }

    return 0;
};


//Function that cycles the structure
void cycle(struct Node *p){

     struct Node *newnode, *nextnode, *basenode;

     int node;

     basenode = p;
     nextnode = p->next;

     do{
     node = 1;

     while(mat[ basenode->info ][ node ] == 0) node++;

     mat[basenode->info][ node ] = 0;
     mat[ node ][ basenode->info ] = 0;

     newnode = (struct Node*)malloc(sizeof(struct Node));
     newnode->info = node;
     newnode->next = NULL;

     basenode->next = newnode;
     basenode = newnode;
     }while(newnode->info != p->info);

     basenode->next = nextnode;
};

//Function that adds a number to our graph
void addNumber(int vertice, int edge){
    num_vertices++;
    mat[vertice][edge] = mat[edge][vertice] = 1;
}
