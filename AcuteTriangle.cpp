#include <cmath>

#include "AcuteTriangle.h"
#include "Canvas.h"

AcuteTriangle::AcuteTriangle(size_t b, char m_pen, std::string m_name) : Triangle(b, b, m_name, m_pen)
{
    if(b%2 == 1) 
    {
        (*this).setHeight(b); 
        (*this).setWidth(b); 
    }
    else 
    {
       (*this).setHeight(b+1); 
       (*this).setWidth(b+1);  
    }
}

void AcuteTriangle::setHeight(const size_t& m_height) { height = (m_height+1)/2; } 

double AcuteTriangle::perimeterGeo() const { return width + std::sqrt(width*width + 4*height*height); }

int AcuteTriangle::areaScr() const { return height*height; }

int AcuteTriangle::perimeterScr() const { return 4*(height-1); }

Canvas AcuteTriangle::draw() const 
{
    Canvas can{height, width};
    // example: width = 5, height = 3
    // at 0: draw 1 (@ 3)
    // at 1: draw 3 (@ 2, 3, 4)
    // at 2: draw 5 (@ 1, 2, 3, 4, 5)
    for(int row = 0; row < height; row++)
    {
        int no_chars = 1 + row*2;  
        int empty_chars = (width - no_chars)/2; 
        for(int i = 0; i < width; i++)
        {
            if(i >= empty_chars && i < (width - empty_chars))
            {
                can.put(row, i, pen); 
            }
        }
    }
    return can;
}