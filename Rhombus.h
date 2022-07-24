#ifndef RHOMBUS_H_
#define RHOMBUS_H_

#include <string>
#include "Shape.h"

class Rhombus : public Shape
{
    public:
        Rhombus(size_t, char = '*', std::string = "Diamond");

        virtual void setHeight(const size_t&) override;
        virtual void setWidth(const size_t&) override;

        virtual double areaGeo() const override;
        virtual double perimeterGeo() const override;
        virtual int areaScr() const override;
        virtual int perimeterScr() const override;
        
        virtual Canvas draw() const override;

        virtual ~Rhombus(){};
};

#endif