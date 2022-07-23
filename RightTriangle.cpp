#include <cmath>

#include "RightTriangle.h"
#include "Canvas.h"

RightTriangle::RightTriangle(int b, char m_pen, std::string m_name) : Triangle(b, b, m_name, m_pen) {}

double RightTriangle::perimeterGeo() const { return (2 + std::sqrt(2))*height; }

int RightTriangle::areaScr() const { return (height*(height+1))/2; }

int RightTriangle::perimeterScr() const { return 3*(height-1); }

Canvas RightTriangle::draw() const 
{
    Canvas can{height, width};

    // iterate over each row
    for (size_t row = 0; row < height; row++)
    {
        // iterate over each column
        for (size_t col = 0; col < width; col++)
        {
            // at 0: only draw at 0 
            // at 1: only draw at 0 and 1
            // at 2: only draw at 0, 1 and 2
            // ...
            // at n: draw at 0...n
            if (col <= row)
            {
                can.put(row, col, pen);
            }
        }
    }
    return can;
}