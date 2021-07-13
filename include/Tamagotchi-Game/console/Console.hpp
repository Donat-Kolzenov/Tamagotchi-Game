// Console header
// Copyright (c) Donat Kolzenov.

#ifndef CONSOLE_H
#define CONSOLE_H
#include "Player.hpp"


namespace tamagotchi
{
  class Console
  {
    public:
      void run_game();

    private:
      void show_welcome();
      void show_game_rules();
      void show_game_over();
      void set_size(const int height, const int width);

    private:
      Player *player;

    private:
      enum DefaultSize  // in pixels
      {
        HEIGHT = 350,
        WIDTH = 395
      };

    public:
      Console();
      ~Console();
  };
}

#endif  // CONSOLE_H