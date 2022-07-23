#include <cmath>

#include "Rhombus.h"
#include "Canvas.h"

Rhombus::Rhombus(int d, char m_pen, std::string m_name) : Shape(d, d, m_name, m_pen) 
{
    (*this).setHeight(d);
    (*this).setWidth(d);
};

void Rhombus::setHeight(const int& m_height)
{
    if(m_height%2 == 1) { height=m_height; }
    else { height=m_height+1; }
}

void Rhombus::setWidth(const int& m_width)
{
    if(m_width%2 == 1) { width=m_width; }
    else { width=m_width+1; }
}

double Rhombus::areaGeo() const { return (height*width)/2; }

double Rhombus::perimeterGeo() const { return height*2*std::sqrt(2); }

int Rhombus::areaScr() const 
{
    double n = std::floor(height/2);
    return 2*n*(n+1)+1;
}

int Rhombus::perimeterScr() const { return 2*(height-1); }

Canvas Rhombus::draw() const {}

