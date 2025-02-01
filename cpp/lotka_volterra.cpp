#include "lotka_volterra.h"

// Implementación de la función Lotka-Volterra
Population lotka_volterra(Population pop, float dt, float a, float b, float c, float d) {
    float dx = (a * pop.x - b * pop.x * pop.y) * dt;
    float dy = (d * pop.x * pop.y - c * pop.y) * dt;
    return { pop.x + dx, pop.y + dy };
}