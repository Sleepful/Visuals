#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0x0);
    timeScale = 100.0;
    ofSetCircleResolution(1000);
}

void ofApp::update(){
}

void ofApp::draw(){
    float side = ofGetWidth();
    ofPushMatrix();
    ofSetHexColor(0xffffff);
    ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    // ofScale(1,-1,1);
    ofRotateRad(PI, 1, 0, 0);
    ofDrawCircle(0,0,side/2);
    ofSetHexColor(0x000000);
    ofDrawCircle(50,50,50);
    ofDrawCircle(0,0,5);
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
