#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 separatingForce = Vector2::zero();

    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;
        int countCloseFlockmates = 0;

    }

    if (!neighborhood.empty())
    {
        for (std::vector<Boid*>::const_iterator itr = neighborhood.begin(); itr != neighborhood.end(); itr++)
        {
            if (*itr != boid)
            {
                separatingForce.x += (*itr)->transform.position.x - boid->transform.position.x;
                separatingForce.y += (*itr)->transform.position.y - boid->transform.position.y;
            }
        }
        separatingForce.x = separatingForce.x / neighborhood.size();
        separatingForce.y = separatingForce.y / neighborhood.size();
    }

    separatingForce.x *= -1;
    separatingForce.y *= -1;

    separatingForce = Vector2::normalized(separatingForce);

    return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
