/**
 * File: graph.c
 * This module is used for managing graph data structures.
 *
 * The module provides functions for creating and manipulating graphs, represented as a set of nodes with edges between them.
 * It includes operations for graph creation, modification, querying, and destruction.
 * 
 * Author: Emil Engvall
 * Date:  2023-12-30
 * 
 */
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>


Graph *graph_create(int n) 
{
    Graph *g = malloc(sizeof(Graph));
    if (!g) {
        perror("Error in graph_create: Allocation failed");
        return NULL;
    }

    g->n = n;
    g->edges = calloc(n, sizeof(set *));
    if (!g->edges) {
        perror("Error in graph_create: Edges allocation failed");
        free(g);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        g->edges[i] = set_empty();
        if (!g->edges[i]) {
            for (int j = 0; j < i; j++) {
                set_destroy(g->edges[j]);
            }
            free(g->edges);
            free(g);
            return NULL;
        }
    }

    return g;
}

void graph_insert_edge(Graph *g, int a, int b) 
{
    if (a < 0 || b < 0 || a >= g->n || b >= g->n) {
        perror("Error in graph_insert_edge: Invalid node index");
        return;
    }
    set_insert(b, g->edges[a]);
}

set *graph_neighbours(Graph *g, int node) 
{
    if (node < 0 || node >= g->n) {
        perror("Error in graph_neighbours: Invalid node index");
        return NULL;
    }
    return g->edges[node];
}

int graph_no_of_nodes(Graph *g) 
{
    if (g == NULL) {
        perror("Error in graph_no_of_nodes: Null graph pointer");
        return -1;
    }
    return g->n;
}

void graph_remove_edge(Graph *g, int a, int b) 
{
    if (g == NULL) {
        perror("Error in graph_remove_edge: Null graph pointer");
        return;
    }
    if (a < 0 || b < 0 || a >= g->n || b >= g->n) {
        perror("Error in graph_remove_edge: Invalid node index");
        return;
    }
    set_remove(b, g->edges[a]);
}

void graph_remove_node(Graph *g, int node) 
{
    if (g == NULL || node < 0 || node >= g->n) {
        perror("Error in graph_remove_node: Invalid parameters");
        return;
    }

    set_destroy(g->edges[node]);

    for (int i = 0; i < g->n; i++) {
        if (i != node) {
            set_remove(node, g->edges[i]);
        }
    }

    for (int i = node; i < g->n - 1; i++) {
        g->edges[i] = g->edges[i + 1];
    }

    g->n--;
}

void graph_destroy(Graph *g) 
{
    if (g == NULL) {
        perror("Error in graph_destroy: Null graph pointer");
        return;
    }

    for (int i = 0; i < g->n; i++) {
        set_destroy(g->edges[i]);
    }
    free(g->edges);
    free(g);
}