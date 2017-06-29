#pragma once

#include "ofMain.h"
#define  mus_num 3

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
	
    //球体を描画
    void draw_outer_sphere(int &sph_x);
    
    //関数の配列化できる？
    //関数で配列できてたら意味わからん?
    void draw_box(int &box_x);
    void draw_cylinder(int &cyl_x);
    void draw_cone(int &cone_x);
    
    //音楽について
    void music_setup();
   
    bool key_pressed[3] = {false, false, false};
    
    //回転させる時に使用
    float spinX;
    float spinY;
    
    //未使用
    int triangle_y[4] = {150, 250, -150, -250};

    
    //インスタンス化
    //カメラ
    ofEasyCam cam;
    //ofCamera cam;
    ofSoundPlayer sound_kind[3];

    //物体
    //同じクラスから何個もインスタンスをつくることはできるけど
    //別のクラスのインスタンス化は配列で名前つけてはできない(？)
    ofSpherePrimitive sphere;
    ofCylinderPrimitive cylinder;
    ofConePrimitive cone;
    ofBoxPrimitive box;

};
