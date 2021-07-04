// Exception Tamagotchi Game header
// Copyright (c) Donat Kolzenov.

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "Pet.h"

//#define _SHOW_CREATE_OBJECTS
//#define _SHOW_ERROR_LOGS


namespace tamagotchi
{
  class exception
  {
    public:
      exception();
      ~exception();
    
    protected:
      const char* developer_name;

    public:
      virtual const char* what() const;
      virtual void solution(Pet *pet) const;
  };



  class out_of_range : public exception
  {
    public:
      out_of_range();
      ~out_of_range();

    public:
      const char* what() const override;
      void solution(Pet *pet) const override;
      void solution(Dog *dog) const;
  };



  class overflow_error : public exception
  {
    public:
      overflow_error();
      ~overflow_error();
    
    public:
      const char* what() const override;
      void solution(Pet *pet) const override;
  };



  class player_error : public exception
  {
    public:
      player_error();
      ~player_error();

    public:
      const char* what() const override;
  };



  class game_over : public exception
  {
    public:
      game_over();
      ~game_over();

    public:
      const char* what() const override;
      void solution(Pet *pet) const override;
  };
}

#endif  // EXCEPTION_H