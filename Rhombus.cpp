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
    // at 0: draw 1 (17 = 1 + 2*8) @ 9 (1+0*2)
    // at 1: draw 3 (17 = 3 + 2*7) @ 8, 9, 10 (1+1*2)
    // at 2: draw 5 (17 = 5 + 2*6) @ 7, 8, 9, 10, 11 (1+2*2)
    // at 3: draw 7 (17 = 7 + 2*5) @ 6, 7, 8, 9, 10, 11, 12
    // at 4: draw 9 (17 = 9 + 2*4) @ 5, 6, 7, 8, 9, 10, 11, 12, 13
    // at 5: draw 11 (17 = 11 + 2*3) @ 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
    // at 6: draw 13 (17 = 13 + 2*2) @ 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    // at 7: draw 15 (17 = 15 + 2*1) @ 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    // at 8: draw 17 (17 = 17 + 2*0) @ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
    // at 9: draw 15 (15 = 17 - 2*1)
    // at 10: draw 13 (13 = 17 - 2*2)
    // at 11: draw 11 (11 = 17 - 2*3)
    // at 12: draw 9 (9 = 17 - 2*4)
    // at 13: draw 7 (7 = 17 - 2*5)
    // at 14: draw 5 (5 = 17 - 2*6)
    // at 15: draw 3 (3 = 17 - 2*7)
    // at 16: draw 1 (1 = 17 - 2*8)  
    for(int row = 0; row < height; row++)
    {
        int midpoint = height/2;
        if(row < midpoint) 
        {
            int no_chars = 1 + row*2;
            can.put(row, midpoint, pen); 
            // when no_chars = 1: 0 iterations
            // when no_chars = 3: 1 iterations (put at 8, 10)
            // when no_chars = 5: 2 iterations (put at 8, 10, 7, 11)
            for(int i = 1; i < no_chars; i+=2)
            {
                can.put(row, midpoint-i, pen); 
                can.put(row, midpoint+i, pen); 
            }
        }
        else if (row > midpoint)
        {
            int no_chars = 17 - 2*(row-midpoint);
            can.put(row, midpoint, pen); 
            for(int i = 1; i < no_chars; i+=2) 
            {
                can.put(row, midpoint-i, pen); 
                can.put(row, midpoint+i, pen); 
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

