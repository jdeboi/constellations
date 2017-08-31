//
//  Graph.hpp
//  constellations
//
//  Created by Jenna deBoisblanc on 8/29/17.
//
//

#ifndef Graph_h
#define Graph_h

#include "ofMain.h"
#include "Node.h"
#include <stdio.h>
#include "ofMain.h"


class Graph {

    private:
//        bool** adjacencyMatrix;     // pointer because you want to be able to modify the array in methods, double because
        bool adjacencyMatrix[100][100];
        int vertexCount;
        vector<Node> nodes;
        int numNodes = 0;
        int currentNodeIndex = -1;
    
    public:
        // originals
        Graph();
        Graph(const int vertexCount);
        void addEdge(int i, int j);
        void removeEdge(int i, int j);
        bool isEdge(int i, int j);
        //~Graph();
    
        // get
        vector<int> getAdjacentIDs(int nodeID);
        //vector<Node*> getAdjacentNodePointers(int nodeID);
    
    
        // display
        void drawAdjacentNode(int nodeID);
        void display();
        void drawLineToCurrent(int x, int y);
        void drawAdjacencyMatrix();
    
        // set
        int getCurrentNode();
        void setCurrentNode(int i);
        void setAdjacentNodePointers(int nodeID);
        void addNode(int x, int y);
    
        // save
        ofFile nodesFile;
        ofFile adjacencyFile;
        void save();
        void read();
    
        void checkNodeClick(int x, int y);
        int getClickedNode(int x, int y);
        void checkEdgeClick(int x, int y);
        bool hasCurrentNode();
        void moveCurrentNode(int dx, int dy);
    
};
#endif /* Graph_h */
