// ASCII Frame header
// Copyright (c) Donat Kolzenov.

#ifndef FRAME_H
#define FRAME_H
#include <iostream>
#include <Windows.h>


namespace tamagotchi
{
  class Frame
  {
    protected:
      Frame();
      ~Frame();

    protected:
      int horizontal_size;
      std::string line;
      std::string line_up;
      std::string line_down;
      std::string border;
      std::string border_right;
      std::string border_left;

    private:
      COORD get_console_size();

    public:
      void wrap_in_menu(std::string str);
      void wrap_in_notice(std::string str);
      void wrap_in_properties(std::string str);
  };



  class SingleFrame : public Frame
  {
    public:
      SingleFrame();
      ~SingleFrame();
  };



  class DoubleFrame : public Frame
  {
    public:
      DoubleFrame();
      ~DoubleFrame();
  };



  class CustomFrame : public Frame
  {
    public:
      CustomFrame();
      ~CustomFrame();
  };



  class VoluminousFrame : public Frame
  {
    public:
      VoluminousFrame();
      ~VoluminousFrame();
  };
}

#endif