#ifndef RHOMBUS_H_
#define RHOMBUS_H_

#include <string>
#include "Shape.h"

class Rhombus : public Shape
{
    public:
        Rhombus(int, std::string = "Diamond", char = '*');

        virtual void setHeight(const int &) override;
        virtual void setWidth(const int &) override;

        virtual double areaGeo() const override;
        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~Rhombus(){};
};

#endif