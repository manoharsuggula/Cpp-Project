#include "../../include/TXT/variables.h"
#include <iostream>

variables::variables()
{
    _no_of_lines = new int(0);
    _no_of_words = new int(0);
    _characters_with_spaces = new int(0);
    _spaces = new int(0);
    _bytes = new int(0);
}

variables::~variables()
{
    delete _no_of_lines;
    delete _no_of_words;
    delete _characters_with_spaces;
    delete _spaces;
    delete _bytes;
}

int* variables::no_of_lines() {
    return _no_of_lines;
}

int* variables::no_of_words() {
    return _no_of_words;
}

int* variables::characters_with_spaces() {
    return _characters_with_spaces;
}

int* variables::spaces() {
    return _spaces;
}

int* variables::bytes() {
    return _bytes;
}