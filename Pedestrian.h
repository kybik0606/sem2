#pragma once

enum class Gender { Male, Female, Undefined };
enum class BeardStatus { HasBeard, NoBeard, Unknown };

class Pedestrian : public Entity
{
private:
    Gender gender;
    BeardStatus beardStatus;

public:
    Pedestrian(int xMin, int yMin, int xMax, int yMax, Gender g, BeardStatus b)
        : Entity(xMin, yMin, xMax, yMax), gender(g), beardStatus(b) {}

    void setGender(Gender g) 
    {
        gender = g;
    }
    Gender getGender() const 
    { 
        return gender; 
    }

    void setBeardStatus(BeardStatus b)
    { 
        beardStatus = b; 
    }
    BeardStatus getBeardStatus() const 
    { 
        return beardStatus;
    }

    void display() const override
    {
        Entity::display();
        std::cout << "Type: Pedestrian\n";
        std::cout << "Gender: " << (gender == Gender::Male ? "Male" : (gender == Gender::Female ? "Female" : "Undefined")) << "\n";
        std::cout << "Beard: " << (beardStatus == BeardStatus::HasBeard ? "Has Beard" : (beardStatus == BeardStatus::NoBeard ? "No Beard" : "Unknown")) << "\n";
    }

    std::string getType() const override 
    {
        return "Pedestrian";
    }
};
