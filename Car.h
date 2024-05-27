#pragma once

#include <string>
#include <stdexcept>

class Car : public Entity 
{
private:
    std::string color;
    std::string licensePlate;
    bool isTaxi;

public:
    Car(int xMin, int yMin, int xMax, int yMax, const std::string& carColor, const std::string& plate, bool taxi)
        : Entity(xMin, yMin, xMax, yMax), color(carColor), licensePlate(plate), isTaxi(taxi) {}

    void setColor(const std::string& carColor) 
    { 
        color = carColor;
    }
    std::string getColor() const 
    { 
        return color;
    }

    void setLicensePlate(const std::string& plate) 
    { 
        licensePlate = plate; 
    }
    std::string getLicensePlate() const
    { 
        return licensePlate; 
    }

    void setIsTaxi(bool taxi)
    { 
        isTaxi = taxi; 
    }
    bool getIsTaxi() const 
    { 
        return isTaxi; 
    }

    void display() const override
    {
        Entity::display();
        std::cout << "Type: Car\n";
        std::cout << "Color: " << color << "\n";
        std::cout << "License Plate: " << licensePlate << "\n";
        std::cout << "Taxi: " << (isTaxi ? "Yes" : "No") << "\n";
    }

    std::string getType() const override 
    {
        return "Car";
    }
};
