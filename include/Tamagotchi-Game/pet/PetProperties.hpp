// Pet properties header
// Copyright (c) Donat Kolzenov.

#ifndef PET_PROPERTIES_H
#define PET_PROPERTIES_H


namespace tamagotchi
{
  class PetProperties
  {
    public:
      int get_health();
      int get_hunger();
      int get_fatigue();
      int get_frequency();
      bool get_healthy();

      void set_health(int health);
      void set_hunger(int hunger);
      void set_fatigue(int fatigue);
      void set_frequency(int frequency);
      void set_healthy(bool healthy);

    private:
      int health;
      int hunger;
      int fatigue;
      int frequency;
      bool healthy;

    public:
      PetProperties();
      ~PetProperties();
  };



  class DogProperties : public PetProperties
  {
    public:
      int get_happiness();
      int get_obedient();

      void set_happiness(int happiness);
      void set_obedient(int obedient);

    private:
      int happiness;
      int obedient;

    public:
      DogProperties();
      ~DogProperties();
  };



  class CatProperties : public PetProperties
  {
    public:
      CatProperties();
      ~CatProperties();
  };



  enum Value
  {
    MIN = 0,
    MAX = 10
  };
}

#endif  // PET_PROPERTIES_H