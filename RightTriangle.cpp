#include <cmath>

#include "RightTriangle.h"
#include "Canvas.h"

RightTriangle::RightTriangle(int b, char m_pen, std::string m_name) : Triangle(b, b, m_name, m_pen) {}

double RightTriangle::perimeterGeo() const { return (2 + std::sqrt(2))*height; }

int RightTriangle::areaScr() const { return (height*(height+1))/2; }

int RightTriangle::perimeterScr() const { return 3*(height-1); }

Canvas draw() const {}