#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood
    if (!neighborhood.empty())
    {
        for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
        {
            if (*itr != boid)
            {
                cohesionForce.x += (*itr)->transform.position.x;
                cohesionForce.y += (*itr)->transform.position.y;
            }
        }
        cohesionForce.x = cohesionForce.x / neighborhood.size();
        cohesionForce.y = cohesionForce.y / neighborhood.size();
    }

    cohesionForce.x = cohesionForce.x - boid->transform.position.x;
    cohesionForce.y = cohesionForce.y - boid->transform.position.y;
    Vector2::normalized(cohesionForce);

    return cohesionForce;
}