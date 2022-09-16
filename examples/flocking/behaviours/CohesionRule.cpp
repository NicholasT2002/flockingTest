#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    if (!neighborhood.empty())
    {
        for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
        {
            if (*itr != boid)
            {
                cohesionForce += ((*itr)->transform.position - boid->transform.position);
            }
        }
        cohesionForce = cohesionForce / neighborhood.size();
    }

    return Vector2::normalized(cohesionForce);
}