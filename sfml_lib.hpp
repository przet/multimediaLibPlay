#ifndef SFML_LIB__H
#define SFML_LIB__H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
void func()
{
    for (int i = 0; i < 10; ++i)
        std::cout << "I am thread number one!" << std::endl;
}
void func2(int x)
{
    int i = 10;
    while (i > 0)
    {
        std::cout << x++ << std::endl;
        i--;
    }
}
class MyClass
{
public:
    void func()
    {
        for (int i = 0; i < 10; ++i)
            std::cout << "I have thread entry point into a member function !" << std::endl;
    }
};

struct MyFunctor
{

    void operator()()
    {
        for (int i = 0; i < 10; ++i)
            std::cout << "I have thread entry point into a functor! " << std::endl;

    }
};

struct MyFunctor2
{

    void operator()(int x)
    {
        if (x == 4)
            for (int i = 0; i < 10; ++i)
                std::cout << "I have thread entry point into a functor, FUNCTOR NUMBER 2! " << std::endl;
        else
            std::cout << "I have thread entry point into a function BUT the argument is NOT 4" << std::endl;

    }
};

struct MyFunctor3
{

    void operator()()
    {
        for (int i = 0; i < 10; ++i)
            std::cout << "I have thread entry point into a functor, NuMbEr threeeeee! " << std::endl;

    }
};

void updateGame(sf::Clock& clock, sf::Time& elapsed, sf::RenderWindow& window,
    sf::CircleShape &shape)
{

    sf::ConvexShape shape2(300);
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



#endif // !SFML_LIB__H

