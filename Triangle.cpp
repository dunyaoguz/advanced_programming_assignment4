#include "Triangle.h"

Triangle::Triangle(size_t m_height, size_t m_width, std::string m_name, char m_pen) : Shape(m_height, m_width, m_name, m_pen) {}

double Triangle::areaGeo() const { return (height*width)/2.0; }