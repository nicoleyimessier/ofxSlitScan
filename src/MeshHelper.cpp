//
//  MeshHelper.cpp
//  SLIT_SCAN_SKETCH
//
//  Created by Nicole Yi Messier on 4/2/20.
//

#include "MeshHelper.h"

void MeshHelper::setup(){
    
}

#pragma mark QUAD GETERS

MeshHelper::TexQuad MeshHelper::getQuad(RectData &where, RectData & tex ){
    
    TexQuad temp;
    
    //! MESH
    temp.verts.tl.x = where.pos.x;
    temp.verts.tl.y = where.pos.y;
    
    temp.verts.tr.x = where.pos.x + where.size.x;
    temp.verts.tr.y = where.pos.y;
    
    temp.verts.bl.x = where.pos.x;
    temp.verts.bl.y = where.pos.y + where.size.y;
    
    temp.verts.br.x = where.pos.x + where.size.x;
    temp.verts.br.y = where.pos.y + where.size.y;
    
    //! TEXTURE
    temp.texCoords.tl.x = tex.pos.x;
    temp.texCoords.tl.y = tex.pos.y;
    
    temp.texCoords.tr.x = tex.pos.x + tex.size.x;
    temp.texCoords.tr.y = tex.pos.y;
    
    temp.texCoords.bl.x = tex.pos.x;
    temp.texCoords.bl.y = tex.pos.y + tex.size.y;
    
    temp.texCoords.br.x = tex.pos.x + tex.size.x;
    temp.texCoords.br.y = tex.pos.y + tex.size.y;
    
    return temp;
}

MeshHelper::ColQuad MeshHelper::getColQuad(RectData &where, ofColor &c){
    
    ColQuad temp;
    
    //! MESH
    temp.verts.tl.x = where.pos.x;
    temp.verts.tl.y = where.pos.y;
    
    temp.verts.tr.x = where.pos.x + where.size.x;
    temp.verts.tr.y = where.pos.y;
    
    temp.verts.bl.x = where.pos.x;
    temp.verts.bl.y = where.pos.y + where.size.y;
    
    temp.verts.br.x = where.pos.x + where.size.x;
    temp.verts.br.y = where.pos.y + where.size.y;
    
    //! COLOR
    temp.c = c;
    
    return temp;
}

#pragma mark ADD TO MESH

void MeshHelper::addToMesh(ofMesh &mesh, TexQuad &quad){
    
    mesh.addVertex(ofVec3f(quad.verts.tl.x, quad.verts.tl.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.tl.x, quad.texCoords.tl.y));
    
    mesh.addVertex(ofVec3f(quad.verts.bl.x, quad.verts.bl.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.bl.x, quad.texCoords.bl.y));
    
    mesh.addVertex(ofVec3f(quad.verts.tr.x, quad.verts.tr.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.tr.x, quad.texCoords.tr.y));
    
    mesh.addVertex(ofVec3f(quad.verts.tr.x, quad.verts.tr.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.tr.x, quad.texCoords.tr.y));
    
    mesh.addVertex(ofVec3f(quad.verts.br.x, quad.verts.br.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.br.x, quad.texCoords.br.y));
    
    mesh.addVertex(ofVec3f(quad.verts.bl.x, quad.verts.bl.y));
    mesh.addTexCoord(ofVec2f(quad.texCoords.bl.x, quad.texCoords.bl.y));
}

void MeshHelper::addToMesh(ofMesh &mesh, ColQuad &quad){
    
    mesh.addVertex(ofVec3f(quad.verts.tl.x, quad.verts.tl.y));
    mesh.addColor(quad.c);
    
    mesh.addVertex(ofVec3f(quad.verts.bl.x, quad.verts.bl.y));
    mesh.addColor(quad.c);
    
    mesh.addVertex(ofVec3f(quad.verts.tr.x, quad.verts.tr.y));
    mesh.addColor(quad.c);
    
    mesh.addVertex(ofVec3f(quad.verts.tr.x, quad.verts.tr.y));
    mesh.addColor(quad.c);
    
    mesh.addVertex(ofVec3f(quad.verts.br.x, quad.verts.br.y));
    mesh.addColor(quad.c);
    
    mesh.addVertex(ofVec3f(quad.verts.bl.x, quad.verts.bl.y));
    mesh.addColor(quad.c);
    
    ofSetColor(255);
    ofDrawCircle(quad.verts.tl.x, quad.verts.tl.y, 10.0f);
    ofDrawCircle(quad.verts.tr.x, quad.verts.tr.y, 10.0f);
    ofDrawCircle(quad.verts.bl.x, quad.verts.bl.y, 10.0f);
    ofDrawCircle(quad.verts.br.x, quad.verts.br.y, 10.0f);
}


