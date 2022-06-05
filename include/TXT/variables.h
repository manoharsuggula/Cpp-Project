#include <iostream>

class variables
{
private:
    int* _no_of_lines;
    int* _no_of_words;
    int* _characters_with_spaces;
    int* _spaces;
    int* _bytes;

public:
    int* no_of_lines();
    int* no_of_words();
    int* characters_with_spaces();
    int* spaces();
    int* bytes();

    variables();
    ~variables();
};
