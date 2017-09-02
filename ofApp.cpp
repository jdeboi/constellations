#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    graph = Graph();
    graphL = GraphList();
    
//    
//    graphL.addEdge(0, 1);
//    graphL.addEdge(1, 3);
//    graphL.addEdge(3, 4);
    
    graphL.printGraph();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    graphL.display();
    
  // graph.display();
    
//    if (mode == ADD_EDGES) {
//    
//        graph.drawLineToCurrent(mouseX, mouseY);
//    }
//    else if (mode == ADD_NODES) {
//        ofSetColor(255, 0, 0);
//        ofFill();
//        ofDrawCircle(mouseX, mouseY, 40);
    //}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    if (key == 's') graph.save();
//    else if (key == 'r') graph.read();
//    else if (key == 'a') mode = ADD_NODES;
//    else if (key == 'e') mode = ADD_EDGES;
//    else if (key == 'm') mode = MOVE_NODES;
//    else if (key == 'v') {
//        mode = VISUALIZE;
//        graph.setNodePointers();
//    }
//    
//    else if (mode == MOVE_NODES) {
//        if (graph.hasCurrentNode()) {
//            if (key == OF_KEY_UP) graph.moveCurrentNode(0, -1);
//            else if (key == OF_KEY_DOWN) graph.moveCurrentNode(0, 1);
//            else if (key == OF_KEY_RIGHT) graph.moveCurrentNode(1, 0);
//            else if (key == OF_KEY_LEFT) graph.moveCurrentNode(-1, 0);
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    if (mode == ADD_NODES) {
//        graph.addNode(mouseX, mouseY);
//    }
//    else if (mode == MOVE_NODES) {
//        graph.checkNodeClick(mouseX, mouseY);
//    }
//    else if (mode == ADD_EDGES) {
//        graph.checkEdgeClick(mouseX, mouseY);
//    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
