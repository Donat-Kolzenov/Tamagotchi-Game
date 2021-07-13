// Pet header
// Copyright (c) Donat Kolzenov.

#ifndef PET_H
#define PET_H
#include "PetProperties.hpp"


namespace tamagotchi
{
  class Pet
  {
    public:
      virtual bool is_healthy() = 0;
      virtual void show_properties() = 0;
      virtual void show_actions() = 0;
      virtual void choose_action() = 0;

    public:
      Pet();
      virtual ~Pet();
  };



  class Dog : public Pet
  {
    public:
      bool is_healthy() override;
      void show_properties() override;
      void show_actions() override;
      void choose_action() override;

    private:
      void feed();
      void play();
      void sleep();
      void train();

    private:
      DogProperties *properties;
      
    public:
      Dog();
      ~Dog() override;
  };



  class Cat : public Pet
  {
    public:
      bool is_healthy() override;
      void show_properties() override;
      void show_actions() override;
      void choose_action() override;

    private:
      void feed();
      void play();
      void sleep();

    private:
      CatProperties *properties;

    public:
      Cat();
      ~Cat() override;
  };



  enum Frequency
  {
    LOW,
    OVER_FEED,
    OVER_PLAY,
    OVER_SLEEP,
    OVER_TRAIN
  };
}

#endif  // PET_H