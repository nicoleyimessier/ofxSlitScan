//
//  MeshHelper.hpp
//  SLIT_SCAN_SKETCH
//
//  Created by Nicole Yi Messier on 4/2/20.
//

#pragma mark once

#include "ofMain.h"


class MeshHelper {
public:
    
    static MeshHelper& one()
    {
        static MeshHelper instance;
        return instance;
        
    }; 
    
    void setup();

    // --- STRUCTS --- //
    struct Quad{
        glm::vec3 tl, tr, br, bl;
    };
    
    struct TexQuad{
        Quad verts;
        Quad texCoords;
    };
    
    struct ColQuad{
        Quad verts;
        ofColor c;
    };
    
    struct RectData {
        glm::vec2 size;
        glm::vec2 pos;
    };
    
    // --- QUAD GETTERS --- //
    TexQuad getQuad(RectData &where, RectData & tex);


    ColQuad getColQuad(RectData &where, ofColor &c);
    
    // --- DRAWING TO MESH --- //
    void addToMesh(ofMesh &mesh, TexQuad &quad);
    void addToMesh(ofMesh &mesh, ColQuad &quad);
    
private:
    
};
