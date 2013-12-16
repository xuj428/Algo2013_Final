#include "testApp.h"
using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    cam.initGrabber(800, 450);
    tracker.setup();
    
     flocker.addParticle(300);
    
	}

//--------------------------------------------------------------
void testApp::update(){
    
    cam.update();
    //face tracker
    if (cam.isFrameNew()) {
        tracker.update(toCv(cam));
        }
    
    faceCenter.set(tracker.getPosition());
    
   
    if(tracker.getFound()&&tracker.getPosition().x !=0 && tracker.getPosition().y !=0){
        flocker.applyForces(faceCenter,tracker.getScale()*4.5, 0.4, 0.75);
        
        flocker.update();
        
//        cout<<tracker.getDirection(ofxFaceTracker::FACING_LEFT) <<endl;
        
        //cout<<tracker.getOrientation()<<endl;
    }
    
    //cout<< tracker.getScale()<<endl;
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
   // ofPolyline faceOutline = tracker.getImageFeature(ofxFaceTracker::FACE_OUTLINE);
    
    cam.draw(0, 0);
    
	//ofSetLineWidth(2);
	//tracker.draw();
    //faceOutline.draw();
    flocker.draw();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'r') {
		tracker.reset();
	}

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
