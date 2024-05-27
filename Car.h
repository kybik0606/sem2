#pragma once

class Car : public Entity {
private:
    std::string color;
    std::string licensePlate;
    bool isTaxi;

public:
    Car(int xMin, int yMin, int xMax, int yMax, const std::string& carColor, const std::string& plate, bool taxi)
        : Entity(xMin, yMin, xMax, yMax), color(carColor), licensePlate(plate), isTaxi(taxi) {}

    void display() const override {
        Entity::display();
        std::cout << "Type: Car\n";
        std::cout << "Color: " << color << "\n";
        std::cout << "License Plate: " << licensePlate << "\n";
        std::cout << "Taxi: " << (isTaxi ? "Yes" : "No") << "\n";
    }

    std::string getType() const override {
        return "Car";
    }
};
