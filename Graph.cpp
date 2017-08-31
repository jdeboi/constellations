//
//  Graph.cpp
//  constellations
//
//  Created by Jenna deBoisblanc on 8/29/17.
//
//

#include "Graph.h"
#include <stdio.h>

Graph::Graph() {
}

Graph::Graph(int vertexCount) {
    nodeCurrent = -1;
//    this->vertexCount = vertexCount;
//    adjacencyMatrix = new bool*[vertexCount];
//    for (int i = 0; i < vertexCount; i++) {
//        adjacencyMatrix[i] = new bool[vertexCount];
//        for (int j = 0; j < vertexCount; j++)
//            adjacencyMatrix[i][j] = false;
//    }
    
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            adjacencyMatrix[i][j] = false;
        }
    }

    for (int i = 0; i < vertexCount; i++) {
        nodes.push_back(Node(std::to_string(i), -10, -10));
    }
    addEdge(0,0);
    addEdge(50, 50);
    //setNodeNeighbors();
}

//void Graph::setNodeNeighbors() {
//    
//}

void Graph::addEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = true;
        adjacencyMatrix[j][i] = true;
    }
}

void Graph::removeEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
        adjacencyMatrix[i][j] = false;
        adjacencyMatrix[j][i] = false;
    }
}

bool Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
        return adjacencyMatrix[i][j];
    else
        return false;
}

vector<int> Graph::getAdjacentIDs(int nodeID) {
    vector<int>adjNodes;
//    adjNodes.push_back(-1);
    if (nodeID >= 0 && nodeID < vertexCount) {
        for (int i = 0; i < vertexCount; i++) {
            if (i != nodeID) {
//                if (adjacencyMatrix[nodeID][i]) {
//                    adjNodes.push_back(i);
//                }
            }
        }
    }
    return adjNodes;
}

// get addresses of nodes in a vector
// actually not sure this saves you much time b/c look up by ID is fast?
//vector<Node*> Graph::getAdjacentNodePointers(int nodeID) {
//    vector<Node*> adjNodes;
//    for (int i = 0; i < vertexCount; i++) {
//        if (i != nodeID && adjacencyMatrix[nodeID][i]) {
//            Node *ptrNode = &nodes.at(i);
//            adjNodes.push_back(ptrNode);
//        }
//    }
//    return adjNodes;
//}

//void Graph::setAdjacentNodePointers(int nodeID) {
//    vector<Node*> adjNodes = getAdjacentNodePointers(nodeID);
//    nodes.at(nodeID).setAdjacentNodePointers(adjNodes);
//}

void Graph::display() {
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i).display();
        //nodes.at(i).drawEdges();
        //drawAdjacentNode(i);
    }
}

void Graph::drawLineToCurrent(int x, int y) {
    ofSetColor(255);
    ofDrawLine(nodes.at(nodeCurrent).getX(), nodes.at(nodeCurrent).getY(), x, y);
}

//void Graph::drawAdjacentNode(int nodeID) {
//    for (int i = 0; i < nodes.size(); i++) {
//        nodes.at(i).drawNeighbors();
//    }
//    vector<int> adjNodeIDs;
//    adjNodeIDs = getAdjacentIDs(nodeID);
  
//    for (int i = 0; i < adjNodeIDs.size(); i++) {
//        int x1 = nodes.at(nodeID).getX();
//        int y1 = nodes.at(nodeID).getY();
//        int x2 = nodes.at(adjNodeIDs.at(i)).getX();
//        int y2 = nodes.at(adjNodeIDs.at(i)).getY();
//        ofSetColor(255);
//        ofDrawLine(x1, y1, x2, y2);
//    }
//}

int Graph::getCurrentNode() {
    return this->nodeCurrent;
}

void Graph::setCurrentNode(int num) {
    this->nodeCurrent = num;
}

//Graph::~Graph() {
//    for (int i = 0; i < vertexCount; i++) {
//        delete[] adjacencyMatrix[i];
//    }
//    delete[] adjacencyMatrix;
//}

void Graph::save() {
    nodesFile.open("nodes.txt",ofFile::WriteOnly);
    for (int i = 0; i < nodes.size(); i++) {
        nodesFile << nodes.at(i).printData() << std::endl;
    }
    nodesFile.close();
    
    adjacencyFile.open("adjacency.txt",ofFile::WriteOnly);
    for (int i = 0; i < nodes.size(); i++) {
        adjacencyFile << i << " ";
        for (int j = 0; j < nodes.size(); j++) {
            adjacencyFile << adjacencyMatrix[i][j] << " ";
        }
        adjacencyFile << std::endl;
    }
}

void Graph::read() {
    ofBuffer buffer = ofBufferFromFile("nodes.txt");
    int i = 0;
    for (auto line : buffer.getLines()){
        vector < string > result;
        result = ofSplitString(line, " ");
    
        if (i >= 0 && i < nodes.size()) {
            nodes.at(i).set(result[0], atoi(result[1].c_str()), atoi(result[2].c_str()));
        }
        i++;
    }
    
    ofBuffer buffer2 = ofBufferFromFile("adjacency.txt");
    i = 0;
    for (auto line : buffer2.getLines()){
        vector < string > result;
        result = ofSplitString(line, " ");
        for (int j = 1; j < result.size(); j++) {
            adjacencyMatrix[i][j] = atoi(result[j].c_str());
        }
        i++;
    }
    
}

void Graph::addStar(int mx, int my) {
    numNodes++;
    if (numNodes <= nodes.size()) {
         nodes.at(numNodes - 1).set(mx, my);
    }
}

void Graph::checkNodeClick(int mx, int my) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).mouseOver(mx, my)) {
            currentStarIndex = i;
            return;
        }
    }
}

void Graph::checkEdgeClick(int mx, int my) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i).mouseOver()) {
            // haven't clicked on a star yet
            if (currentNodeIndex == -1) {
                currentNodeIndex = i;
            }
            // clicked on the same star
            else if (currentNodeIndex == i) {
                currentNodeIndex = -1;
                // clicked a new star! let's add an edge
            } else {
                // add link in adjacency matrix
                adjacencyMatrix[currentNodeIndex][i] = true;
                currentNodeIndex = i;
            }
            return;
        }
    }
    currentNodeIndex = -1;
    return;

}

bool Graph::hasCurrentStar() {
    return (currentStarIndex > -1);
}

void Graph:: moveCurrentStar(int dx, int dy) {
    nodes.at(currentNodeIndex).move(dx, dy);
}
    
    
