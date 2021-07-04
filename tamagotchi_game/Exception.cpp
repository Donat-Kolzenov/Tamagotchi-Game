#include <iostream>
#include "Pet.h"
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



  void exception::solution(Pet *pet) const
  {
    pet->set_sick(true);
    std::cout << "Program was terminate..." << std::endl;
    system("pause");

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



  void out_of_range::solution(Pet *pet) const
  {
    if(pet->get_health() > MAX) { pet->set_health(MAX); }
    if(pet->get_health() < MIN) { pet->set_health(MIN); }

    if(pet->get_hunger() > MAX) { pet->set_hunger(MAX); }
    if(pet->get_hunger() < MIN) { pet->set_hunger(MIN); }

    if(pet->get_fatigue() > MAX) { pet->set_fatigue(MAX); }
    if(pet->get_fatigue() < MIN) { pet->set_fatigue(MIN); }

    return;
  }



  void out_of_range::solution(Dog *dog) const
  {
    this->solution((Pet*)dog);
    if(dog->get_happiness() > MAX) { dog->set_happiness(MAX); }
    if(dog->get_happiness() < MIN) { dog->set_happiness(MIN); }

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



  void overflow_error::solution(Pet *pet) const
  {
    int freq = pet->get_freq();

    if(freq == HIGH_FEED || freq == HIGH_PLAY)
      pet->set_health(pet->get_health() - 1);

    if(freq == HIGH_SLEEP)
    {
      pet->set_hunger(pet->get_hunger() - 1);
      pet->set_health(pet->get_health() - 1);
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



  void game_over::solution(Pet *pet) const
  {
    pet->set_sick(true);
  }
}