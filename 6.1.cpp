#include <iostream>
#include "Entity.h"
#include "Pedestrian.h"
#include "Cyclist.h"
#include "Car.h"
#include "UnattendedBag.h"

int main() 
{
    Pedestrian p(10, 20, 30, 40, Gender::Male, BeardStatus::NoBeard);
    Cyclist c(50, 60, 70, 80, ChildStatus::NotChild, GlassesStatus::HasGlasses, "Red");
    Car car(90, 100, 110, 120, "Blue", "123ABC", true);
    UnattendedBag bag(130, 140, 150, 160, 3600);

    Entity* entities[] = { &p, &c, &car, &bag };

    for (Entity* e : entities) 
    {
        e->display();
        std::cout << std::endl;
    }
    return 0;
}
