#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();
    
    if (!neighborhood.empty())
    {
        for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
        {
            if (*itr != boid)
            {
                averageVelocity += (*itr)->Particle::getVelocity();
            }
        }
        averageVelocity /= neighborhood.size();
    }
    
    return Vector2::normalized(averageVelocity);
}