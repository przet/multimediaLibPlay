#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

void func()
{
    for (int i = 0;i < 10; ++i)
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
        for (int i = 0;i < 10; ++i)
            std::cout << "I have thread entry point into a member function !" << std::endl;
    }
};

struct MyFunctor
{

    void operator()()
    {
        for (int i = 0;i < 10; ++i)
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
        for (int i = 0;i < 10; ++i)
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


int main()
{
    
    sf::Thread thread(&func);
    thread.launch();
    sf::Thread thread2(&func2, 5);
    thread2.launch();
    MyClass myObject;
    sf::Thread thread3(&MyClass::func, &myObject);
    thread3.launch();
    MyFunctor myFunctorObj;
    sf::Thread thread4(myFunctorObj);
    thread4.launch();
    MyFunctor2 myFunctor2Obj;
    sf::Thread thread4_a(myFunctor2Obj, 4);
    thread4_a.launch();
    sf::Thread thread4_b((MyFunctor3())); //THIS works...but I need the extra parantheses around MyFunctor3()...otherwise, I will get an error expecting a class.
                                          //But the tutorials and docs on SFML all omit these paraenteses...I wonder if its compiler version?
    thread4_b.launch();
    sf::Thread thread5([]() {std::cout << "I have entry point via a lambda(which is just ss for a functor)" << std::endl;});
    thread5.launch();
    


    //main thread
    for (int i = 0; i < 10;++i)
        std::cout << "I am the main thread" << std::endl;
    //sf::Clock clock;
    //sf::Time elapsed;
    //sf::RenderWindow window(sf::VideoMode(200,200), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //while (window.isOpen())
    //{
    //    
    //    sf::Event event;
    //    sf::Time elapsed = clock.restart();
    //    while (window.pollEvent(event))
    //        if (event.type == sf::Event::Closed)
    //            window.close();

    //    updateGame(clock, elapsed, window, shape);
    //
    //
    //}
    ////updateGame(elapsed);
    system("pause");
    return 0;
}

