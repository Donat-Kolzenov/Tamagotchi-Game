#include <iostream>
#include "Properties.h"
#include "Exception.h"


namespace tamagotchi
{
  int PetProperties::get_health()
  {
    return this->health;
  }



  int PetProperties::get_hunger()
  {
    return this->hunger;
  }



  int PetProperties::get_fatigue()
  {
    return this->fatigue;
  }



  int PetProperties::get_freq()
  {
    return this->freq;
  }



  bool PetProperties::get_healthy()
  {
    return this->healthy;
  }



  void PetProperties::set_health(int health)
  {
    try
    {
      this->health = health;
    
      if(this->health > MAX || this->health < MIN)
        throw out_of_range();

      if(this->health == MIN)
        throw game_over();
    }
    catch(const out_of_range& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
      ex.solution(this->health);
    }
    catch(const game_over& ex)
    {
      std::cerr << ex.what() << std::endl;
      ex.solution(this);
    }
    return;
  }



  void PetProperties::set_hunger(int hunger)
  {
    try
    {
      this->hunger = hunger;

      if(this->hunger > MAX || this->hunger < MIN)
        throw out_of_range();
    }
    catch(const out_of_range& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
      ex.solution(this->hunger);
    }
    return;
  }



  void PetProperties::set_fatigue(int fatigue)
  {
    try
    {
      this->fatigue = fatigue;

      if(this->fatigue > MAX || this->fatigue < MIN)
        throw out_of_range();
    }
    catch(const out_of_range& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
      ex.solution(this->fatigue);
    }
    return;
  }



  void PetProperties::set_freq(int freq)
  {
    try
    {
      if(this->freq == freq)
        throw overflow_error();
      
      this->freq = freq;
    }
    catch(const overflow_error& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cout << ex.what() << std::endl;
      #endif
      ex.solution(this);
    }
    return;
  }



  void PetProperties::set_healthy(bool healthy)
  {
    this->healthy = healthy;
    return;
  }



  int DogProperties::get_happiness()
  {
    return this->happiness;
  }



  void DogProperties::set_happiness(int happiness)
  {
    try
    {
      this->happiness = happiness;

      if(this->happiness > MAX || this->happiness < MIN)
        throw out_of_range();
    }
    catch(const out_of_range& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
      ex.solution(this->happiness);
    }
    return;
  }
}