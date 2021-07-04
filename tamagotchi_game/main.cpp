#include <iostream>
#include "Tamagotchi.h"

using namespace tamagotchi;

int main()
{
  Interface *console = new Interface;
  console->run_game();
  delete console;

  system("pause");
  return 0;
}