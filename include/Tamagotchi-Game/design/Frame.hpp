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
    public:
      void wrap_in_menu(std::string menu_str);
      void wrap_in_notice(std::string notice_str);
      void wrap_in_properties(std::string properties_str);

    private:
      COORD get_console_size();
      void find_property_scale_color(std::string property, std::string digit);

    protected:
      int horizontal_size;
      std::string line;
      std::string line_up;
      std::string line_down;
      std::string border;
      std::string border_right;
      std::string border_left;

    public:
      Frame();
      ~Frame();
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
}

#endif  // FRAME_H