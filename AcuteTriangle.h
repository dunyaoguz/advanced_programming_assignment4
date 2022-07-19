#ifndef ACUTETRIANGLE_H_
#define ACUTETRIANGLE_H_

#include <string>
#include "Triangle.h"

class AcuteTriangle : public Triangle
{
    public:
        AcuteTriangle(int, std::string = "Wedge", char = '*');

        virtual void setHeight(const int&) override;

        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~AcuteTriangle(){};
};

#endif