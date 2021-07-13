// Exception Tamagotchi Game header
// Copyright (c) Donat Kolzenov.

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include "PetProperties.hpp"

/*
 *  if your undef #define(s) below then
 *  debugging information will be displayed
 * (recommend changing size of the console
 *  for correct display)
 */

//#define _SHOW_CREATE_OBJECTS
//#define _SHOW_CREATE_EXCEPTIONS
//#define _SHOW_ERROR_LOGS


namespace tamagotchi
{
  class exception
  {
    public:
      virtual const char* what() const;

    public:
      exception();
      exception(PetProperties *properties);
      ~exception();
  };



  class out_of_range : public exception
  {
    public:
      const char* what() const override;

    public:
      out_of_range();
      out_of_range(int &value);
      ~out_of_range();
  };



  class overflow_error : public exception
  {
    public:
      const char* what() const override;

    public:
      overflow_error();
      overflow_error(PetProperties *properties);
      ~overflow_error();
  };



  class game_over : public exception
  {
    public:
      const char* what() const override;

    public:
      game_over();
      game_over(PetProperties *properties);
      ~game_over();
  };
}

#endif  // EXCEPTION_H