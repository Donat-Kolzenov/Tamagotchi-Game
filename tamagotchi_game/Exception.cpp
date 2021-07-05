#include <iostream>
#include "Pet.h"
#include "Properties.h"
#include "Exception.h"


namespace tamagotchi
{
  exception::exception()
  {
    this->developer_name = "'Donat Kolzenov'";
  }



  exception::~exception()
  {

  }



  const char* exception::what() const
  {
    return "Unknown error. "
      "Contact the developer of this game ";
        this->developer_name;
          " for further details...";
  }



  void exception::solution(PetProperties *properties) const
  {
    properties->set_healthy(false);
    std::cout << "Program was terminate..." << std::endl;
    return;
  }



  out_of_range::out_of_range()
  {

  }



  out_of_range::~out_of_range()
  {

  }



  const char* out_of_range::what() const
  {
    return "Error! Changed value was out of range";
  }



  void out_of_range::solution(int &value) const
  {
    if(value > MAX)
      value = MAX;

    if(value < MIN)
      value = MIN;

    return;
  }



  overflow_error::overflow_error()
  {

  }



  overflow_error::~overflow_error()
  {

  }



  const char* overflow_error::what() const 
  {
    return "Error! Clicked too much, get your taxes";
  }



  void overflow_error::solution(PetProperties *properties) const
  {
    int freq = properties->get_freq();

    if(freq == HIGH_FEED || freq == HIGH_PLAY)
      properties->set_health(properties->get_health() - 1);

    if(freq == HIGH_SLEEP)
    {
      properties->set_hunger(properties->get_hunger() - 1);
      properties->set_health(properties->get_health() - 1);
    }
    return;
  }



  player_error::player_error()
  {

  }



  player_error::~player_error()
  {

  }



  const char* player_error::what() const
  {
    return "Error! You haven't created a player yet!"
      " Hint: use the command: "
        "\"Name of Interface\"->create_player()";
  }



  game_over::game_over()
  {

  }



  game_over::~game_over()
  {

  }



  const char* game_over::what() const
  {
    return "Oh no, your pet is sick :(";
  }



  void game_over::solution(PetProperties *properties) const
  {
    properties->set_healthy(false);
    return;
  }
}