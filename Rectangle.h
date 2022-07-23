#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <string>
#include "Shape.h"

class Rectangle : public Shape
{
    public:
        Rectangle(int, int, char = '*', std::string = "Rectangle");

        virtual double areaGeo() const override;
        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~Rectangle(){};
};

#endif