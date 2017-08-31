#pragma once

#include "ofMain.h"
#include "Graph.h"

#define VISUALIZE   0
#define ADD_STARS   1
#define ADD_EDGES   2
#define MOVE_STARS  3

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int mode = 1;
    
        Graph graph;
    
    
    
		
};
