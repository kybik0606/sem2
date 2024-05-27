#pragma once

#include <stdexcept>

class UnattendedBag : public Entity
{
private:
    int firstSeenTime;

public:
    UnattendedBag(int xMin, int yMin, int xMax, int yMax, int timeSeen)
        : Entity(xMin, yMin, xMax, yMax)
    {
        setFirstSeenTime(timeSeen);
    }

    void setFirstSeenTime(int timeSeen)
    {
        if (timeSeen < 0 || timeSeen >= 86400)
        {
            throw std::invalid_argument("Invalid time of day");
        }
        firstSeenTime = timeSeen;
    }

    int getFirstSeenTime() const
    { 
        return firstSeenTime;
    }

    void display() const override
    {
        Entity::display();
        std::cout << "Type: Unattended Bag\n";
        std::cout << "First Seen Time: " << firstSeenTime << " seconds after midnight\n";
    }

    std::string getType() const override 
    {
        return "Unattended Bag";
    }
};
