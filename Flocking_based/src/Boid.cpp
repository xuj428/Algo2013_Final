

#include "Boid.h"

Boid::Boid() {
    damping = 0.98;
}

Boid::Boid( ofVec2f position, ofVec2f velocity) {
    pos = position;
    vel = velocity;
    damping = 0.98;
}

void Boid::applyForce( ofVec2f force ){
    acc += force;
}

void Boid::pullToCenter( ofVec2f center ){
    
    // if the particles stray too far, we want to pull them back on screen
    
    ofVec2f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 70.0;
    
    if( dir.length() > maxDistance ) {
        dir.normalize();
        vel -= dir * ( ( dist - maxDistance ) * 0.0004f );
    }
}

void Boid::update(){
    vel += acc;
    
    // don't move too fast
    vel.limit(3.0);
    
    // but also don't move too slow!
    if( vel.lengthSquared() < 1.0 ){
        vel = vel.normalized() * 1.0;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set(0);
}

void Boid::draw(){
    ofSetColor(255);
    ofCircle(pos, 2);
    

    
}