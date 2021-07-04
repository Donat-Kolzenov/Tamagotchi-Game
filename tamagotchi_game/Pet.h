// Pet header
// Copyright (c) Donat Kolzenov.

#ifndef PET_H
#define PET_H


namespace tamagotchi
{
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



  class Pet
  {
    public:
      Pet();
      ~Pet();

    private:
      bool sick;
      int health;
      int hunger;
      int fatigue;
      int freq;

    public:
      int get_health();
      int get_hunger();
      int get_fatigue();
      int get_freq();
      bool is_sick();

      void set_health(int health);
      void set_hunger(int hunger);
      void set_fatigue(int fatigue);
      void set_freq(int freq);
      void set_sick(bool sick);

    public:
      virtual void feed() = 0;
      virtual void play() = 0;
      virtual void sleep() = 0;
      virtual void show_properties() = 0;
  };



  class Dog : public Pet
  {
    public:
      Dog();
      ~Dog();

    private:
      int happiness;

    public:
      int get_happiness();
      void set_happiness(int happiness);

    public:
      void feed() override;
      void play() override;
      void sleep() override;
      void show_properties() override;
  };



  class Cat : public Pet
  {
    public:
      Cat();
      ~Cat();

    public:
      void feed() override;
      void play() override;
      void sleep() override;
      void show_properties() override;
  };
}

#endif  //PET_H