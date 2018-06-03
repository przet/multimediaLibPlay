#include <SFML/Graphics.hpp>

void updateGame(sf::Clock& clock, sf::Time& elapsed, sf::RenderWindow& window,
        sf::CircleShape &shape)
{
    
    sf::ConvexShape shape2(300.f);
    elapsed = clock.getElapsedTime();
    while (elapsed.asSeconds() <10000)
    {
    window.clear();
    window.draw(shape);
    window.display();
    window.clear();
    window.draw(shape2);
    window.display();
    window.clear();
    
    elapsed += clock.getElapsedTime();
    }
}
void updateGame(sf::Clock& clock, sf::Time& elapsed, sf::RenderWindow& window,
        sf::CircleShape &shape);


int main()
{
    sf::Clock clock;
    sf::Time elapsed;
    sf::RenderWindow window(sf::VideoMode(200,200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        
        sf::Event event;
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        updateGame(clock, elapsed, window, shape);
    
    
    }
    //updateGame(elapsed);

    return 0;
}

