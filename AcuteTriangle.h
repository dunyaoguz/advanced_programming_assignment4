#ifndef ACUTETRIANGLE_H_
#define ACUTETRIANGLE_H_

#include <string>
#include "Triangle.h"

class AcuteTriangle : public Triangle
{
    public:
        AcuteTriangle(size_t, char = '*', std::string = "Wedge");

        virtual void setHeight(const size_t&) override;

        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~AcuteTriangle(){};
};

#endif