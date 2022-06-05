#include "../../include/PPM/PPMFileReader.h"

using namespace std;


PPMFileReader::PPMFileReader() {}
PPMFileReader::PPMFileReader(std::fstream* o) : FileReader(o)
{}
void* PPMFileReader::read()
{
    string line,temp;
    string format;
    int rows, columns, highest;
    std::fstream* _reader = readFile();
    vector<int> values;
    vector<Pixel> pixels;

    format = "";
    while(1)
    {
        getline(*(_reader), format);
        if(format[0] != '#')
            break;
        format = "";
    }

    if((*_reader).peek() == '#')
    {
        getline((*_reader), line);
    }

    (*_reader) >> columns;
    (*_reader) >> rows;
    (*_reader) >> highest;
    int x;
    while(*(_reader) >> x)
    {
        values.push_back(x);
    }

    for(int j=0;j<values.size();j+=3)
    {
        Pixel p(values.at(j), values.at(j+1), values.at(j+2));
        pixels.push_back(p);
    }

    PPM* ppm = new PPM(format,rows,columns,highest,pixels);

    return ppm;
}