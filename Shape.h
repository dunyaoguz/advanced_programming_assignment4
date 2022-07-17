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

        Shape(std::string, char);

    public:
        std::string getName() const;
        char getPen() const;
        int getId() const; 
        int getHeight() const;
        int getWidth() const;

        void setName(const std::string&);
        void setPen(const char&);

        virtual int areaGeo() const;
        virtual int perimeterGeo() const;
        virtual int areaScr() const;
        virtual int perimeterScr() const;
        virtual Canvas draw() const;

        std::string toString() const;

        virtual ~Shape(){};
};

std::ostream &operator<<(std::ostream &, const Shape &);

#endif