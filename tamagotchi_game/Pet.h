// Pet header
// Copyright (c) Donat Kolzenov.

#ifndef PET_H
#define PET_H
#include "Properties.h"


namespace tamagotchi
{
  class Pet
  {
    public:
      Pet();
      virtual ~Pet();

    public:
      virtual bool is_healthy() = 0;
      virtual void show_properties() = 0;
      virtual void show_actions() = 0;
      virtual void choose_action() = 0;
  };



  class Dog : public Pet
  {
    public:
      Dog();
      ~Dog() override;

    private:
      DogProperties *properties;

    private:
      void feed();
      void play();
      void sleep();
      void punish();

    public:
      bool is_healthy() override;
      void show_properties() override;
      void show_actions() override;
      void choose_action() override;
  };



  class Cat : public Pet
  {
    public:
      Cat();
      ~Cat() override;

    private:
      CatProperties *properties;

    private:
      void feed();
      void play();
      void sleep();

    public:
      bool is_healthy() override;
      void show_properties() override;
      void show_actions() override;
      void choose_action() override;
  };
}

#endif  //PET_H