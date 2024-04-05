/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "Core.hpp"
#include "loader/Loader.hpp"

int main(int ac, char **av)
{
  Loader loader;

  if (ac != 2) {
    std::cerr << "Usage: ./arcade path_to_lib" << std::endl;
    return 84;
  }
  try {
    loader.loadLibraries("./lib");
    auto &games = loader.getGamesLibraries();
    auto &graphics = loader.getGraphicsLibraries();
    auto it = graphics.find(av[1]);
    if (it == graphics.end()) {
      std::cerr << "Game library not found" << std::endl;
      return 84;
    }
    Core core(games, graphics);
    core.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 84;
  }
  return 0;
}
