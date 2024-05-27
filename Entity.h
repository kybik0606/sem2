#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Entity 
{
protected:
    int Xmin, Ymin, Xmax, Ymax;

public:
    Entity(int xMin, int yMin, int xMax, int yMax)
    {
        setCoordinates(xMin, yMin, xMax, yMax);
    }

    virtual ~Entity() {}

    void setCoordinates(int xMin, int yMin, int xMax, int yMax) 
    {
        if (xMin < 0 || yMin < 0 || xMax < xMin || yMax < yMin) 
        {
            throw std::invalid_argument("Invalid coordinates");
        }
        Xmin = xMin;
        Ymin = yMin;
        Xmax = xMax;
        Ymax = yMax;
    }

    int getXmin() const
    { 
        return Xmin; 
    }
    int getYmin() const
    {
        return Ymin; 
    }
    int getXmax() const 
    { 
        return Xmax; 
    }
    int getYmax() const
    { 
        return Ymax;
    }

    virtual void display() const
    {
        std::cout << "Entity: (" << Xmin << ", " << Ymin << ") - (" << Xmax << ", " << Ymax << ")\n";
    }

    virtual std::string getType() const = 0;
};
