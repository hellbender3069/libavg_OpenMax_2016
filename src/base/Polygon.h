// Original code by John W. Ratcliff presumed to be in the public domain. Found 
// at http://www.flipcode.com/archives/Efficient_Polygon_Triangulation.shtml. 

#ifndef _Triangulate_H_
#define _Triangulate_H_

#include "Triangle.h"
#include "GLMHelper.h"

#include <vector>

namespace avg {

class Polygon {
public:
    Polygon();
    Polygon(const Vec2Vector& pts);

    const Vec2Vector& getPts() const;
    float getArea();
    void triangulate(std::vector<int>& resultIndexes);

private:
    static void edgeCallback(bool bEdge); 
    static void vertexCallback(void* pVertexData, void* pPolygonData); 

    Vec2Vector m_Pts;
    std::vector<int>* m_pIndexes;
};

// Result type is suitable for use in a Triangle Vertex Array.
void triangulatePolygon(const Vec2Vector &contour, std::vector<int> &resultIndexes);

float getPolygonArea(const Vec2Vector &contour);

}

#endif
