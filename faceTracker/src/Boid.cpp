//
//  Boid.cpp
//  Flocking
//
//  Created by Charlie Whitney on 10/20/13.
//
//

#include "Boid.h"

Boid::Boid() {
    damping = 0.99;
}

Boid::Boid( ofVec2f position, ofVec2f velocity) {
    pos = position;
    vel = velocity;
    damping = 0.99;
    p.loadImage("yellow.png");
    //p.loadImage("yeah.png");
    size=ofRandom(25,65);
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
        vel -= dir * ( ( dist - maxDistance ) * 0.0005f );
    }
}

void Boid::update(){
    vel += acc;
    
    // don't move too fast
    vel.limit(5.0);
    
    // but also don't move too slow!
    if( vel.lengthSquared() < 1.0 ){
        vel = vel.normalized() * 1.0;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set(0);
}

void Boid::draw(){
    //ofSetColor(255,0,0);
    p.draw(pos,size,size);
    
//    ofSetColor( 255, 0, 0 );
//    ofLine( pos, pos - vel*5.0);
    
}