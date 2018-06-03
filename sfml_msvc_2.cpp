#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
//Global mutex
sf::Mutex mutex;

//Function Declarations
void renderingThread(sf::RenderWindow*);
void drawingThread(sf::CircleShape*);
int main()
{
    //Better to create window in main thread
    sf::RenderWindow window1(sf::VideoMode(600, 400),"OpenGL");

    //Deactivate window1 OpenGL context. TODO: what does this mean?
    window1.setActive(false);

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition(shape.getPosition().x+225, shape.getPosition().y+125);

    sf::Thread thread1(&renderingThread, &window1);
    thread1.launch();
    while (window1.isOpen())
    {
        sf::Event event;
        while (window1.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window1.close();
               
        }
    }

    









    return 0;
}

//Function Definitions
void renderingThread(sf::RenderWindow *some_window);
{
    mutex.lock();
    
    
    
    while (some_window->isOpen())
    {
       
        //draw
        some_window->clear(sf::Color::Black);
        some_window->draw(*some_circleShape);
        

        //end the current frame
        some_window->display();

        
    }
    mutex.unlock();
}

void drawingThread(sf::CircleShape *some_circleShape)