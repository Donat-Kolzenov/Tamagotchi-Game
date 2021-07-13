#include <iostream>
#include <Windows.h>
#include <cctype>                // for std::isdigit
#include "PetProperties.hpp"
#include "Frame.hpp"
#include "Exception.hpp"

#define _COLOR_RED 4
#define _COLOR_WHITE 7
#define _COLOR_GREEN 10
#define _PADDING_RIGHT 2         // default padding for correct display the frame in console
#define _LEFT_BORDERLINE_SIZE 4  // default left borderline size for properties frame


namespace tamagotchi
{
  Frame::Frame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Frame> " << this << std::endl;
    #endif

    COORD console_size = this->get_console_size();
    this->horizontal_size = console_size.X - _PADDING_RIGHT;
  }



  Frame::~Frame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Frame> " << this << std::endl;
    #endif
  }



  COORD Frame::get_console_size()
  {
    CONSOLE_SCREEN_BUFFER_INFO console_info;
    GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE), 
                                &console_info );

    COORD console_size;
    console_size.X = console_info.srWindow.Right;
    console_size.Y = console_info.srWindow.Bottom;

    return console_size;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_menu(std::string menu_str)
  {
    std::string null_str;
    for(int i = 0; i < this->horizontal_size; i++)
        null_str += " ";

    std::cout << this->line_up << std::endl;
    std::cout << null_str << " " << this->border << "\r" << this->border << " ";
    
    for(int i = 0; i < menu_str.size(); i++)
    {
      std::cout << menu_str[i];

      if(menu_str[i] == '\n')
          std::cout << null_str << " " << this->border << "\r" << this->border << " ";
    }
    std::cout << std::endl << this->line_down << std::endl;
    return;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_notice(std::string notice_str)
  {
    int size = 0;
    std::string notice_part;

    std::cout << this->line_up << std::endl;
    for(int i = 0; i < notice_str.size(); i++)
    {
      if(notice_str[i] != '\n')
          notice_part += notice_str[i];

      if(notice_str[i] == '\n' || i == notice_str.size() - 1)
      {
        if(notice_str[i] == '\n')
            size = i - size;

        if(i == notice_str.size() - 1)
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
          notice_part << " " << right_line << this->border_right << std::endl;

        size = i + 1;
        notice_part.clear();
      }
    }
    std::cout << this->line_down << std::endl;
    return;
  }



  // You can enter unlimited amount of line (use "\\n")
  void Frame::wrap_in_properties(std::string properties_str)
  {
    std::string digit;
    std::string property;
    std::string scale;
    std::string left_line;
    
    int left_size = _LEFT_BORDERLINE_SIZE;
    for(int j = 0; j < left_size - 1; j++)
        left_line += this->line;
      
    std::cout << this->line_up << std::endl;
    for(int i = 0; i < properties_str.size(); i++)
    {
      if(properties_str[i] != '\n' && std::isdigit(properties_str[i]) == false)
          property += properties_str[i];

      if(std::isdigit(properties_str[i]))
          digit += properties_str[i];

      if(properties_str[i] == '\n' || i == properties_str.size() - 1)
      {
        for(int i = 0; i < atoi(digit.c_str()); i++)
            scale += "+";

        for(int i = 0; i < MAX - atoi(digit.c_str()); i++)
            scale += "_";
          
        int right_size = this->horizontal_size - left_line.size() - property.size() - scale.size();
        std::string right_line;
        for(int i = 0; i < right_size - 2; i++)
            right_line += this->line;

        std::cout << this->border_left << left_line << " " << property;
        
        this->find_property_scale_color(property, digit);
        std::cout << scale;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_WHITE);

        std::cout << " " << right_line << this->border_right << std::endl;

        property.clear();
        digit.clear();
        scale.clear();
      }
    }
    std::cout << this->line_down << std::endl;
    return;
  }



  void Frame::find_property_scale_color(std::string property, std::string digit)
  {
    if( property.find("Health")    != std::string::npos ||
        property.find("Happiness") != std::string::npos ||
        property.find("Obedient")  != std::string::npos  )
    {
      if(atoi(digit.c_str()) == MAX)
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_GREEN);

      else if(atoi(digit.c_str()) == MIN)
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_RED);
    }

    else if( property.find("Hunger")  != std::string::npos ||
             property.find("Fatigue") != std::string::npos  )
    {
      if(atoi(digit.c_str()) == MAX)
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_RED);

      else if(atoi(digit.c_str()) == MIN)
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _COLOR_GREEN);
    }
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

    std::string long_line;
    for(int i = 0; i < this->horizontal_size; i++)
        long_line += "\xC4";

    this->line = "\xCD";
    this->line_up = "\xD6" + long_line + "\xB7";      // -->  ╓───────────╖
    this->line_down = "\xD3" + long_line + "\xBD";    // -->  ╠═══     ═══╣
    this->border = "\xBA";                            // -->  ╙───────────╜
    this->border_left = "\xCC";
    this->border_right = "\xB9";
  }



  CustomFrame::~CustomFrame()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <CustomFrame> " << this << std::endl;
    #endif
  }
}