// Interface header
// Copyright (c) Donat Kolzenov.

#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include "Player.h"


namespace tamagotchi
{
  class Interface
  {
    public:
      Interface();
      ~Interface();

    private:
      Player *player;

    public:
      void run_game();

    private:
      void welcome();
      void game_over();

      void create_player();
      Player* get_player();
  };
}

#endif  //INTERFACE_H