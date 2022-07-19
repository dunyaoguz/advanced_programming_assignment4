#include <typeinfo>
#include "Shape.h"

size_t Shape::counter = 1; 

Shape::Shape(std::string m_name, char m_pen, int m_height, int m_width) 
{
    name = m_name;
    pen = m_pen;
    height = m_height;
    width = m_width;
    id = counter;
    counter++;
}

std::string Shape::getName() const { return name; }

char Shape::getPen() const { return pen; }

int Shape::getId() const { return id; }

int Shape::getHeight() const { return height; }

int Shape::getWidth() const { return width;}

void Shape::setName(const std::string& m_name) { name = m_name; }

void Shape::setPen(const char& m_pen) { pen = m_pen; }

void Shape::setHeight(const int& m_height) { height = m_height; }

void Shape::setWidth(const int& m_width) { width = m_width; }

std::string Shape::toString() const
{
    std::string s0 = "Shape Information\n";
    std::string s1 = "-----------------\n";
    std::string s2 = "id: \t" + std::to_string(id) + "\n";
    std::string s3 = "Shape name: \t" + name + "\n";
    std::string s4 = "Pen character: \t" + pen + "\n";
    std::string s5 = "Height: \t" + std::to_string(height) + "\n";
    std::string s6 = "Width: \t" + std::to_string(width) + "\n";
    std::string s7 = "Textual area: \t" + std::to_string(this->areaScr()) + "\n";
    std::string s8 = "Textual perimeter: \t" + std::to_string(this->perimeterScr()) + "\n";
    std::string s9 = "Geometric area: \t" + std::to_string(this->areaGeo()) + "\n";
    std::string s10 = "Geometric perimeter: \t" + std::to_string(this->perimeterGeo()) + "\n";
    std::string s11 = "Static type: \n";
    std::string s11 = "Dynamic type: \n";
    return s0+s1+s2+s3+s4+s5+s6+s7+s8+s9+s10;
}

std::ostream &operator<<(std::ostream& output, const Shape& shapeToPrint)
{
    output << shapeToPrint.toString();
    return output;
}
