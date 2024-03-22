/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** main
*/

#include "loader/DLLoader.hpp"

int main(void)
{
  DLLoader loader;

  try {
    loader.loadLibraries("./lib");
    std::cout << "Games libraries:" << loader.getGamesLibraries().size() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
