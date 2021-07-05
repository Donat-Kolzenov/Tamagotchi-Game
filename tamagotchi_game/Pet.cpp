#include <iostream>
#include <conio.h>
#include "Pet.h"
#include "Properties.h"
#include "Exception.h"
#include "Frame.h"
#include "Convert.h"


namespace tamagotchi
{
  Pet::Pet()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Pet> " << this << std::endl;
    #endif
  }



  Pet::~Pet()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Pet> " << this << std::endl;
    #endif
  }



  Dog::Dog()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Dog> " << this << std::endl;
    #endif
    this->properties = new DogProperties;

    this->properties->set_health(MAX);
    this->properties->set_hunger(MIN);
    this->properties->set_fatigue(MIN);
    this->properties->set_happiness(MIN);
    this->properties->set_freq(LOW);
    this->properties->set_healthy(true);
  }



  Dog::~Dog()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Dog> " << this << std::endl;
    #endif
    delete this->properties;
  }



  void Dog::feed()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is feeding...");
    delete frame;

    this->properties->set_hunger(this->properties->get_hunger() - 1);
    this->properties->set_freq(HIGH_FEED);

    return;
  }



  void Dog::play()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is playing...");
    delete frame;

    this->properties->set_fatigue(this->properties->get_fatigue() + 1);
    this->properties->set_happiness(this->properties->get_happiness() + 1);
    this->properties->set_freq(HIGH_PLAY);

    return;
  }



  void Dog::sleep()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is sleeping...");
    delete frame;

    this->properties->set_fatigue(MIN);
    this->properties->set_hunger(this->properties->get_hunger() + 1);
    this->properties->set_health(this->properties->get_health() + 1);
    this->properties->set_freq(HIGH_SLEEP);

    return;
  }



  void Dog::punish()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is punished...");
    delete frame;

    this->properties->set_happiness(this->properties->get_happiness() - 1);
  }



  bool Dog::is_healthy()
  {
    return this->properties->get_healthy();
  }



  void Dog::show_properties()
  {
    std::string health =    myConvert::IntToString(this->properties->get_health());
    std::string hunger =    myConvert::IntToString(this->properties->get_hunger());
    std::string fatigue =   myConvert::IntToString(this->properties->get_fatigue());
    std::string happiness = myConvert::IntToString(this->properties->get_happiness());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health    " + health + "\n"
                              "Happiness " + happiness + "\n"
                              "Hunger    " + hunger + "\n"
                              "Fatigue   " + fatigue);

    delete frame;
    return;
  }



  void Dog::show_actions()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_menu("Select action:\n"
                        "1. Feed\n"
                        "2. Play\n"
                        "3. Sleep\n"
                        "4. Punish\n"
                        "0. Terminated");

    delete frame;
    return;
  }



  void Dog::choose_action()
  {
    switch(_getch())
    {
      case '1':
      {
        system("cls");
        this->feed();
        break;
      }

      case '2':
      {
        system("cls");
        this->play();
        break;
      }

      case '3':
      {
        system("cls");
        this->sleep();
        break;
      }

      case '4':
      {
        system("cls");
        this->punish();
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



  Cat::Cat()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Cat> " << this << std::endl;
    #endif
    this->properties = new CatProperties;

    this->properties->set_health(MAX);
    this->properties->set_hunger(MIN);
    this->properties->set_fatigue(MIN);
    this->properties->set_freq(LOW);
    this->properties->set_healthy(true);
  }



  Cat::~Cat()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Cat> " << this << std::endl;
    #endif
    delete properties;
  }



  void Cat::feed()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is feeding...");
    delete frame;

    this->properties->set_hunger(this->properties->get_hunger() - 1);
    this->properties->set_freq(HIGH_FEED);

    return;
  }



  void Cat::play()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is playing...");
    delete frame;

    this->properties->set_fatigue(this->properties->get_fatigue() + 1);
    this->properties->set_freq(HIGH_PLAY);

    return;
  }



  void Cat::sleep()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is sleeping...");
    delete frame;

    this->properties->set_fatigue(MIN);
    this->properties->set_freq(HIGH_SLEEP);
    this->properties->set_hunger(this->properties->get_hunger() + 1);
    this->properties->set_health(this->properties->get_health() + 1);

    return;
  }



  bool Cat::is_healthy()
  {
    return this->properties->get_healthy();
  }



  void Cat::show_properties()
  {
    std::string health =  myConvert::IntToString(this->properties->get_health());
    std::string hunger =  myConvert::IntToString(this->properties->get_hunger());
    std::string fatigue = myConvert::IntToString(this->properties->get_fatigue());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health  " + health + "\n"
                              "Hunger  " + hunger + "\n"
                              "Fatigue " + fatigue);

    delete frame;
    return;
  }



  void Cat::show_actions()
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



  void Cat::choose_action()
  {
    switch(_getch())
    {
      case '1':
      {
        system("cls");
        this->feed();
        break;
      }

      case '2':
      {
        system("cls");
        this->play();
        break;
      }

      case '3':
      {
        system("cls");
        this->sleep();
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