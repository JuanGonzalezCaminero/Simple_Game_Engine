This is a simple 2D game engine written in C++ using the SDL library. It was designed and implemented from scratch as a self-learning project.

Many features are still missing and will most likely remain so as the project was meant mainly as a place to test and learn C++ and related technologies such as gtest or Cmake, it contains some design flaws that would need refactoring part of the project and it is not a priority right now.

Nevertheless, a demo can be compiled and run using the CMakeLists found at the project's root, which shows the intended usage of the library.

## Design

This diagram shows the overall design of the library

 <img src="/doc/diagram.png" width="80%" />
 
 - Shown in blue are the input handling-related classes. The Observer pattern is used, the InputHandler class processes raw inputs and classifies them into different GameEvent types, the InputComponent observers, associated to the different elements in the game are notified and updated accordingly.
 - The elements of a game, the GameObjects, use the Component pattern, where the GameObject class contains some attributes and functions that are essential to every element, and different components can be added to them in order to extend their functionality.
 - The GameObjects themselves are structured according to a Composite pattern, where an entity can be either simple, or contain other entities.
