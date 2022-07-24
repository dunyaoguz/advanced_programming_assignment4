#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <string>
#include "Shape.h"

class Triangle : public Shape
{
    protected:
        Triangle(size_t, size_t, std::string, char);

    public:
        virtual double areaGeo() const override;
        virtual ~Triangle(){};
};

#endif