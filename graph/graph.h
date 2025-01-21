#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"

/**
 * @defgroup graph_h Graph Operations
 * @brief This module is used for managing graph data structures.
 *
 * The module provides functions for creating and manipulating graphs, represented as a set of nodes with edges between them.
 * It includes operations for graph creation, modification, querying, and destruction.
 *
 * Error Handling:
 * Functions without perror messages assume successful execution.
 * All functions return perror messages on failure.
 *
 * @author Emil Engvall
 * @since  2023-12-30
 * @{
 */

/**
 * @brief Structure representing a graph.
 */
typedef struct Graph {
    int n;          /**< Number of nodes in the graph.**/
    set **edges;    /**< Array of pointers to sets representing adjacency lists for each node.**/
} Graph;

/**
 * @brief Creates a new graph with a specified number of nodes.
 *
 * @param n The number of nodes in the graph.
 * @return A pointer to the newly created graph.
 */
Graph *graph_create(int n);

/**
 * @brief Adds an edge from node a to node b in the graph.
 *
 * @param g The graph to which the edge will be added.
 * @param a The starting node of the edge.
 * @param b The ending node of the edge.
 */
void graph_insert_edge(Graph *g, int a, int b);

/**
 * @brief Returns the set of all neighbors of a given node in the graph.
 *
 * @param g The graph.
 * @param node The node whose neighbors are to be found.
 * @return A set representing the neighbors of the node.
 */
set *graph_neighbours(Graph *g, int node);

/**
 * @brief Returns the number of nodes in the graph.
 *
 * @param g The graph.
 * @return The number of nodes in the graph.
 */
int graph_no_of_nodes(Graph *g);

/**
 * @brief Removes an edge from node a to node b in the graph.
 *
 * @param g The graph from which the edge will be removed.
 * @param a The starting node of the edge.
 * @param b The ending node of the edge.
 */
void graph_remove_edge(Graph *g, int a, int b);

/**
 * @brief Removes a node and its related edges from the graph.
 *
 * @param g The graph from which the node will be removed.
 * @param node The node to be removed.
 */
void graph_remove_node(Graph *g, int node);

/**
 * @brief Destroys the graph, freeing all allocated resources.
 *
 * @param g The graph to be destroyed.
 */
void graph_destroy(Graph *g);

#endif /* GRAPH_H */
/**
 * @}
 */
