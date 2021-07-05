// Pet properties header
// Copyright (c) Donat Kolzenov.

#ifndef PROPERTIES_H
#define PROPERTIES_H


namespace tamagotchi
{
  class PetProperties
  {
    private:
      int health;
      int hunger;
      int fatigue;
      int freq;
      bool healthy;

    public:
      int get_health();
      int get_hunger();
      int get_fatigue();
      int get_freq();
      bool get_healthy();

      void set_health(int health);
      void set_hunger(int hunger);
      void set_fatigue(int fatigue);
      void set_freq(int freq);
      void set_healthy(bool healthy);
  };



  class DogProperties : public PetProperties
  {
    private:
      int happiness;

    public:
      int get_happiness();
      void set_happiness(int happiness);
  };



  class CatProperties : public PetProperties
  {
    
  };



  enum Value
  {
    MIN = 0,
    MAX = 10,
  };



  enum Freq
  {
    LOW,
    HIGH_FEED,
    HIGH_PLAY,
    HIGH_SLEEP
  };
}

#endif