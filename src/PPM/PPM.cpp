#include "../../include/PPM/PPM.h"

PPM::PPM(){}

PPM::PPM(string f,int r,int c,int h,vector<Pixel> pix)
{
    format = f;
    rows = r;
    columns = c;
    highest = h;
    pix_map = pix;
}

PPM::~PPM(){}

PPM::PPM(const PPM& ppm)
{
    format = ppm.format;
    rows = ppm.rows;
    columns = ppm.columns;
    highest = ppm.highest;
    pix_map = ppm.pix_map;
}

int PPM::get_rows()
{
    return rows;    
}
int PPM::get_columns()
{
    return columns;
}
int PPM::get_highest()
{
    return highest;
}
vector<Pixel> PPM::get_pix()
{
    return pix_map;
}
string PPM::get_format()
{
    return format;
}

void PPM::set_rows(int value)
{
    rows = value;
}
void PPM::set_columns(int value)
{
    columns = value;
}
void PPM::set_highest(int value)
{
    highest = value;
}
void PPM::set_pix(vector<Pixel> p)
{
    pix_map = p;
}
void PPM::set_format(string f)
{
    format = f;
}