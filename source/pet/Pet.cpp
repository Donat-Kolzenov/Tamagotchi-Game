#include <iostream>
#include "conio.h"      // for _getch()
#include "Pet.hpp"
#include "PetProperties.hpp"
#include "Exception.hpp"
#include "Frame.hpp"
#include "Convert.hpp"


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

    this->properties->set_frequency(OVER_FEED);
    this->properties->set_hunger(this->properties->get_hunger() - 1);

    return;
  }



  void Dog::play()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is playing...");
    delete frame;

    this->properties->set_frequency(OVER_PLAY);
    this->properties->set_fatigue(this->properties->get_fatigue() + 1);
    this->properties->set_happiness(this->properties->get_happiness() + 1);

    return;
  }



  void Dog::sleep()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is sleeping...");
    delete frame;

    this->properties->set_fatigue(MIN);
    this->properties->set_frequency(OVER_SLEEP);
    this->properties->set_hunger(this->properties->get_hunger() + 1);
    this->properties->set_health(this->properties->get_health() + 1);

    return;
  }



  void Dog::train()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is being trained...");
    delete frame;

    this->properties->set_frequency(OVER_TRAIN);
    this->properties->set_obedient(this->properties->get_obedient() + 1);
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
    std::string obedient  = myConvert::IntToString(this->properties->get_obedient());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health    " + health + "\n"
                              "Hunger    " + hunger + "\n"
                              "Fatigue   " + fatigue + "\n"
                              "Happiness " + happiness + "\n"
                              "Obedient  " + obedient);

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
                        "4. Train");

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
        this->train();
        break;
      }

      default:
      {
        system("cls");
        CustomFrame frame;
        frame.wrap_in_notice("Entered wrong key!");
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
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Cat is feeding...");
    delete frame;

    this->properties->set_frequency(OVER_FEED);
    this->properties->set_hunger(this->properties->get_hunger() - 1);

    return;
  }



  void Cat::play()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Cat is playing...");
    delete frame;

    this->properties->set_frequency(OVER_PLAY);
    this->properties->set_fatigue(this->properties->get_fatigue() + 1);

    return;
  }



  void Cat::sleep()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Cat is sleeping...");
    delete frame;

    this->properties->set_fatigue(MIN);
    this->properties->set_frequency(OVER_SLEEP);
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
                        "3. Sleep");

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

      default:
      {
        system("cls");
        CustomFrame frame;
        frame.wrap_in_notice("Entered wrong key!");
        break;
      }
    }
    return;
  }
}