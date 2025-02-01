#include "lotka_volterra.h"
#include "grafica.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

int main() {
    constexpr float a = 1.0f, b = 0.1f, c = 1.5f, d = 0.075f;
    constexpr float dt = 0.1f;
    Population pop = {50.0f, 20.0f};

    sf::RenderWindow windowTiempo(sf::VideoMode(sf::Vector2u(800, 600)), "Evolucion en funcion del tiempo");
    sf::RenderWindow windowFase(sf::VideoMode(sf::Vector2u(800, 600)), "Diagrama de fases");

    std::vector<sf::Vertex> preyEvolution, predatorEvolution, phaseDiagram;
    int timeStep = 0;

    while (windowTiempo.isOpen() && windowFase.isOpen()) {
        // Manejo de eventos para la ventana de evolución temporal
        while (auto eventOpt = windowTiempo.pollEvent()) {
            if (eventOpt.has_value() && eventOpt->is<sf::Event::Closed>()) {
                windowTiempo.close();
            }
        }

        // Manejo de eventos para la ventana del diagrama de fases
        while (auto eventOpt = windowFase.pollEvent()) {
            if (eventOpt.has_value() && eventOpt->is<sf::Event::Closed>()) {
                windowFase.close();
            }
        }

        // Actualizar la población utilizando el modelo Lotka-Volterra
        pop = lotka_volterra(pop, dt, a, b, c, d);

        // Escalar los valores para ajustarlos a las ventanas
        float preyScaled = 100 + pop.x * 2;
        float predatorScaled = 500 - pop.y * 2;
        float timeX = timeStep % 700 + 50;

        // Almacenar los puntos para las gráficas
        if (timeStep < 700) {
            preyEvolution.emplace_back(sf::Vector2f(timeX, 600 - preyScaled), sf::Color::Blue);
            predatorEvolution.emplace_back(sf::Vector2f(timeX, 600 - predatorScaled), sf::Color::Red);
        }
        phaseDiagram.emplace_back(sf::Vector2f(100 + pop.x * 5, 500 - pop.y * 5), sf::Color::Green);

        // Dibujar la gráfica de evolución en función del tiempo
        windowTiempo.clear(sf::Color::White);
        graficarTiempo(windowTiempo, preyEvolution, predatorEvolution);
        windowTiempo.display();

        // Dibujar el diagrama de fases
        windowFase.clear(sf::Color::White);
        graficarFase(windowFase, phaseDiagram);
        windowFase.display();

        sf::sleep(sf::milliseconds(50));
        timeStep++;
    }

    return 0;
}
