/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "loader/Loader.hpp"

int main(void)
{
  Loader loader;

  try {
    loader.loadLibraries("./lib");
    std::cout << "Games libraries:" << loader.getGamesLibraries().size() << std::endl;
    std::cout << "Graphics libraries:" << loader.getGraphicsLibraries().size() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
