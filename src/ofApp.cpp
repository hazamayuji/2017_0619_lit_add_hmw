#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
   
    //もっと省略できる？
    sound_kind[0].load("synth.mp3");
    sound_kind[1].load("beat.mp3");
    sound_kind[2].load("bass.mp3");
    
    music_setup();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //回転
    spinX = sin(ofGetElapsedTimef()*0.5);
    spinY = cos(ofGetElapsedTimef()*0.5);
    
    //x座標
    int obj_x[3] = {ofGetWidth()/4, 0, -ofGetWidth()/4};
   
    cam.begin();
    
    for(int i = 0; i < mus_num; i++){
        
        //物体を表示(外側の球体)
        if(key_pressed[i]){
            draw_outer_sphere(obj_x[i]);
        }
        
        //音楽を流す
        if(key_pressed[i]){
            sound_kind[i].setPaused(false);
        }else{
            sound_kind[i].setPaused(true);
        }
        
    }
    
    //球体の中の物体を表示
    //ここは削減できる？
    if(key_pressed[0]){
        draw_cone(obj_x[0]);
    }
    if(key_pressed[1]){
        draw_box(obj_x[1]);
    }
    if(key_pressed[2]){
        draw_cylinder(obj_x[2]);
    }
    
    
    //音の切り替え用のスイッチ(未)
//    ofSetColor(255,0,0);
//    ofDrawTriangle(obj_x[1] - 50, triangle_y[0], obj_x[1], triangle_y[1], obj_x[1] + 50, triangle_y[0]);
//    ofDrawTriangle(obj_x[1] - 50, triangle_y[2], obj_x[1], triangle_y[3], obj_x[1] + 50, triangle_y[2]);
//   
//    ofSetColor(0,255,0);
//    ofDrawTriangle(obj_x[2] - 50, triangle_y[0], obj_x[2], triangle_y[1], obj_x[2] + 50, triangle_y[0]);
//    ofDrawTriangle(obj_x[2] - 50, triangle_y[2], obj_x[2], triangle_y[3], obj_x[2] + 50, triangle_y[2]);
//
//    ofSetColor(0,0,255);
//    ofDrawTriangle(obj_x[0] - 50, triangle_y[0], obj_x[0], triangle_y[1], obj_x[0] + 50, triangle_y[0]);
//    ofDrawTriangle(obj_x[0] - 50, triangle_y[2], obj_x[0], triangle_y[3], obj_x[0] + 50, triangle_y[2]);

    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch(key){
            
        case 'd':
            key_pressed[0] = !key_pressed[0];
            break;

        case 's':
            key_pressed[1] = !key_pressed[1] ;
            break;
            
        case 'a':
            key_pressed[2] = !key_pressed[2];
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

//繰り返し使用
void ofApp::draw_outer_sphere(int &sph_x){
    
    ofSetColor(255, 255, 255);
    sphere.setPosition(sph_x, 0, 0);
    sphere.set(100, 10);
    sphere.drawWireframe();
    sphere.rotate(spinX, 1.0, 0.0, 0.0);
    sphere.rotate(spinY, 0, 1.0, 0.0);
    
}

//座標の位置などを簡単に変えやすいように、コードを見やすくするため関数化
//ここも簡略化できる？
//同じようなコード多数

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

void ofApp::music_setup(){
    
    for(int i = 0; i < mus_num; i++){
        
        sound_kind[i].setLoop(true);
        sound_kind[i].setVolume(1.0);
        sound_kind[i].play();
        sound_kind[i].setPaused(true);
        
    }

}
