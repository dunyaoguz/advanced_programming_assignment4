#include "Triangle.h"

Triangle::Triangle(int m_height, int m_width, std::string m_name, char m_pen) : Shape(m_height, m_width, m_name, m_pen) {}

double Triangle::areaGeo() const { return (height*width)/2.0; }