/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include <filesystem>
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
    auto libName = std::filesystem::canonical(av[1]).string();
    auto it = graphics.find(libName);
    if (it == graphics.end())
      throw ArcadeError("No such graphics library: " + libName);
    Core core(games, graphics, libName);
    core.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 84;
  }
  return 0;
}
