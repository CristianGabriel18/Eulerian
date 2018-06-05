/**
* @file main.c
* @brief Our main file where user can choose options for actions to be performed.
*
* @author © Cocîrlă Cristian-Gabriel
*
* @date 26/05/2018
*/

#include "functions.c"


/**
* Main function from where our user can choose options that will perform certain actions.
*/
int main(){


    int graphRead = 0, decision = 0;
    int vertice, edge;

    while(1){
        printf("\n\n\t- Menu -");
        printf("\n1. Read graph from file \"eulerian.in\"");
        printf("\n2. Display the matrix adjacency of the graph");
        printf("\n3. Add number to graph");
        printf("\n4. Check if graph is a connected graph (DFS)");
        printf("\n5. Check if the graph respects the conditions for parity");
        printf("\n6. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &decision);
        switch(decision){
            case 1:
                if(graphRead)
                    printf("\nGraph has been already read from file. Close the program and try again.");
                else{
                    graphRead = 1;
                    readGraph("eulerian.in");
                    printf("\nGraph has been read from the file.");
                }
                break;
            case 2:
                printf("\nDisplaying matrix adjacency for the graph...\n");
                displayMatrix();
                break;
            case 3:
                printf("\nEnter the number of the vertice: ");
                scanf("%d", &vertice);
                printf("\nEnter the number of the edge: ");
                scanf("%d", &edge);
                addNumber(vertice, edge);
                break;
            case 4:
                printf("\nChecking if the graph is connected...");
                if( connex() ){
                    printf("\nThe graph is a connected graph");
                }
                else{
                    printf("\nGraph is not connected");
                }
                break;
            case 5:
                printf("\nChecking if the graph respects the conditions for parity");
                if( connex() ){

                    if( have_degree() ){

                        printf("\nGraph respects the conditions for parity: ");
                        head = (struct Node*)malloc(sizeof(struct Node));
                        head->info = 1;
                        head->next = 0;

                        while( add() );

                        c = head;
                        while( c ){
                           printf("%d ", c->info);
                           c = c->next;
                        }

                    }
                    else{

                        printf("\nThe Graph does not respect the conditions for parity");

                    }

                }
                else{
                    printf("\nGraph is not connected, condition for parity can't be checked.");
                }
                break;
            case 6:
                return 0;
                break;
            default:
                printf("\nInvalid option, please select a number from 1 to 6.");
                break;
        }
    }

    return 0;
};

