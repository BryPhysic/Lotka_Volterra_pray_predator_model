#ifndef GRAFICA_H
#define GRAFICA_H

#include <SFML/Graphics.hpp>
#include <vector>

void graficarTiempo(sf::RenderWindow& window, const std::vector<sf::Vertex>& preyEvolution, 
                     const std::vector<sf::Vertex>& predatorEvolution);

void graficarFase(sf::RenderWindow& window, const std::vector<sf::Vertex>& phaseDiagram);

#endif
