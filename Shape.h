#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <iostream>
#include <ostream>

#include "Canvas.h"

class Shape 
{
    protected:
        std::string name;
        char pen;
        int id;
        size_t height;
        size_t width;
        static size_t counter; // used for id-ing Shapes

        Shape(size_t, size_t, std::string, char);

    public:
        std::string getName() const;
        char getPen() const;
        int getId() const; 
        size_t getHeight() const;
        size_t getWidth() const;

        void setName(const std::string&);
        void setPen(const char&);
        virtual void setHeight(const size_t&);
        virtual void setWidth(const size_t&);

        virtual double areaGeo() const = 0;
        virtual double perimeterGeo() const = 0;
        virtual int areaScr() const = 0;
        virtual int perimeterScr() const = 0;
        virtual Canvas draw() const = 0;

        std::string toString() const;

        virtual ~Shape(){};
};

std::ostream &operator<<(std::ostream&, const Shape&);

#endif