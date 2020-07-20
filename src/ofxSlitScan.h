#pragma once
#include "MeshHelper.h"
#include "SlitScanData.h"
#include "ofMain.h"

class ofxSlitScan {
  public:
    ofxSlitScan();
    ~ofxSlitScan();

    void setup();
    void update( float dt );
    void draw();

    //! city stream types
    void drawVerticalSlotIn(
        int num_cols, glm::vec2 size, glm::vec2 content_size, ofMesh &mesh, glm::vec2 where_start, glm::vec2 where_target, float anim_val );


    void drawHorizontalPixel( glm::vec2 pos, glm::vec2 size, glm::vec2 content_size, ofMesh &mesh, float anim_val, float target_ypos );


    void drawHorSwipeVertSC(
        int num_cols, glm::vec2 pos, glm::vec2 size, ofTexture &tex_ref, ofMesh &mesh, float anim_wipe, float anim_slit, bool lr = false );

    // story stream
    void drawVerticalTransition( int num_rows, glm::vec2 pos, glm::vec2 size, ofTexture &tex_ref, ofMesh &mesh, float anim_slit,
        float anim_move_up, float anim_mask_out );

    void drawVerticalBase(
        int num_rows, glm::vec2 pos, glm::vec2 size, ofTexture &tex_ref, ofMesh &mesh, float anim_move_up, float offset_y );

    void drawVerticalOverlay(
        int num_rows, glm::vec2 pos, glm::vec2 size, ofTexture &tex_ref, ofMesh &mesh, float anim_move_up, float offset_y );

    // vss
    void typeVSSSlotIn( int num_cols, glm::vec2 size, glm::vec2 content_size, ofMesh &mesh, glm::vec2 where_start, glm::vec2 where_target,
        float xoffset, float anim_val );

    void typeVSSSlotOut( int num_cols, glm::vec2 size, glm::vec2 content_size, ofMesh &mesh, glm::vec2 where_start, glm::vec2 where_target,
        float xoffset, float anim_val );

    // no pixel stretch
    void drawVerticalMaskOut( int num_cols, glm::vec2 pos, glm::vec2 size, ofTexture &tex_ref, ofMesh &mesh, vector<float> &anim_vals );

    void drawMesh( ofTexture &tex_ref, ofMesh &mesh );

    // text animation
    void drawMaskIn(
        int num_rows, float row_height, glm::vec2 content_size, ofMesh &mesh, glm::vec2 pos, float anim_val );

  private:
    float blinnWyvillCosineApproximation( float x );
    float doubleOddPolynomialSeat( float x, float a, float b, int n );
    float doublePolynomialSigmoid( float x, float a, float b, int n );
};