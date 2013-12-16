#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    ofBackground(0);
    
    flocker.addParticle(500);
    size=30;
    }

//--------------------------------------------------------------
void testApp::update(){
    faceCenter.set(mouseX,mouseY);
    
    flocker.applyForces(faceCenter,size, 0.4, 0.75);
    flocker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
      // ofPushMatrix();{
//        ofTranslate( ofGetWindowSize() / 2.0 );
        flocker.draw();
  //  }ofPopMatrix();
    ofNoFill();
    ofCircle(mouseX,mouseY,size*5);
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    size-=1;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    flocker.addParticle( 50 );
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
