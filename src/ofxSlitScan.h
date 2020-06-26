#pragma once
#include "ofMain.h"
#include "MeshHelper.h"
#include "SlitScanData.h"

class ofxSlitScan {
public: 
	ofxSlitScan(); 
	~ofxSlitScan(); 

	void setup(); 
	void update(float dt); 
	void draw(); 

	//! draw types
	void drawVerticalSlotIn(int num_cols, glm::vec2 size, ofTexture & tex_ref, ofMesh & mesh, 
							glm::vec2 where_start, glm::vec2 where_target, float anim_val, float proto_val);


	void drawHorizontalPixel(glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh, 
							float anim_val, float target_ypos);


	void drawHorizontalSwipe(int num_cols, glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh,
		float proto_val0, float proto_val1);

private: 

};