#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    graphL = GraphList();


//    graphL.addEdge(0, 1);
//    graphL.addEdge(1, 3);
//    graphL.addEdge(3, 4);
    
    //graphL.printGraph();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    graphL.display();
    
    if (mode == ADD_EDGES) {
    
        graphL.drawLineToCurrent(mouseX, mouseY);
    }
    else if (mode == ADD_NODES) {
        ofSetColor(255, 0, 0);
        ofFill();
        ofDrawCircle(mouseX, mouseY, 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') {
        graphL.save();
        graphL.printGraph();
    }
    else if (key == 'r') graphL.read();
    else if (key == 'a') mode = ADD_NODES;
    else if (key == 'e') mode = ADD_EDGES;
    else if (key == 'm') mode = MOVE_NODES;
    else if (key == 'v') {
        mode = VISUALIZE;
    }

    else if (mode == MOVE_NODES) {
        if (graphL.hasCurrentNode()) {
            if (key == OF_KEY_UP) graphL.moveCurrentNode(0, -1);
            else if (key == OF_KEY_DOWN) graphL.moveCurrentNode(0, 1);
            else if (key == OF_KEY_RIGHT) graphL.moveCurrentNode(1, 0);
            else if (key == OF_KEY_LEFT) graphL.moveCurrentNode(-1, 0);
        }
    }
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
    if (mode == ADD_NODES) {
        graphL.addNode(mouseX, mouseY);
    }
    else if (mode == MOVE_NODES) {
        graphL.checkNodeClick(mouseX, mouseY);
    }
    else if (mode == ADD_EDGES) {
        graphL.checkEdgeClick(mouseX, mouseY);
    }
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
