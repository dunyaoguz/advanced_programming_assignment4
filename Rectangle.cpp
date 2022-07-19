#include <string>
#include "Rectangle.h"
#include "Canvas.h"

Rectangle::Rectangle(int m_height, int m_width, std::string m_name, char m_pen) : Shape(m_height, m_width, m_name, m_pen) {};

double Rectangle::areaGeo() const { return height*width; }

double Rectangle::perimeterGeo() const { return 2*(height+width); }

int Rectangle::areaScr() const { return height*width; }

int Rectangle::perimeterScr() const { return 2*(height*width)-4; }
    
Canvas Rectangle::draw() const { return Canvas{height, width, pen};}
