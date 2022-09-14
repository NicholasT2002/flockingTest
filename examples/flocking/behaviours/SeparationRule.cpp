#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include <iostream>

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    if (neighborhood.empty())
        return Vector2::zero();
    
    int closestFlockmates = 0;
    Vector2 force = Vector2::zero();

    // Find the closest ones
    for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
    {
        float distance = Vector2::getDistance((*itr)->transform.position, boid->transform.position);
        if (distance < desiredMinimalDistance)
        {
            closestFlockmates++;

            //Apply force
            if (distance < 0.01)
            {
                distance = 0.01;
            }

            force  += (boid->transform.position - (*itr)->transform.position) / distance;
        }
    }
    if (closestFlockmates == 0)
    {
        return Vector2::zero();
    }

    // Calculate the center of mass
    force /= closestFlockmates;

    return Vector2::normalized(force);
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
