#pragma once
#include "ofMain.h"
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define WINDOW_SIDE 500 // square window

class ofApp : public ofBaseApp {

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

// project vars
    void drawCircle(ofVec2f center, float scale, float orbitAngle);
    float timeScale;
    float clearAlpha;
    bool spin;
    float side;
    float halfSide;

};