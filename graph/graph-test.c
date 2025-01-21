/*
 * DV1: Datatyper och datastrukturer
 * Fall 23
 * OU7
 *
 * File:         graph-test.c
 * Description:  
 * Author:       Emil Engvall
 * CS username:  ens19esm
 * Date:         2023-12-30
 */

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void depth_first(int n, Graph *g, int visited[]);
void add_random_edges(Graph *g, int num_edges);
void print_neighbours(Graph *g);

int main() 
{
    srand(time(NULL));
    int nr_nodes = 10; 

    // Skapar en tom graf med n noder
    Graph *g = graph_create(nr_nodes);

    // Sätter in några slumpmässigt valda bågar
    add_random_edges(g, 15); 

    // Utför en djupet-först traversering från nod 0
    int visited[nr_nodes];
    for (int i = 0; i < nr_nodes; i++) {
        visited[i] = 0;
    }

    printf("DFS traversering från nod 0:\n");
    depth_first(0, g, visited);
    printf("\n");

    // Skriver ut grannskapslistorna
    printf("Grannskapslistor för varje nod:\n");
    print_neighbours(g);

    // Förstör grafen
    graph_destroy(g);

    return 0;
}

void depth_first(int n, Graph *g, int visited[]) 
{
    // visit(n) - Mark the node n as visited
    printf("%d ", n);
    visited[n] = 1;

    // neighbourSet = neighbours(n, g)
    set *neighbourSet = graph_neighbours(g, n);
    if (neighbourSet != NULL) {
        int *neighbourValues = set_get_values(neighbourSet);

        // for each node v in g
        for (int v = 0; v < graph_no_of_nodes(g); v++) {
            // if v is a member of neighbourSet and not visited
            if (set_member_of(v, neighbourSet) && !visited[v]) {
                // depthFirst(v, g)
                depth_first(v, g, visited);
            }
        }

        free(neighbourValues);
    }
}

void add_random_edges(Graph *g, int num_edges) {
    int num_nodes = graph_no_of_nodes(g);

    for (int i = 0; i < num_edges; i++) {
        int a = rand() % num_nodes;
        int b = rand() % num_nodes;

        if (a != b) {
            graph_insert_edge(g, a, b);
        }
    }
}


void print_neighbours(Graph *g) 
{
    for (int i = 0; i < graph_no_of_nodes(g); i++) {
        set *neighbours = graph_neighbours(g, i);

        printf("Node %d: ", i);
        if (set_size(neighbours) > 0) {
            int *values = set_get_values(neighbours);
            for (int j = 0; j < set_size(neighbours); j++) {
                printf("%d ", values[j]);
            }
            free(values);
        } else {
            printf("-"); // Skriv '-' för noder utan grannar
        }
        printf("\n");
    }
}
