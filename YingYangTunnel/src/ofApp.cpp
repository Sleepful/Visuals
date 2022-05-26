#include "ofApp.h"
#include <math.h>

void ofApp::setup(){
    ofBackground(0x0);
    ofSetCircleResolution(1000);
    timeScale = 100.0;
    side = ofGetWidth();
    halfSide = side/2;
    spin = false;
}

void ofApp::update(){
}

void rotateCircle(){}


void drawHalfCircle(float radius, float orbitAngle, int color){
    float start = orbitAngle - 90;
    float end = orbitAngle + 90;
    ofPath half;
    half.setCircleResolution(999);
    half.arc(ofVec2f(0,0), radius, radius, start, end);
    half.setFilled(true);
    //half.setStrokeWidth(1);
    half.setFillHexColor(color);
    half.draw();
    }

// center is the circle's position
// scale is how close to the screen the circle is
// orbitAngle is between 0 and 360
void drawCircle(float radius, float orbitAngle, int color){
    ofVec2f pos = ofVec2f(0,radius).getRotated(orbitAngle);
    ofSetHexColor(color);
    ofDrawCircle(pos,radius);
}

// center the matrix bloop (rotating camera)
void centerCoordinateSystem(){
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    ofRotateRad(PI, 1, 0, 0);
}

float invertOrbit(float orbit){
    return 360-orbit;
}

void adjustCoordinates(float radius, float orbitAngle){
    ofVec2f pos = ofVec2f(0,radius).getRotated(orbitAngle);
    ofTranslate(pos);
}

// slow
// float secondsForFullOrbit = 10;
// fast
float secondsForFullOrbit = 5;
float millisForFullOrbit = secondsForFullOrbit*1000;

void drawYingYang(float radius, int level){
    if(radius<10) return;
    float millis = ofGetElapsedTimeMillis();
    float angle = modf(millis/(millisForFullOrbit/level), &millis);
    float orbitAngle = angle*360;

    float circleRadius = radius/2;
    float oppositeOrbit = orbitAngle-180;

    drawHalfCircle(radius, orbitAngle, BLACK);
    drawHalfCircle(radius, oppositeOrbit, WHITE);

    drawCircle(circleRadius, orbitAngle, BLACK);
    drawCircle(circleRadius, oppositeOrbit, WHITE);

    ofPushMatrix();
    {
        float orbit = orbitAngle;
        adjustCoordinates(circleRadius, orbit);
        drawYingYang(circleRadius, level+1);
    }
    ofPopMatrix();

    ofPushMatrix();
    {
        float orbit = oppositeOrbit;
        adjustCoordinates(circleRadius, orbit);
        drawYingYang(circleRadius, level+1);
    }
    ofPopMatrix();
}

void ofApp::draw(){
    ofPushMatrix();
        centerCoordinateSystem();
        drawYingYang(halfSide, 1);
    ofPopMatrix();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    // clearAlpha = ofMap(x, 0, ofGetWidth(), 0, 255);  // clearAlpha goes from 0 to 255 as the mouse moves from left to right
    // timeScale = ofMap(y, 0, ofGetHeight(), 0, 1);  // timeScale goes from 0 to 1 as the mouse moves from top to bottom
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
