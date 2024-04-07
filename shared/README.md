# 📦 Arcade Shared Library
Shared library for Arcade project

## Description
This library contains shared code for the Arcade project in order to unify interfaces between collaborative groups.

## Groups
 - **[G-Epitech](https://github.com/G-Epitech/FMY-Arcade)** : [Flavien Chenu](https://github.com/flavien-chenu), [Math](https://github.com/tekmath) & [Yann Masson](https://github.com/Yann-Masson)

 - **[Carapace Retro](https://github.com/G-Epitech)** : [Baptiste Moreau](https://github.com/BxptisteM), [Axel Fradet](https://github.com/AxelF44) & [Suceveanu Dragos](https://github.com/sdragos1)

## How ?

Our arcade simulator relies on a modular development model, utilizing dynamic libraries to separate game logic from graphical display. This system revolves around two types of libraries: game libraries and graphical libraries. These two libraries operate entirely independently, focusing solely on the principle of getters and setters for data manipulation.

1. Game Libraries:

Game libraries are responsible for managing the internal game logic, including gameplay mechanics, collisions, levels, and more. They provide functionalities through getter and setter methods, allowing developers to access and modify game data as needed.

2. Graphical Libraries:

On the other hand, graphical libraries handle the visual display of the game. They include features such as sprite rendering, animation management, and special effects. These libraries also interact with the simulator solely through getter and setter methods, enabling the modification of visual properties of game elements.

3. Core:

To ensure consistency and communication between game libraries and graphical libraries, a "core" is necessary. This core acts as a central liaison, coordinating game data with graphical display. It retrieves information about the game state from game libraries and passes it to graphical libraries for display. Similarly, it monitors user interactions and updates game data accordingly, ensuring a smooth gaming experience.

In summary, our arcade simulator relies on a modular development model where game libraries, graphical libraries, and the core interact independently, providing maximum flexibility and enabling developers to create unique and dynamic gaming experiences.

## Documentation

If you want the code documentation you can run this command :

```bash
doxygen Doxyfile
```

This command allow you to generate Doxygen documentation.
