#ifndef LOTKA_VOLTERRA_H
#define LOTKA_VOLTERRA_H

struct Population {
    float x;  
    float y;  
};

Population lotka_volterra(Population pop, float dt, float a, float b, float c, float d);

#endif
