#ifndef PPM_H
#define PPM_H

#include<vector>
#include<string>
#include "Pixel.h"

using namespace std;

class PPM
{
    vector<Pixel> pix_map;
    int rows;
    int columns;
    int highest;
    string format;

    public:
    PPM();
    PPM(string,int,int,int,vector<Pixel>);
    ~PPM();
    PPM(const PPM&);

    int get_rows();
    int get_columns();
    int get_highest();
    vector<Pixel> get_pix();
    string get_format();

    void set_rows(int);
    void set_columns(int);
    void set_highest(int);
    void set_pix(vector<Pixel>);
    void set_format(string);
    
};

#endif