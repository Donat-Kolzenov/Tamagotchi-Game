// Player header
// Copyright (c) Donat Kolzenov.

#ifndef PLAYER_H
#define PLAYER_H
#include "Pet.h"


namespace tamagotchi
{
  class Player
  {
    public:
      Player();
      ~Player();

    private:
      Pet *pet;

    public:
      Pet* get_pet();
      
      void choose_pet();
      void choose_action();
  };
}

#endif  //PLAYER_H