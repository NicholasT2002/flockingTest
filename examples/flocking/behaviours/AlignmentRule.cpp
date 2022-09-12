#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood
    
    if (!neighborhood.empty())
    {
        for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
        {
            if (*itr != boid)
            {
                averageVelocity.x += (*itr)->Particle::getVelocity().x;
                averageVelocity.y += (*itr)->Particle::getVelocity().y;
            }
        }
        averageVelocity.x = averageVelocity.x / neighborhood.size();
        averageVelocity.y = averageVelocity.y / neighborhood.size();
    }
    
    return Vector2::normalized(averageVelocity);
}