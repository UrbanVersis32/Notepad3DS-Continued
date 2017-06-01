#pragma once

#include "file.h"
#include <3ds.h>
#include <string>

#define CLEAR_SCREEN_LINES 40
#define MAX_LINES 28
#define MAX_WIDTH 49
#define LINE_STATUS_LINE "\x1b[7;0H"
#define SAVE_STATUS_LINE "\x1b[10;0H"
#define INSTRUCTION_LINE "\x1b[0;0H"
#define VERSION_LINE "\x1b[6;0H"

extern PrintConsole topScreen, bottomScreen; 
extern int scroll;

//Clears everything off the top screen
void clear_screen();

//Updates current selected screen with contents of file
void update_screen(File& file, unsigned int current_line);

void print_text(const char* str, unsigned int count, unsigned int selected_line);

void clear_save_status();
void print_save_status(std::string message);

void clear_line_status();
void print_line_status(unsigned int current_line);

void print_instructions();

void print_version(std::string version);

std::string char_vec_to_string(std::vector<char>& line);
