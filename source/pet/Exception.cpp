#include <iostream>
#include "Pet.hpp"
#include "PetProperties.hpp"
#include "Exception.hpp"
#include "Frame.hpp"


namespace tamagotchi
{
  exception::exception()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Default constructor was called! <exception> " << this << std::endl;
    #endif
  }



  exception::exception(PetProperties *properties)
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Constructor was called! <exception> " << this << std::endl;
    #endif
    
    properties->set_healthy(false);
  }



  exception::~exception()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Destructor was called! <exception> " << this << std::endl;
    #endif
  }



  const char* exception::what() const
  {
    return "Unknown error!\n"
      "Contact the developer of this game";
  }



  out_of_range::out_of_range()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Default constructor was called! <out_of_range> " << this << std::endl;
    #endif
  }



  out_of_range::out_of_range(int &value)
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Constructor was called! <out_of_range> " << this << std::endl;
    #endif

    if(value > MAX)
      value = MAX;

    if(value < MIN)
      value = MIN;
  }



  out_of_range::~out_of_range()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Destructor was called! <out_of_range> " << this << std::endl;
    #endif
  }



  const char* out_of_range::what() const
  {
    return "Error! Changed value was out of range";
  }



  overflow_error::overflow_error()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Default constructor was called! <overflow_error> " << this << std::endl;
    #endif
  }



  overflow_error::overflow_error(PetProperties *properties)
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Constructor was called! <overflow_error> " << this << std::endl;
    #endif

    int frequency = properties->get_frequency();
    properties->set_health(properties->get_health() - 1);
    
    if(frequency == OVER_SLEEP)
      properties->set_hunger(properties->get_hunger() - 1);

    if(frequency == OVER_TRAIN)
      properties->set_fatigue(properties->get_fatigue() + 1);
  }



  overflow_error::~overflow_error()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Destructor was called! <overflow_error> " << this << std::endl;
    #endif
  }



  const char* overflow_error::what() const 
  {
    return "Error! Clicked too much";
  }



  game_over::game_over()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Defalut constructor was called! <game_over> " << this << std::endl;
    #endif
  }



  game_over::game_over(PetProperties *properties)
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Constructor was called! <game_over> " << this << std::endl;
    #endif

    exception ex(properties);
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_notice("Oh no, your pet is sick...");
    delete frame;
  }



  game_over::~game_over()
  {
    #ifdef _SHOW_CREATE_EXCEPTIONS
    std::cout << "Destructor was called! <game_over> " << this << std::endl;
    #endif
  }



  const char* game_over::what() const
  {
    return "Error! Game over";
  }
}