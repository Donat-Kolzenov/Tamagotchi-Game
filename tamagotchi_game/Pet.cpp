#include <iostream>
#include "Pet.h"
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
    this->sick = false;
    this->health = MAX;
    this->hunger = MIN;
    this->fatigue = MIN;
    this->freq = LOW;
  }



  Pet::~Pet()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Pet> " << this << std::endl;
    #endif
  }



  int Pet::get_health()
  {
    return this->health;
  }



  int Pet::get_hunger()
  {
    return this->hunger;
  }



  int Pet::get_fatigue()
  {
    return this->fatigue;
  }



  int Pet::get_freq()
  {
    return this->freq;
  }



  void Pet::set_health(int health)
  {
    try
    {
      this->health = health;
    
      if(this->health > MAX || this->health < MIN)
        throw out_of_range();

      if(this->health == MIN)
        throw game_over();
    }
    catch(const game_over& ex)
    {
      this->show_properties();
      std::cout << ex.what() << std::endl;
      ex.solution(this);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void Pet::set_hunger(int hunger)
  {
    try
    {
      this->hunger = hunger;

      if(this->hunger > MAX || this->hunger < MIN)
        throw out_of_range();
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void Pet::set_fatigue(int fatigue)
  {
    try
    {
      this->fatigue = fatigue;

      if(this->fatigue > MAX || this->fatigue < MIN)
        throw out_of_range();
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void Pet::set_freq(int freq)
  {
    try
    {
      if(this->freq == freq)
        throw overflow_error();
      
      this->freq = freq;
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void Pet::set_sick(bool sick)
  {
    this->sick = sick;
    return;
  }



  bool Pet::is_sick()
  {
    return this->sick;
  }



  Dog::Dog()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Dog> " << this << std::endl;
    #endif

    this->happiness = MIN;
  }



  Dog::~Dog()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Dog> " << this << std::endl;
    #endif
  }



  int Dog::get_happiness()
  {
    return this->happiness;
  }



  void Dog::set_happiness(int happiness)
  {
    try
    {
      this->happiness = happiness;

      if(this->happiness > MAX || this->happiness < MIN)
        throw out_of_range();
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void Dog::feed()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is feeding...");
    delete frame;

    this->set_hunger(this->get_hunger() - 1);
    this->set_freq(HIGH_FEED);

    return;
  }



  void Dog::play()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is playing...");
    delete frame;

    this->set_fatigue(this->get_fatigue() + 1);
    this->set_happiness(this->get_happiness() + 1);
    this->set_freq(HIGH_PLAY);

    return;
  }



  void Dog::sleep()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Dog is sleeping...");
    delete frame;

    this->set_fatigue(MIN);
    this->set_hunger(this->get_hunger() + 1);
    this->set_health(this->get_health() + 1);
    this->set_freq(HIGH_SLEEP);

    return;
  }



  void Dog::show_properties()
  {
    std::string health =    myConvert::IntToString(this->get_health());
    std::string hunger =    myConvert::IntToString(this->get_hunger());
    std::string fatigue =   myConvert::IntToString(this->get_fatigue());
    std::string happiness = myConvert::IntToString(this->get_happiness());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health    " + health + "\n"
                              "Happiness " + happiness + "\n"
                              "Hunger    " + hunger + "\n"
                              "Fatigue   " + fatigue);

    delete frame;
    return;
  }



  Cat::Cat()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Cat> " << this << std::endl;
    #endif
  }



  Cat::~Cat()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Cat> " << this << std::endl;
    #endif
  }



  void Cat::feed()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is feeding...");
    delete frame;

    this->set_hunger(this->get_hunger() - 1);
    this->set_freq(HIGH_FEED);

    return;
  }



  void Cat::play()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is playing...");
    delete frame;

    this->set_fatigue(this->get_fatigue() + 1);
    this->set_freq(HIGH_PLAY);

    return;
  }



  void Cat::sleep()
  {
    SingleFrame *frame = new SingleFrame;
    frame->wrap_in_notice("Cat is sleeping...");
    delete frame;

    this->set_fatigue(MIN);
    this->set_freq(HIGH_SLEEP);
    this->set_hunger(this->get_hunger() + 1);
    this->set_health(this->get_health() + 1);

    return;
  }



  void Cat::show_properties()
  {
    std::string health =  myConvert::IntToString(this->get_health());
    std::string hunger =  myConvert::IntToString(this->get_hunger());
    std::string fatigue = myConvert::IntToString(this->get_fatigue());
    
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_properties("Health  " + health + "\n"
                              "Hunger  " + hunger + "\n"
                              "Fatigue " + fatigue);

    delete frame;
    return;
  }
}