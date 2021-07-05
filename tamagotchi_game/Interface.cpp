#include <iostream>
#include "Interface.h"
#include "Player.h"
#include "Frame.h"
#include "Exception.h"


namespace tamagotchi
{
  Interface::Interface()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Interface> " << this << std::endl;
    #endif
    this->player = NULL;
  }



  Interface::~Interface()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Interface> " << this << std::endl;
    #endif
    if(this->player != NULL)
      delete this->player;
  }



  void Interface::welcome()
  {
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_notice("Welcome to Tamagotchi Game!");
    delete frame;

    return;
  }



  void Interface::game_over()
  {
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_notice("GAME OVER");
    delete frame;

    return;  
  }



  void Interface::run_game()
  {
    this->welcome();

    this->create_player();

    player->show_pet_list();
    player->choose_pet();

    while(player->get_pet()->is_healthy())
    {
      player->get_pet()->show_properties();
      player->get_pet()->show_actions();
      player->choose_action();
    }
    this->game_over();

    return;
  }



  void Interface::create_player()
  {
    if(this->player == NULL)
      this->player = new Player;
      
    return;
  }



  Player* Interface::get_player()
  {
    try
    {
      if(this->player == NULL)
        throw player_error();

      else
        return this->player;
    }
    catch(const player_error& ex)
    {
      std::cerr << ex.what() << std::endl;
    }
  }
}