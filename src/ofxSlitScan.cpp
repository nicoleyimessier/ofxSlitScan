#include "ofxSlitScan.h"

ofxSlitScan::ofxSlitScan() {

}

ofxSlitScan::~ofxSlitScan() {

}

void ofxSlitScan::setup() {

}

void ofxSlitScan::update(float dt) {

}

void ofxSlitScan::draw() {

}

void ofxSlitScan::drawVerticalSlotIn(int num_cols, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh,
                                    glm::vec2 where_start, glm::vec2 where_target, float anim_val, float proto_val) {

    for (int i = 0; i < num_cols; i++) {
        MeshHelper::RectData where;
        where.size.x = size.x / num_cols;
        where.size.y = size.y;
        where.pos.x = where.size.x * i;
        where.pos.y = where_start.y + abs(where_target.y - where_start.y) * ofMap(anim_val, 1.0f, 0.0f, 0.0f, 1.0f);
        //where.pos.y = proto_val;

        float size_percent = where.size.y / size.y;
        float mapCounter = ofMap(i, -1, num_cols-1, 1, 0); 
        //float mapCounter = ofMap(i, 0, num_cols, 0, 1); //uncomment for right to left slot in 
        float offSsetExp = powf(mapCounter, 2.0f);
        float offSsetExp_map = ofMap(offSsetExp, 0, 1, 10.0f, (1 - size_percent));

        MeshHelper::RectData tex;
        glm::vec2 content_size = glm::vec2(tex_ref.getWidth(), tex_ref.getHeight());

        // start values
        glm::vec2 start_size, start_pos;
        glm::vec2 target_size, target_pos;

        start_size.y = content_size.y;
        start_size.x = content_size.x / num_cols;
        start_pos.y = 0;
        start_pos.x = tex.size.x * i;


        // animation vals
        target_size.y = content_size.y * offSsetExp_map;
        target_size.x = content_size.x / num_cols;
        target_pos.y = content_size.y * offSsetExp_map;
        target_pos.x = tex.size.x * i;

        tex.size.y = start_size.y - abs(start_size.y - target_size.y) * anim_val;
        tex.size.x = content_size.x / num_cols;
        tex.pos.y = start_pos.y + abs(start_pos.y - target_pos.y) * anim_val;
        tex.pos.x = tex.size.x * i;

        MeshHelper::TexQuad quad = MeshHelper::one().getQuad(where, tex);
        MeshHelper::one().addToMesh(mesh, quad);

    }

    //! draw mesh
    tex_ref.bind();
    mesh.draw();
    tex_ref.unbind();

}

void ofxSlitScan::drawHorizontalPixel(glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh, float anim_val, float target_ypos) {
    MeshHelper::RectData where;
    where.size.x = size.x;
    where.size.y = size.y;
    where.pos.x = pos.x; 
    where.pos.y = pos.y + anim_val * target_ypos;

    MeshHelper::RectData tex;
    glm::vec2 content_size = glm::vec2(tex_ref.getWidth(), tex_ref.getHeight());

    tex.size.y = content_size.y;
    tex.size.x = content_size.x;
    tex.pos.y = 0.0f;
    tex.pos.x = 0.0f;


    //! crop
    MeshHelper::TexQuad temp;

    //! MESH
    temp.verts.tl.x = where.pos.x;
    temp.verts.tl.y = where.pos.y;

    temp.verts.tr.x = where.pos.x + where.size.x ;
    temp.verts.tr.y = where.pos.y;

    temp.verts.bl.x = where.pos.x;
    temp.verts.bl.y = where.pos.y + where.size.y * ofMap(anim_val, 0, 1, 1, 0);

    temp.verts.br.x = where.pos.x + where.size.x;
    temp.verts.br.y = where.pos.y + where.size.y * ofMap(anim_val, 0, 1, 1, 0);

    //! TEXTURE
    temp.texCoords.tl.x = tex.pos.x;
    temp.texCoords.tl.y = tex.size.y * anim_val;

    temp.texCoords.tr.x = tex.pos.x + tex.size.x;
    temp.texCoords.tr.y = tex.size.y * anim_val;

    temp.texCoords.bl.x = tex.pos.x;
    temp.texCoords.bl.y = tex.pos.y + tex.size.y;

    temp.texCoords.br.x = tex.pos.x + tex.size.x;
    temp.texCoords.br.y = tex.pos.y + tex.size.y;

    MeshHelper::one().addToMesh(mesh, temp);

    MeshHelper::TexQuad pixel_stretch;

    //! MESH
    pixel_stretch.verts.tl.x = where.pos.x;
    pixel_stretch.verts.tl.y = where.pos.y + where.size.y * ofMap(anim_val, 0, 1, 1, 0);

    pixel_stretch.verts.tr.x = where.pos.x + where.size.x;
    pixel_stretch.verts.tr.y = where.pos.y + where.size.y * ofMap(anim_val, 0, 1, 1, 0);

    pixel_stretch.verts.bl.x = where.pos.x;
    pixel_stretch.verts.bl.y = where.pos.y + where.size.y;

    pixel_stretch.verts.br.x = where.pos.x * 2 + where.size.x;
    pixel_stretch.verts.br.y = where.pos.y + where.size.y;

    //! TEXTURE
    pixel_stretch.texCoords.tl.x = tex.pos.x;
    pixel_stretch.texCoords.tl.y = tex.size.y;

    pixel_stretch.texCoords.tr.x = tex.pos.x + tex.size.x;
    pixel_stretch.texCoords.tr.y = tex.size.y;

    pixel_stretch.texCoords.bl.x = tex.pos.x;
    pixel_stretch.texCoords.bl.y = tex.size.y;

    pixel_stretch.texCoords.br.x = tex.pos.x + tex.size.x;
    pixel_stretch.texCoords.br.y = tex.size.y;
    
    MeshHelper::one().addToMesh(mesh, pixel_stretch);

    //! draw mesh
    tex_ref.bind();
    mesh.draw();
    tex_ref.unbind();
}

void ofxSlitScan::drawHorizontalSwipe(int num_cols, glm::vec2 pos, glm::vec2 size, ofTexture& tex_ref, ofMesh& mesh, float proto_val0, float proto_val1) {

    for (int i = 0; i < num_cols; i++) {

        float size_percent = ( size.x / num_cols ) / size.x;
        float mapCounter = ofMap(i, -1, num_cols - 1, 1, 0);
        //float mapCounter = ofMap(i, 0, num_cols, 0, 1); //uncomment for right to left slot in 
        float offSsetExp = powf(mapCounter, 1.0f);
        float offSsetExp_map = ofMap(offSsetExp, 0, 1, tex_ref.getWidth() - tex_ref.getWidth()/num_cols, proto_val1);

        MeshHelper::RectData where;
        where.size.x = size.x / num_cols;
        where.size.y = size.y;
        //where.pos.x = where.size.x * i; 
        where.pos.x = pos.x + where.size.x * i - proto_val0;
        where.pos.y = pos.y;

        MeshHelper::RectData tex;
        glm::vec2 content_size = glm::vec2(tex_ref.getWidth(), tex_ref.getHeight());

        // start values
        glm::vec2 start_size, start_pos;
        glm::vec2 target_size, target_pos;

        start_size.y = content_size.y;
        start_size.x = content_size.x / num_cols;
        start_pos.y = 0;
        start_pos.x = tex.size.x * i;

        // animation vals
        target_size.y = content_size.y;
        target_size.x = content_size.x / num_cols; 
        target_pos.y = content_size.y;
        target_pos.x = tex.size.x * i;

        tex.size.y = content_size.y;
        tex.size.x = content_size.x / num_cols;
        tex.pos.y = 0.0f;
        //tex.pos.x = tex.size.x * (num_cols - 1);
        tex.pos.x = offSsetExp_map;

        //tex.pos.x = proto_val0;

        MeshHelper::TexQuad quad = MeshHelper::one().getQuad(where, tex);
        MeshHelper::one().addToMesh(mesh, quad);

    }

    //! draw mesh
    tex_ref.bind();
    mesh.draw();
    tex_ref.unbind();

}
