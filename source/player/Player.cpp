#include <iostream>
#include "conio.h"      // for _getch()
#include "Player.hpp"
#include "Pet.hpp"
#include "Exception.hpp"
#include "Frame.hpp"


namespace tamagotchi
{
  Player::Player()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Player> " << this << std::endl;
    #endif

    this->pet = NULL;
  }



  Player::~Player()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Player> " << this << std::endl;
    #endif

    if(this->pet != NULL)
        delete this->pet;
  }



  Pet* Player::get_pet()
  {
    return this->pet;
  }



  void Player::show_pet_list()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_menu("Select your pet:\n"
                        "1. Dog\n"
                        "2. Cat");
 
    delete frame;
    return;
  }



  void Player::choose_pet()
  {
    while(this->pet == NULL)
    {
      switch(_getch())
      {
        case '1':
        {
          system("cls");
          this->pet = new Dog;
          CustomFrame frame;
          frame.wrap_in_notice(" Dog ");
          break;
        }

        case '2':
        {
          system("cls");
          this->pet = new Cat;
          CustomFrame frame;
          frame.wrap_in_notice(" Cat ");
          break;
        }
      }
    }
    return;
  }
}