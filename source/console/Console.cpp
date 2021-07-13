#include <iostream>
#include <Windows.h>
#include "Console.hpp"
#include "Player.hpp"
#include "Frame.hpp"
#include "Exception.hpp"


namespace tamagotchi
{
  Console::Console()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Constructor was called! <Console> " << this << std::endl;
    #endif

    this->player = new Player;
    SetConsoleTitle("Tamagotchi Game");
    this->set_size(HEIGHT, WIDTH);
  }



  Console::~Console()
  {
    #ifdef _SHOW_CREATE_OBJECTS
    std::cout << "Destructor was called! <Console> " << this << std::endl;
    #endif

    delete this->player;
  }



  void Console::run_game()
  {
    this->show_welcome();
    this->show_game_rules();

    this->player->show_pet_list();
    this->player->choose_pet();

    while(this->player->get_pet()->is_healthy())
    {
      this->player->get_pet()->show_properties();
      this->player->get_pet()->show_actions();
      this->player->get_pet()->choose_action();
    }
    this->player->get_pet()->show_properties();
    this->show_game_over();
    
    return;
  }



  void Console::show_welcome()
  {
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_notice("Welcome to Tamagotchi Game!");
    delete frame;

    return;
  }



  void Console::show_game_rules()
  {
    CustomFrame *frame = new CustomFrame;
    frame->wrap_in_menu("The game is played until your pet gets sick.\n"
                        "By selecting a pet, you can perform certain\n"
                        "actions above him that change his parameters.\n"
                        "Monitor the health of your pet and then your\n"
                        "pet will be in perfect order.");
    delete frame;
    return;
  }



  void Console::show_game_over()
  {
    DoubleFrame *frame = new DoubleFrame;
    frame->wrap_in_notice("GAME OVER");
    delete frame;

    return;  
  }



  void Console::set_size(const int height, const int width)
  {
    int padding_x = GetSystemMetrics(SM_CXSCREEN);
    int padding_y = GetSystemMetrics(SM_CYSCREEN);

    MoveWindow( GetConsoleWindow(),
                padding_x / 3, 
                padding_y / 3, 
                width,
                height,
                true );

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo( GetStdHandle(STD_OUTPUT_HANDLE),
                                &info );

    COORD coord;
    coord.X = info.srWindow.Right + 1;
    coord.Y = info.srWindow.Bottom + 1;
    SetConsoleScreenBufferSize( GetStdHandle(STD_OUTPUT_HANDLE),
                                coord );
    return;
  }
}