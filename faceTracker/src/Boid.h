//
//  Boid.h
//  Flocking
//
//  Created by Charlie Whitney on 10/20/13.
//
//

#pragma once

#include "ofMain.h"

class Boid {
  public:
    Boid();
    Boid( ofVec2f position, ofVec2f velocity );
    
    void applyForce( ofVec2f force );
    void pullToCenter( ofVec2f center );
    
    void update();
    void draw();
    
    float   damping;
    float size;
    ofVec2f pos, vel, acc;
    ofImage p;
};