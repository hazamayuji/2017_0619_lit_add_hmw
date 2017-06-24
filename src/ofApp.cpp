#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    spinX = sin(ofGetElapsedTimef()*0.5);
    spinY = cos(ofGetElapsedTimef()*0.5);
    
    cam.begin();
    
    
    //aキーについて
    if(key_pressed[2]%2 == 1){
        draw_outer_sphere(obj_x[2]);
        draw_cylinder(obj_x[2]);
    }
    
    //sキーについて
    if(key_pressed[1]%2 == 1){
        draw_outer_sphere(obj_x[1]);
        draw_box(obj_x[1]);
       
    }
    
    if(key_pressed[1]%2 == 0){
        
    sound_beat.load("beat.mp3");
    sound_beat.setLoop(true);
    sound_beat.setVolume(1.0);
    sound_beat.play();
    sound_beat.setMultiPlay(false);
        
    }
    
    
    //dキーについて
    if(key_pressed[0]%2 == 1){
        draw_outer_sphere(obj_x[0]);
        draw_cone(obj_x[0]);
    }

    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key){
        case 'a':
            key_pressed[2]++;
            break;

        case 's':
            key_pressed[1]++;
            break;
            
        case 'd':
            key_pressed[0]++;
            break;
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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


void ofApp::draw_outer_sphere(int &sph_x){
    
    ofSetColor(255, 255, 255);
    sphere.setPosition(sph_x, 0, 0);
    sphere.set(100, 10);
    sphere.drawWireframe();
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    
}

void ofApp::draw_box(int &box_x){
    
    ofSetColor(255, 0, 0);
    box.setPosition(box_x, 0, 0);
    box.drawWireframe();
    box.rotate(spinX, 1.0, 0.0, 0.0);
    box.rotate(spinY, 0, 1.0, 0.0);
}

void ofApp::draw_cylinder(int &cyl_x){
    
    ofSetColor(0, 255, 0);
    cylinder.setPosition(cyl_x, 0, 0);
    cylinder.drawWireframe();
    cylinder.rotate(spinX, 1.0, 0.0, 0.0);
    cylinder.rotate(spinY, 0, 1.0, 0.0);

}

void ofApp::draw_cone(int &cone_x){
    
    ofSetColor(0, 0, 255);
    cone.setScale(2.5);
    cone.setPosition(cone_x, 0, 0);
    cone.drawWireframe();
    cone.rotate(spinX, 1.0, 0.0, 0.0);
    cone.rotate(spinY, 0, 1.0, 0.0);
    
}
