#include <iostream>
#include <Windows.h>  // for COORD
#include <cctype>     // for std::isdigit
#include "Frame.h"
#include "Exception.h"

#define _COLOR_RED 4
#define _COLOR_WHITE 7
#define _COLOR_GREEN 10


namespace tamagotchi
{
  Frame::Frame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Frame> " << this << std::endl;
    #endif

    COORD console_size = this->get_console_size();
    this->horizontal_size = console_size.X - 2;
  }



  Frame::~Frame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Frame> " << this << std::endl;
    #endif
  }



  COORD Frame::get_console_size()
  {
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);

    COORD consoleSize;
    consoleSize.X = consoleInfo.srWindow.Right;
    consoleSize.Y = consoleInfo.srWindow.Bottom;

    return consoleSize;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_menu(std::string str)
  {
    std::string null_str;
    for(int i = 0; i < this->horizontal_size; i++)
      null_str += " ";

    std::cout << this->line_up << std::endl;
    std::cout << null_str << " " << this->border << "\r" << this->border << " ";
    
    for(int i = 0; i < str.size(); i++)
    {
      std::cout << str[i];

      if(str[i] == '\n')
        std::cout << null_str << " " << this->border << "\r" << this->border << " ";
    }
    std::cout << std::endl << this->line_down << std::endl;
    return;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_notice(std::string str)
  {
    int size = 0;
    std::string str_tmp;

    std::cout << this->line_up << std::endl;
    for(int i = 0; i < str.size(); i++)
    {
      if(str[i] != '\n')
        str_tmp += str[i];

      if(str[i] == '\n' || i == str.size() - 1)
      {
        if(str[i] == '\n')
          size = i - size;

        if(i == str.size() - 1)
          size = i - size + 1;

        int left_size = (this->horizontal_size - size) / 2;
        int right_size = this->horizontal_size - size - left_size;

        std::string left_line;
        for(int j = 0; j < left_size - 1; j++)
          left_line += this->line;

        std::string right_line;
        for(int j = 0; j < right_size - 1; j++)
          right_line += this->line;

        std::cout << this->border_left << left_line << " " <<
          str_tmp << " " << right_line << this->border_right << std::endl;

        size = i + 1;
        str_tmp.clear();
      }
    }
    std::cout << this->line_down << std::endl;
    return;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_properties(std::string str)
  {
    std::string digit;
    std::string str_tmp;
    std::string scale;
    int left_size = 4;
    std::string left_line;
    for(int j = 0; j < left_size - 1; j++)
      left_line += this->line;
      
    std::cout << this->line_up << std::endl;
    for(int i = 0; i < str.size(); i++)
    {
      if(str[i] != '\n' && std::isdigit(str[i]) == false)
        str_tmp += str[i];

      if(std::isdigit(str[i]))
        digit += str[i];

      if(str[i] == '\n' || i == str.size() - 1)
      {
        for(int i = 0; i < atoi(digit.c_str()); i++)
          scale += "+";

        for(int i = 0; i < MAX - atoi(digit.c_str()); i++)
          scale += "_";
          
        int right_size = this->horizontal_size - left_line.size() - str_tmp.size() - scale.size();
        std::string right_line;
        for(int i = 0; i < right_size - 2; i++)
          right_line += this->line;

        std::cout << this->border_left << left_line << " " << str_tmp;

        if(atoi(digit.c_str()) == MAX && ( str_tmp.find("Health")    != std::string::npos ||
                                           str_tmp.find("Happiness") != std::string::npos ))
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_GREEN);

        if(atoi(digit.c_str()) == MAX && ( str_tmp.find("Hunger")  != std::string::npos ||
                                           str_tmp.find("Fatigue") != std::string::npos ))
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_RED);

        if(atoi(digit.c_str()) == MIN && ( str_tmp.find("Health")    != std::string::npos ||
                                           str_tmp.find("Happiness") != std::string::npos ))
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_RED);

        if(atoi(digit.c_str()) == MIN && ( str_tmp.find("Hunger")  != std::string::npos ||
                                           str_tmp.find("Fatigue") != std::string::npos ))
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_GREEN);

        std::cout << scale;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_WHITE);

        std::cout << " " << right_line << this->border_right << std::endl;

        str_tmp.clear();
        digit.clear();
        scale.clear();
      }
    }
    std::cout << this->line_down << std::endl;
    return;
  }



  SingleFrame::SingleFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <SingleFrame> " << this << std::endl;
    #endif

    this->line = "\xC4";
    std::string long_line;
    for(int i = 0; i < this->horizontal_size; i++)
      long_line += this->line;

    this->line_up = "\xDA" + long_line + "\xBF";      // -->  ┌───────────┐
    this->line_down = "\xC0" + long_line + "\xD9";    // -->  │           │
    this->border = "\xB3";                            // -->  └───────────┘
    this->border_left = "\xC3";
    this->border_right = "\xB4";
  }



  SingleFrame::~SingleFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <SingleFrame> " << this << std::endl;
    #endif
  }



  DoubleFrame::DoubleFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <DoubleFrame> " << this << std::endl;
    #endif

    this->line = "\xCD";
    std::string long_line;
    for(int i = 0; i < this->horizontal_size; i++)
      long_line += this->line;

    this->line_up = "\xC9" + long_line + "\xBB";      // -->  ╔═══════════╗
    this->line_down = "\xC8" + long_line + "\xBC";    // -->  ║           ║
    this->border = "\xBA";                            // -->  ╚═══════════╝
    this->border_left = "\xCC";
    this->border_right = "\xB9";
  }



  DoubleFrame::~DoubleFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <DoubleFrame> " << this << std::endl;
    #endif
  }



  CustomFrame::CustomFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <CustomFrame> " << this << std::endl;
    #endif

    this->line = "\xC4";
    std::string long_line;
    for(int i = 0; i < this->horizontal_size; i++)
      long_line += this->line;

    this->line_up = "\xD6" + long_line + "\xB7";      // -->  ╓───────────╖
    this->line_down = "\xD3" + long_line + "\xBD";    // -->  ╟───     ───╢
    this->border = "\xBA";                            // -->  ╙───────────╜
    this->border_left = "\xC7";
    this->border_right = "\xB6";
  }



  CustomFrame::~CustomFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <CustomFrame> " << this << std::endl;
    #endif
  }



  VoluminousFrame::VoluminousFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <VoluminousFrame> " << this << std::endl;
    #endif

    std::string long_line;
    for(int i = 0; i < this->horizontal_size; i++)
      long_line += "\xC4";

    this->line = "\xC4";  //"\xCD"
    this->line_up = "\xD6" + long_line + "\xB7";      // -->  ╓───────────┐
    this->line_down = "\xC8" + long_line + "\xBE";    // -->  ╟───     ───┤
    this->border = "\xBA";                            // -->  ╚═══════════╛
    this->border_left = "\xC7";                       // -->  ╓───────────┐
    this->border_right = "\xB6";                      // -->  ╠═══     ═══╡
  }                                                   // -->  ╚═══════════╛



  VoluminousFrame::~VoluminousFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <VoluminousFrame> " << this << std::endl;
    #endif
  }
}