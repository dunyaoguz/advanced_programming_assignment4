#include <cmath>

#include "AcuteTriangle.h"
#include "Canvas.h"

AcuteTriangle::AcuteTriangle(int b, char m_pen, std::string m_name) : Triangle(b, b, m_name, m_pen)
{
    if(b%2 == 0) 
    {
        (*this).setHeight(b+1); 
        (*this).setWidth(b+1); 
    }
}

void AcuteTriangle::setHeight(const int& m_height) { height = (m_height+1)/2; } 

double AcuteTriangle::perimeterGeo() const { return width + std::sqrt(width*width + 4*height*height); }

int AcuteTriangle::areaScr() const { return height*height; }

int AcuteTriangle::perimeterScr() const { return 4*(height-1); }

Canvas draw() const 
{
    
}