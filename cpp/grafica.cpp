#include "grafica.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void dibujarEjes(sf::RenderWindow& window) {
    sf::Vertex ejeX[] = {sf::Vertex(sf::Vector2f(50, 300), sf::Color::Black),
                         sf::Vertex(sf::Vector2f(750, 300), sf::Color::Black)};
    sf::Vertex ejeY[] = {sf::Vertex(sf::Vector2f(400, 50), sf::Color::Black),
                         sf::Vertex(sf::Vector2f(400, 550), sf::Color::Black)};
    window.draw(ejeX, 2, sf::PrimitiveType::Lines);
    window.draw(ejeY, 2, sf::PrimitiveType::Lines);
}

void graficarTiempo(sf::RenderWindow& window, const std::vector<sf::Vertex>& preyEvolution, 
                    const std::vector<sf::Vertex>& predatorEvolution) {
    window.clear(sf::Color::Black);
    dibujarEjes(window);

    std::cout << "Prey size: " << preyEvolution.size() << " | Predator size: " << predatorEvolution.size() << std::endl;

    if (preyEvolution.size() > 1) {
        window.draw(preyEvolution.data(), preyEvolution.size(), sf::PrimitiveType::LineStrip);
    }
    if (predatorEvolution.size() > 1) {
        window.draw(predatorEvolution.data(), predatorEvolution.size(), sf::PrimitiveType::LineStrip);
    }
    window.display();
}

void graficarFase(sf::RenderWindow& window, const std::vector<sf::Vertex>& phaseDiagram) {
    window.clear(sf::Color::Black);
    dibujarEjes(window);

    std::cout << "Phase size: " << phaseDiagram.size() << std::endl;

    if (phaseDiagram.size() > 1) {
        window.draw(phaseDiagram.data(), phaseDiagram.size(), sf::PrimitiveType::LineStrip);
    }
    window.display();
}
