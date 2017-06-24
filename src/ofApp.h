#pragma once

#include "ofMain.h"
#define  NUM 1500

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    void draw_outer_sphere(int &sph_x);
    
    //関数の配列化できる？
    void draw_box(int &box_x);
    void draw_cylinder(int &cyl_x);
    void draw_cone(int &cone_x);
    
    void loop_sound_a();
   
    //bool key_pressed[3] = {false, false, false};
    int key_pressed[3] = {0,0,0};
    int obj_x[3] = {ofGetWidth()/4, 0, -ofGetWidth()/4};
    
    
    //回転させる時に使用
    float spinX;
    float spinY;
    
    
    //インスタンス化
    //カメラ
    //ofCamera cam;
    ofEasyCam cam;
    ofSoundPlayer sound_beat;
    ofSoundPlayer sound_bass;

    //物体
    ofSpherePrimitive sphere;
    ofCylinderPrimitive cylinder;
    ofConePrimitive cone;
    ofBoxPrimitive box;
    
    

};
