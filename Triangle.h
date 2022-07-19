#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <string>
#include "Shape.h"

class Triangle : public Shape
{
    protected:
        Triangle(int, int, std::string, char);

    public:
        virtual double areaGeo() const override;
        virtual ~Triangle(){};
};

#endif