#include <iostream>
#include "Interface.h"
#include "Player.h"
#include "Frame.h"
#include "Exception.h"
#include "Convert.h"


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



  void Interface::show_menu()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_menu("Select action:\n"
                        "1. Feed\n"
                        "2. Play\n"
                        "3. Sleep\n"
                        "0. Terminated");

    delete frame;
    return;
  }



  void Interface::show_pet_list()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_menu("Select your pet:\n"
                        "1. Dog\n"
                        "2. Cat");
 
    delete frame;
    return;
  }



  void Interface::show_properties()
  {
    Pet *pet = this->get_player()->get_pet();

    std::string health =  myConvert::IntToString(pet->get_health());
    std::string hunger =  myConvert::IntToString(pet->get_hunger());
    std::string fatigue = myConvert::IntToString(pet->get_fatigue());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health =  " + health + "\n"
                              "Hunger =  " + hunger + "\n"
                              "Fatigue = " + fatigue);

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

    this->show_pet_list();
    this->player->choose_pet();

    while(player->get_pet()->is_sick() == false)
    {
      player->get_pet()->show_properties();
      this->show_menu();
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
    if(this->player == NULL)
      throw player_error();

    else
      return this->player;
  }
}