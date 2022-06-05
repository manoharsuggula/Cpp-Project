#include "../../include/PPM/Pixel.h"

Pixel::Pixel(int r,int g,int b)
{
    red = r;
    green = g;
    blue = b;
}

Pixel::Pixel(){}

Pixel::~Pixel(){}

Pixel::Pixel(const Pixel& pix)
{
    red = pix.red;
    green = pix.green;
    blue = pix.blue;
}

int Pixel::get_red()
{
    return red;
}
int Pixel::get_green()
{
    return green;
}
int Pixel::get_blue()
{
    return blue;
}

void Pixel::set_red(int value)
{
    red = value;
}
void Pixel::set_green(int value)
{
    green = value;
}
void Pixel::set_blue(int value)
{
    blue = value;
}