//Haz arder tu corazón 
#include "bits2.h"
using namespace std;

const int MAXV = 10;
const int MAXINT = 10000;
int tiempo;
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

typedef struct edgenode{
    int y;
    int weight;
    edgenode *next;
}egdenode;

typedef struct {
    edgenode *edges[MAXV+1]; 
    int degree [MAXV+1];
    int nvertices;
    int nedges; 
    int directed;
}graph;

void initialize_graph (graph *g, bool directed) {
    cout<<"ini\n";
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for (int i = 1; i <= MAXV; i++) {
        g->degree [i] = 0;
    }
    for (int i = 1; i <= MAXV; i++) {
        g->edges[i] = NULL;
    }
}

void insert_edge (graph *g, int x, int y,int _weight ,bool directed) {
    edgenode *p = new edgenode;
    cout<<x<<" "<<y<<"\n";
    p->weight = _weight;
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
    g->degree[x]++;

    if (!directed) {
     insert_edge(g, y, x,_weight ,true);
    } 
    else {
     g->nedges++;
     g->nvertices= g->nvertices+2;
    }
}

void print_graph(graph *g) {
    cout<<"imprimiendo\n";
    
    edgenode *p = new edgenode;
    for (int i = 1; i <= MAXV; i++) {
    p = g->edges [i];
    if(p!= NULL){cout<<"\n";cout<<i<<" ";}
    while (p != NULL) {
        cout<<" "<<p->y;
        p = p->next;
    }
    }
    cout<<"\n";
}

void initializa_search(graph *g)
{
    tiempo = 0;
    ciclo(i,g->nvertices)
    {
        processed[i] = false;
        discovered[i] = false;
        parent[i] = -1;
    }
}

int dijkstra(graph *g, int start) {
    edgenode *p = new edgenode;
    bool intree [MAXV+1];
    int distance [MAXV+1];
    int v;
    int w;
    int dist;
    int weight = 0;
    for (int i = 1; i <= MAXV; i++) {
        intree [i] = false;
        distance [i] = MAXINT;
        parent [i] = -1;
    }
    distance [start] = 0;
    v = start;
    while (!intree[v]) {
        intree [v] = true;
        if (v != start) {
            cout<<parent[v]<<" "<<v<<" ";
            weight = weight + dist;
        }
        p = g->edges[v];
        while (p != NULL) {
            w = p->y;
            if (distance [w] > (distance[v]+p->weight)){
                distance [w] = distance[v]+p->weight;
                parent [w] = v;
            }
            p = p->next;
        }
        dist = MAXINT;
        for (int i = 1; i <= MAXV; i++) {
            if ((!intree[i]) && (dist > distance [i])) {
                dist = distance[i];
                v = i;
            }
        }
        cout<<"\n";
    }
    return(weight);
}
