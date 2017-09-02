//
//  GraphList.hpp
//  constellations
//
//  Created by Jenna deBoisblanc on 8/29/17.
//
//

#ifndef GraphList_h
#define GraphList_h

#include "ofMain.h"
#include "Node.h"
#include <stdio.h>
#include "ofMain.h"

#define vertexCount 100


/*
 * Adjacency List
 */
struct AdjList
{
    Node* head;
};

class GraphList {
    
private:
    //        bool** adjacencyMatrix;     // pointer because you want to be able to modify the array in methods, double because
//    bool adjacencyMatrix[vertexCount][vertexCount];
    vector<Node> nodes;
    int numNodes = 0;
    
    AdjList* nodeList;
    
public:
    Node* currentNodeIndex;
    // originals
    GraphList();
    void addEdge(int i, int j);
//    void removeEdge(int i, int j);
//    bool isEdge(int i, int j);
    //~GraphList();
    
    // get
//    vector<int> getAdjacentIDs(int nodeID);
//    vector<Node*> getAdjacentNodePointers(int nodeID);
    
    
    // display
//    void drawAdjacentNode(int nodeID);
    void display();
    void drawLineToCurrent(int x, int y);
//    void drawAdjacencyMatrix();
    
    // set
    Node* getCurrentNode();
    void setCurrentNode(Node* n);
//    void setAdjacentNodePointers(int nodeID);
//    void addNode(int x, int y);
//    void setNodePointers();
    
    // save
//    ofFile nodesFile;
//    ofFile adjacencyFile;
//    void save();
//    void read();
    
    void checkNodeClick(int x, int y);
    Node* getClickedNode(int x, int y);
    void checkEdgeClick(int x, int y);
    bool hasCurrentNode();
    void moveCurrentNode(int dx, int dy);
    
    void printGraph();
    
    
};
#endif /* GraphList_h */
