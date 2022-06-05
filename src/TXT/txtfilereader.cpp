
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../../include/TXT/txtfilereader.h"
#include "../../include/TXT/variables.h"

using namespace std;

txtfilereader::txtfilereader(std::fstream* o) : FileReader(o){}

void* txtfilereader::read()
{
    variables* v = new variables();

    fstream* myfile = readFile();
    string line;
    string str;
    char ch;

    (*myfile).seekg(0,ios::beg);
    while(getline((*myfile), line))
    {
        *(v->no_of_lines()) += 1;      //Calculating number lines by iterating lines
        *(v->characters_with_spaces()) += line.size();    //characters_with_spaces can be counted by adding
                                                     //line size for every line.
        for(int i=0; i < line.size(); i++)
        {
            if(isspace(line[i]))
            {
                *(v->spaces()) += 1;      //Calculating total spaces
            }
        }
    }

    (*myfile).clear();
    (*myfile).seekg(0, ios::beg);
    while((*myfile)>>line)
    {
        *(v->no_of_words()) += 1;   //Calculating number of words
    }

    (*myfile).clear();
    (*myfile).seekg(0, ios::end);
    *(v->bytes()) = (*myfile).tellg();      //this gives total bytes

    return static_cast<void*>(v);
}
