#include <typeinfo>
#include "Shape.h"

size_t Shape::counter = 1; 

Shape::Shape(int m_height, int m_width, std::string m_name, char m_pen) 
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
    std::string t1 = typeid(this).name();
    std::string t2 = typeid(*this).name();

    std::string info = 
        "\nShape Information\n-----------------\n"
        "id: " + std::to_string(id) + "\n"
        "Shape name: " + name + "\n"
        "Pen character: " + std::to_string(pen) + "\n"
        "Height: " + std::to_string(height) + "\n"
        "Width: " + std::to_string(width) + "\n"
        "Textual area: " + std::to_string(this->areaScr()) + "\n"
        "Textual perimeter: " + std::to_string(this->perimeterScr()) + "\n"
        "Geometric area: " + std::to_string(this->areaGeo()) + "\n"
        "Geometric perimeter: " + std::to_string(this->perimeterGeo()) + "\n"
        "Static type: " + t1 + "\n"
        "Dynamic type: " + t2 + "\n";
    return info;
}

std::ostream &operator<<(std::ostream& output, const Shape& shapeToPrint)
{
    output << shapeToPrint.toString();
    return output;
}
