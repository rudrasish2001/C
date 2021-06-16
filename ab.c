#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    unsigned int first;
    unsigned int second;
} edge;
 
static unsigned int cyclic_recursive(const edge *edges, unsigned int n, unsigned int *visited,
        unsigned int order, unsigned int vertex, unsigned int predecessor)
{
    unsigned int i;
    unsigned int cycle_found = 0;
    visited[vertex] = 1;
    for (i = 0; i < n && !cycle_found; i++) {
        if (edges[i].first == vertex || edges[i].second == vertex) {            
            const unsigned int neighbour = edges[i].first == vertex ?
                    edges[i].second : edges[i].first;
            if (visited[neighbour] == 0) {             
                cycle_found = cyclic_recursive(edges, n, visited, order, neighbour, vertex);
            }
            else if (neighbour != predecessor) {            
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}
 
unsigned int cyclic(const edge *edges, unsigned int n, unsigned int order)
{
    unsigned int *visited = calloc(order, sizeof(unsigned int));
    unsigned int cycle_found;
    if (visited == NULL) {
        return 0;
    }
    cycle_found  = cyclic_recursive(edges, n, visited, order, 0, 0);
    free(visited);
    return cycle_found;
}

int main(void)
{
    const unsigned int order = 5; 
    const unsigned int n = 5; 
    edge *edges;
    unsigned int c;
    
    edges = malloc(n * sizeof(edge));
    if (edges == NULL) {
        return 1;
    }

    edges[1].first = 1;
    edges[1].second = 0;
    edges[1].first = 0;
    edges[1].second = 0;


    edges[2].first = 0;
    edges[2].second = 1;
    edges[2].first = 0;
    edges[2].second = 0;


    edges[3].first = 0;
    edges[3].second = 0;
    edges[3].first = 1;
    edges[3].second = 0;


    edges[4].first = 0;
    edges[4].second = 0;
    edges[4].first = 0;
    edges[4].second = 1;


    edges[5].first = 1;
    edges[5].second = 0;
    edges[5].first = 0;
    edges[5].second = 0;
 
    c = cyclic(edges, n, order);    
    if(c){
        printf("cyclic - It has deadlock");
    }
    else{
        printf("Acyclic - It doesn't have deadlock");
    }
    free(edges);
 
    return 0;
}
