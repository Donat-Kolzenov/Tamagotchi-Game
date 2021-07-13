// Player header
// Copyright (c) Donat Kolzenov.

#ifndef PLAYER_H
#define PLAYER_H
#include "Pet.hpp"


namespace tamagotchi
{
  class Player
  {
    public:
      void show_pet_list();
      void choose_pet();
    
    public:
      Pet* get_pet();

    private:
      Pet *pet;

    public:
      Player();
      ~Player();
  };
}

#endif  // PLAYER_H