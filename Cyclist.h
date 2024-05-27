#pragma once

enum class ChildStatus { Child, NotChild, Unknown };
enum class GlassesStatus { HasGlasses, NoGlasses, Unknown };

class Cyclist : public Entity
{
private:
    ChildStatus childStatus;
    GlassesStatus glassesStatus;
    std::string bikeColor;

public:
    Cyclist(int xMin, int yMin, int xMax, int yMax, ChildStatus c, GlassesStatus g, const std::string& color)
        : Entity(xMin, yMin, xMax, yMax), childStatus(c), glassesStatus(g), bikeColor(color) {}

    void setChildStatus(ChildStatus c)
    { 
        childStatus = c;
    }
    ChildStatus getChildStatus() const 
    { 
        return childStatus; 
    }

    void setGlassesStatus(GlassesStatus g) 
    { 
        glassesStatus = g;
    }
    GlassesStatus getGlassesStatus() const 
    {
        return glassesStatus;
    }

    void setBikeColor(const std::string& color)
    {
        bikeColor = color;
    }
    std::string getBikeColor() const
    { 
        return bikeColor;
    }

    void display() const override 
    {
        Entity::display();
        std::cout << "Type: Cyclist\n";
        std::cout << "Child: " << (childStatus == ChildStatus::Child ? "Yes" : (childStatus == ChildStatus::NotChild ? "No" : "Unknown")) << "\n";
        std::cout << "Glasses: " << (glassesStatus == GlassesStatus::HasGlasses ? "Yes" : (glassesStatus == GlassesStatus::NoGlasses ? "No" : "Unknown")) << "\n";
        std::cout << "Bike Color: " << bikeColor << "\n";
    }

    std::string getType() const override 
    {
        return "Cyclist";
    }
};
