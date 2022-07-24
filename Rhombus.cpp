#include <cmath>

#include "Rhombus.h"
#include "Canvas.h"

Rhombus::Rhombus(size_t d, char m_pen, std::string m_name) : Shape(d, d, m_name, m_pen) 
{
    (*this).setHeight(d);
    (*this).setWidth(d);
};

void Rhombus::setHeight(const size_t& m_height)
{
    if(m_height%2 == 1) { height=m_height; }
    else { height=m_height+1; }
}

void Rhombus::setWidth(const size_t& m_width)
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

Canvas Rhombus::draw() const 
{
    Canvas can{height, width};
    // example: height = 17
    // at 0: draw 1 (17 = 1 + 2*8)
    // at 1: draw 3 (17 = 3 + 2*7) 
    // at 2: draw 5 (17 = 5 + 2*6)
    // ...
    // at 8: draw 17 (17 = 17 + 2*0)
    // ...
    // at 14: draw 5 (5 = 17 - 2*6)
    // at 15: draw 3 (3 = 17 - 2*7)
    // at 16: draw 1 (1 = 17 - 2*8)  
    for(int row = 0; row < height; row++)
    {
        int midpoint = height/2;
        if(row < midpoint) 
        {
            int no_chars = 1 + row*2;            
            // calculate the number of empty chars on each side 
            int empty_chars = (height - no_chars)/2; 
            for(int i = 0; i < height; i++)
            {
                if(i >= empty_chars && i < (height - empty_chars))
                {
                    can.put(row, i, pen); 
                }
            }
        }
        else if (row > midpoint)
        {
            int no_chars = height - 2*(row-midpoint);
            int empty_chars = (height - no_chars)/2; 
            for(int i = 0; i < height; i++)
            {
                if(i >= empty_chars && i < (height - empty_chars))
                {
                    can.put(row, i, pen); 
                }
            }
        }
        else if (row == midpoint)
        {
            for(int col = 0; col < width; col++) 
            {
                can.put(row, col, pen);
            }
        }
    }
    return can;
}

