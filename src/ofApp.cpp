#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    ofSetBackgroundAuto(false);
    
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    cameraWidth = 1920;
    cameraHeight = 1080;
    texture.allocate(cameraWidth, cameraHeight, GL_RGBA);
    videoGrabber.initGrabber(cameraWidth, cameraHeight);
    
    intSliderForBlendMode.addListener(this, &ofApp::intSliderForBlendModeChanged);
    
    guiPanel.setup();
    guiPanel.add(intSliderForBlendMode.setup("BlendMode", 4, 0, 5));
    guiPanel.add(colorSlider.setup("color", ofColor(255, 255, 255, 20), ofColor(0,0,0,0), ofColor(255, 255, 255, 255)));
}

void ofApp::intSliderForBlendModeChanged(int & circleResolution){
    ofEnableBlendMode((ofBlendMode)circleResolution);
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();
    if (videoGrabber.isFrameNew()) {
        texture = videoGrabber.getTextureReference();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
//    
//    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
//    ofSetColor(0, 0, 0, 0);
//    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
//    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(colorSlider);
    texture.draw(ofGetWidth(), 0, -ofGetWidth(), ofGetHeight());
    ofPopStyle();
    
    //gui
    guiPanel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
