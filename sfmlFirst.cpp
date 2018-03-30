#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "sfml_lib.hpp"




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

