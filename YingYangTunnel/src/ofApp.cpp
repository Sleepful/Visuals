#include "ofApp.h"

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

// center is the circle's position
// scale is how close to the screen the circle is
// orbitAngle is between 0 and 360
void ofApp::drawCircle(ofVec2f center, float scale, float orbitAngle){
    float radius = scale * halfSide;
    ofPath blackHalf;
    blackHalf.moveTo(300 + 200, 300);
    blackHalf.arc(center, radius, radius, 0, 180);
    blackHalf.setFilled(true);
    blackHalf.setStrokeWidth(1);
    blackHalf.draw();
    ofPath whiteHalf;
    whiteHalf.moveTo(300 + 200, 300);
    whiteHalf.arc(center, radius, radius, 180, 0);
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
    ofPushMatrix();
        centerCoordinateSystem();
        ofSetHexColor(0xffffff);
        ofDrawCircle(0,0,side/2);
        ofSetHexColor(0x000000);
        ofDrawCircle(50,50,50);
        ofDrawCircle(0,0,5);
        drawCircle(ofVec3f(0,0,0),0,0);
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
