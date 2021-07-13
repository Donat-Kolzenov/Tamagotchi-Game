#include <iostream>
#include "Pet.hpp"
#include "PetProperties.hpp"
#include "Exception.hpp"


namespace tamagotchi
{
  PetProperties::PetProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <PetProperties> " << this << std::endl;
    #endif

    this->health = MAX;
    this->hunger = MIN;
    this->fatigue = MIN;
    this->frequency = LOW;
    this->healthy = true;
  }



  PetProperties::~PetProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <PetProperties> " << this << std::endl;
    #endif
  }



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



  int PetProperties::get_frequency()
  {
    return this->frequency;
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
        throw out_of_range(this->health);

      if(this->health == MIN)
        throw game_over(this);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
    return;
  }



  void PetProperties::set_hunger(int hunger)
  {
    try
    {
      this->hunger = hunger;

      if(this->hunger > MAX || this->hunger < MIN)
        throw out_of_range(this->hunger);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
    return;
  }



  void PetProperties::set_fatigue(int fatigue)
  {
    try
    {
      this->fatigue = fatigue;

      if(this->fatigue > MAX || this->fatigue < MIN)
        throw out_of_range(this->fatigue);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
    return;
  }



  void PetProperties::set_frequency(int frequency)
  {
    try
    {
      if(this->frequency == frequency)
        throw overflow_error(this);
      
      this->frequency = frequency;
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
    return;
  }



  void PetProperties::set_healthy(bool healthy)
  {
    this->healthy = healthy;
    return;
  }



  DogProperties::DogProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <DogProperties> " << this << std::endl;
    #endif
    
    this->happiness = MAX;
    this->obedient = MIN;
  }



  DogProperties::~DogProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <DogProperties> " << this << std::endl;
    #endif
  }



  int DogProperties::get_happiness()
  {
    return this->happiness;
  }



  int DogProperties::get_obedient()
  {
    return this->obedient;
  }



  void DogProperties::set_happiness(int happiness)
  {
    try
    {
      this->happiness = happiness;

      if(this->happiness > MAX || this->happiness < MIN)
        throw out_of_range(this->happiness);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
    return;
  }



  void DogProperties::set_obedient(int obedient)
  {
    try
    {
      this->obedient = obedient;

      if(this->obedient > MAX || this->obedient < MIN)
        throw out_of_range(this->obedient);
    }
    catch(const exception& ex)
    {
      #ifdef _SHOW_ERROR_LOGS
      std::cerr << ex.what() << std::endl;
      #endif
    }
  }



  CatProperties::CatProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <CatProperties> " << this << std::endl;
    #endif
  }



  CatProperties::~CatProperties()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <CatProperties> " << this << std::endl;
    #endif
  }
}