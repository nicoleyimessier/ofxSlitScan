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

	//! city stream types
	void drawVerticalSlotIn(int num_cols, glm::vec2 size, ofTexture & tex_ref, ofMesh & mesh, 
							glm::vec2 where_start, glm::vec2 where_target, float anim_val, float proto_val);


	void drawHorizontalPixel(glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh, 
							float anim_val, float target_ypos);



	void drawHorSwipeVertSC(int num_cols, glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh,
		float anim_wipe, float anim_slit, float val1, float val2, float val3);

	// story stream 
	void drawVerticalTransition(int num_rows, glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh,
		float anim_slit, float anim_move_up, float anim_mask_out);

private: 

	float blinnWyvillCosineApproximation(float x);
	float doubleOddPolynomialSeat(float x, float a, float b, int n); 
	float doublePolynomialSigmoid(float x, float a, float b, int n);

};