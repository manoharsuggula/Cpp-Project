#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    int red,blue,green;

    public:

    Pixel(int,int,int);
    Pixel();
    ~Pixel();
    Pixel(const Pixel&);

    int get_red();
    int get_green();
    int get_blue();

    void set_red(int);
    void set_green(int);
    void set_blue(int);
};

#endif