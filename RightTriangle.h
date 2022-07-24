#ifndef RIGHTTRIANGLE_H_
#define RIGHTTRIANGLE_H_

#include <string>
#include "Triangle.h"

class RightTriangle : public Triangle
{
    public:
        RightTriangle(size_t, char = '*', std::string = "Ladder");

        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~RightTriangle(){};
};

#endif