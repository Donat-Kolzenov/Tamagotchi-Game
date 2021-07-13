#include <iostream>
#include "Tamagotchi.hpp"

using namespace tamagotchi;


int main()
{
  Console *console = new Console;
  console->run_game();
  delete console;

  system("pause");
  return 0;
}