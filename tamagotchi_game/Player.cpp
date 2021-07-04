#include <iostream>
#include "conio.h"      // for getch()
#include "Player.h"
#include "Exception.h"


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
          break;
        }
        case '2':
        {
          system("cls");
          this->pet = new Cat;
          break;
        }
        default:
        {
          std::cout << "Enter wrong key!" << std::endl;
          break;
        }
      }
    }
    return;
  }



  void Player::choose_action()
  {
    switch(_getch())
    {
      case '1':
      {
        system("cls");
        this->pet->feed();
        break;
      }

      case '2':
      {
        system("cls");
        this->pet->play();
        break;
      }

      case '3':
      {
        system("cls");
        this->pet->sleep();
        break;
      }

      case '0':
      {
        throw game_over();
        break;
      }

      default:
      {
        system("cls");
        std::cout << "Enter wrong key!" << std::endl;
        break;
      }
    }
    return;
  }
}