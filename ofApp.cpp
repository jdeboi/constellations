#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    graph = Graph(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
   graph.display();
    
    if (mode == ADD_EDGES) {
        if (graph.getCurrentNode() >= 0) {
            graph.drawLineToCurrent(mouseX, mouseY);
        }
    }
    else if (mode == ADD_STARS) {
        ofSetColor(255, 0, 0);
        ofFill();
        ofDrawCircle(mouseX, mouseY, 40);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') graph.save();
    else if (key == 'r') graph.read();
    else if (key == 'a') mode = ADD_STARS;
    else if (key == 'e') mode = ADD_EDGES;
    else if (key == 'm') mode = MOVE_STARS;
    else if (key == 'v') mode = VISUALIZE;
    
    else if (mode == MOVE_STARS) {
        if (graph.hasCurrentStar()) {
            if (key == OF_KEY_UP) graph.moveCurrentStar(0, -1);
            else if (key == OF_KEY_DOWN) graph.moveCurrentStar(0, 1);
            else if (key == OF_KEY_RIGHT) graph.moveCurrentStar(1, 0);
            else if (key == OF_KEY_LEFT) graph.moveCurrentStar(-1, 0);
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
    if (mode == ADD_STARS) {
        graph.addStar(mouseX, mouseY);
    }
    else if (mode == MOVE_STARS) {
        graph.checkNodeClick(mouseX, mouseY);
    }
    else if (mode == ADD_EDGES) {
        graph.checkEdgeClick(mouseX, mouseY);
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
