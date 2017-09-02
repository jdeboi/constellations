//
//  GraphList.cpp
//  constellations
//
//  Created by Jenna deBoisblanc on 9/1/17.
//
//

#include "GraphList.h"

//
//  GraphList.cpp
//  constellations
//
//  Created by Jenna deBoisblanc on 8/29/17.
//
//

#include "GraphList.h"
#include <stdio.h>

GraphList::GraphList() {
    this->currentNodeIndex = NULL;
    this->numNodes = 0;
    nodeList = new AdjList [vertexCount];
    for (int i = 0; i < vertexCount; ++i) {
        nodeList[i].head = NULL;  		//linking head of all vertices (array) to NULL ,it doesn't store any number only stores HEAD
    }
    for (int i = 0; i < vertexCount; i++) {
        nodes.push_back(Node(std::to_string(i), rand() % 400,rand() % 400));
    }
//    addEdge(0,1);
//    addEdge(1,3);
//    addEdge(50, 50);
    //setNodeNeighbors();
}

//void GraphList::setNodeNeighbors() {
//
//}

void GraphList::addEdge(int src, int dest) {
    /*
     * Adding Edge to Graph
     * https://github.com/JerryGoyal/data-structure/blob/master/graph%20implementation%20using%20adjacency%20list%20linked%20list%20array.cpp
     */

    
    Node* newNode = new Node;  //newNode stores both data(dest) and *next pointer
    //Node* newNode = &nodes.at(src);
    newNode->data = dest;					//consider src = 0 and dest = 1		0<----->1 for undirected graph
    newNode->next = NULL;		//  1----->NULL
    //adding nodes at beginning of each list just like in linked list//
    newNode->next = nodeList[src].head;		//*next(of dst) storing address of head->next node i.e.. 1--->2 (first node from head)
    nodeList[src].head = newNode;				//	0-->1-->2
    
    // Since graph is undirected, add an edge from dest to src also
    //Node* destNode = &nodes.at(dest); 				 //now newNode storing data(src)
    newNode = new Node;
    newNode->data = src;
    newNode->next = NULL;				// 0--->NULL
    
    newNode->next = nodeList[dest].head;	// 0---->NULL (bcuz.. 1-->NULL)
    nodeList[dest].head = newNode;			// 1---->0
    
}


// get addresses of nodes in a vector
// actually not sure this saves you much time b/c look up by ID is fast?
//vector<Node*> GraphList::getAdjacentNodePointers(int nodeID) {
//    vector<Node*> adjNodes;
//    for (int i = 0; i < nodes.size(); i++) {
//        if (i != nodeID && adjacencyMatrix[nodeID][i]) {
//            Node *ptrNode = &nodes.at(i);
//            adjNodes.push_back(ptrNode);
//        }
//    }
//    return adjNodes;
//}

//void GraphList::setAdjacentNodePointers(int nodeID) {
//    vector<Node*> adjNodes = getAdjacentNodePointers(nodeID);
//    //cout <<nodeID << " " << adjNodes.size() << std::endl;
//    nodes.at(nodeID).setAdjacentNodePointers(adjNodes);
//}

//void GraphList::display() {
//    for (int i = 0; i < vertexCount; i++) {
//        if (nodeList[i].head != NULL) {
//        Node n = *nodeList[i].head;
//            n.display();
//            n.showDestinationLines();
//        }
//    }
//}

void GraphList::display(){
    ofSetColor(255);
    int v;
    for (v = 0; v < vertexCount; ++v) {
        Node* tmp = nodeList[v].head;		//tmp has the address of (0,1..)vertex head
        int x1, y1;
        if (tmp) {
            x1 = tmp->getX();
            y1 = tmp->getY();
            //ofDrawEllipse(x1, y1, 30, 30);
        }
        while (tmp) {
            tmp->display();
            tmp = tmp->next;
            if (tmp) {
                int x2 = tmp->getX();
                int y2 = tmp->getY();
                ofDrawLine(x1, y2, x2, y2);
            }
        }
    }
}


void GraphList::drawLineToCurrent(int x, int y) {
    ofSetColor(255);
    if(currentNodeIndex) {
        ofDrawLine(currentNodeIndex->getX(), currentNodeIndex->getY(), x, y);
    }
}



Node* GraphList::getCurrentNode() {
    //cout << currentNodeIndex << std::endl;
    return currentNodeIndex;
}

void GraphList::setCurrentNode(Node* num) {
    currentNodeIndex = num;
}

//void GraphList::save() {
//    nodesFile.open("nodes.txt",ofFile::WriteOnly);
//    for (int i = 0; i < nodes.size(); i++) {
//        nodesFile << nodes.at(i).printData() << std::endl;
//    }
//    nodesFile.close();
//    
//    adjacencyFile.open("adjacency.txt",ofFile::WriteOnly);
//    for (int i = 0; i < nodes.size(); i++) {
//        adjacencyFile << i << " ";
//        for (int j = 0; j < nodes.size(); j++) {
//            adjacencyFile << adjacencyMatrix[i][j] << " ";
//        }
//        adjacencyFile << std::endl;
//    }
//}

//void GraphList::setNodePointers() {
//    for (int i = 0; i < nodes.size(); i++) {
//        setAdjacentNodePointers(i);
//    }
//}

//void GraphList::read() {
//    ofBuffer buffer = ofBufferFromFile("nodes.txt");
//    int i = 0;
//    for (auto line : buffer.getLines()){
//        vector < string > result;
//        result = ofSplitString(line, " ");
//        
//        if (i >= 0 && i < nodes.size()) {
//            nodes.at(i).set(result[0], atoi(result[1].c_str()), atoi(result[2].c_str()));
//        }
//        i++;
//    }
//    
//    ofBuffer buffer2 = ofBufferFromFile("adjacency.txt");
//    i = 0;
//    for (auto line : buffer2.getLines()){
//        vector < string > result;
//        result = ofSplitString(line, " ");
//        for (int j = 1; j < result.size(); j++) {
//            adjacencyMatrix[i][j] = atoi(result[j].c_str());
//        }
//        i++;
//    }
//    
//}

//void GraphList::addNode(int mx, int my) {
//    numNodes++;
//    if (numNodes <= nodes.size()) {
//        nodes.at(numNodes - 1).set(mx, my);
//    }
//}


void GraphList::checkNodeClick(int mx, int my) {
    currentNodeIndex = getClickedNode(mx, my);
}

Node* GraphList::getClickedNode(int mx, int my) {
    int v;
    for (v = 0; v < vertexCount; ++v){
        Node* tmp = nodeList[v].head;		//tmp has the address of (0,1..)vertex head
        while (tmp) {
            if (tmp->mouseOver(mx, my)) {
                return tmp;
            }
            tmp = tmp->next;
        }
    }
    return NULL;
}

void GraphList::checkEdgeClick(int mx, int my) {
    Node* prevNodeIndex = currentNodeIndex;
    currentNodeIndex = getClickedNode(mx, my);
    //cout << currentNodeIndex << " " << prevNodeIndex << std::endl;
    // if we actually clicked on a star to create an edge
    if (currentNodeIndex) {
        // if we've already selected a star
        if (prevNodeIndex) {
            // oops, clicked on the same star
            if (prevNodeIndex == currentNodeIndex) {
                currentNodeIndex = NULL;
            }
            // clicked a new star! let's add an edge
            else {
                // add link in list
                addEdge(prevNodeIndex->data, currentNodeIndex->data);
            }
        }
    }
}

bool GraphList::hasCurrentNode() {
    return (currentNodeIndex);
}

void GraphList:: moveCurrentNode(int dx, int dy) {
    currentNodeIndex->move(dx, dy);
}

void GraphList::printGraph(){
    int v;
    for (v = 0; v < vertexCount; ++v){
        Node* tmp = nodeList[v].head;		//tmp has the address of (0,1..)vertex head
        //cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
        while (tmp)
        {
            //cout<<"-> "<<tmp->data;
            tmp = tmp->next;
        }
        //cout<<endl;
    }
}

