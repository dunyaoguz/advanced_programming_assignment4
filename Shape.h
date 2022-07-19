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
        int height;
        int width;
        static size_t counter; // used for id-ing Shapes

        Shape(int, int, std::string, char);

    public:
        std::string getName() const;
        char getPen() const;
        int getId() const; 
        int getHeight() const;
        int getWidth() const;

        void setName(const std::string&);
        void setPen(const char&);
        virtual void setHeight(const int&);
        virtual void setWidth(const int&);

        virtual double areaGeo() const = 0;
        virtual double perimeterGeo() const = 0;
        virtual int areaScr() const = 0;
        virtual int perimeterScr() const = 0;
        virtual Canvas draw() const = 0;

        std::string toString() const;

        virtual ~Shape(){};
};

std::ostream &operator<<(std::ostream &, const Shape &);

#endif