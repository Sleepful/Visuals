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


void ofApp::drawHalfCircle(ofVec2f center, float scale, float orbitAngle, int color){
    float radius = scale * halfSide;
    //ofVec2f distance = ofVec2f(0, radius);
    float start = orbitAngle - 90;
    float end = orbitAngle + 90;
    ofPath half;
    half.setCircleResolution(999);
    half.arc(center, radius, radius, start, end);
    half.setFilled(true);
    half.setStrokeWidth(1);
    half.setFillHexColor(color);
    half.draw();
    }

// center is the circle's position
// scale is how close to the screen the circle is
// orbitAngle is between 0 and 360
void ofApp::drawCircle(ofVec2f center, float scale, float orbitAngle, int color){
    float radius = scale * halfSide;
    ofVec2f distance = ofVec2f(0, radius);
    ofVec2f pos = ofVec2f(center+distance).getRotated(orbitAngle);
    ofSetHexColor(color);
    ofVec2f v1( 3, 4 );
    ofVec2f v2 = v1.getScaled( 15 );
    cout << "pos y x: " << v2 <<endl;
    cout << "pos y x: " << pos <<endl;
    ofDrawCircle(pos,radius);
    ofPath blackHalf;
    blackHalf.moveTo(300 + 200, -300);
    // blackHalf.arc(center, radius, radius, 0, -180);
    blackHalf.setFilled(true);
    blackHalf.setStrokeWidth(1);
    blackHalf.draw();
    ofPath whiteHalf;
    whiteHalf.moveTo(300 + 200, -300);
    //whiteHalf.arc(center, radius, radius, 180, 0);
    whiteHalf.setFilled(false);
    whiteHalf.setStrokeWidth(1);
    whiteHalf.draw();
}

// center the matrix bloop (rotating camera)
// float matrixCenter(){}
void centerCoordinateSystem(){
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    ofRotateRad(PI, 1, 0, 0);

}

void ofApp::draw(){
    float side = ofGetWidth();
    float millis = ofGetElapsedTimeMillis();
    float secondsForFullOrbit = 3*1000;
    float angle = modf(millis/secondsForFullOrbit, &millis);
    float orbitAngle = angle*360;
    ofPushMatrix();
        centerCoordinateSystem();
        ofSetHexColor(0x04d9ff);
        ofDrawCircle(0,0,side/2);
        ofSetHexColor(0x000000);
        ofDrawCircle(50,50,50);
        ofDrawCircle(0,0,5);
        drawHalfCircle(ofVec2f(0,0),1,orbitAngle, BLACK);
        drawHalfCircle(ofVec2f(0,0),1,orbitAngle-180, WHITE);
        drawCircle(ofVec2f(0,0),0.5,orbitAngle-180, WHITE);
        drawCircle(ofVec2f(0,0),0.5,orbitAngle, BLACK);
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
