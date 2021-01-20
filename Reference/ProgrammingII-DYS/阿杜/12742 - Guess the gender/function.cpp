#include <iostream>
#include "function.h"
#include <stdlib.h>
using namespace std;

Graph::~Graph(){}

Graph::Graph(int n){
    this->numberOfVertices = n;
    this->adjacencyList = (Vertex**)malloc(sizeof(Vertex*)*n);
    this->vertexInfo = (int*)malloc(sizeof(int)*n);
    for(int i = 0;i<n;i++){
        this->adjacencyList[i] = new Vertex(i);
        this->vertexInfo[i]=-1;
    }
}
void Graph::addEdge(int source,int destination){
    Vertex *tmp = this->adjacencyList[source];
    Vertex *dest = new Vertex(destination);
    dest->nextVertex = tmp->nextVertex;
    tmp->nextVertex = dest;
}

bool Graph::solver(){
    Vertex *tmp;
    for(int i=0;i<this->numberOfVertices;i++){
        tmp = this->adjacencyList[i];
        if(this->vertexInfo[tmp->index]==-1) this->vertexInfo[tmp->index]=0;
        while(1){
            tmp = tmp->nextVertex;
            if(tmp==NULL) break;
            if(this->vertexInfo[tmp->index]==-1) this->vertexInfo[tmp->index] = !this->vertexInfo[i];
            if(this->vertexInfo[tmp->index]==this->vertexInfo[i]) return 0;
        }
    }
    return 1;
}
