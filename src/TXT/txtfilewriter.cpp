#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "../../include/TXT/txtfilewriter.h"
#include "../../include/TXT/variables.h"

using namespace std;

txtfilewriter::txtfilewriter(std::fstream* o) : FileWriter(o){}

void txtfilewriter::setInpFileName(char* fileName) {
    _inpFileName = fileName;
}

void txtfilewriter::write(void* v)
{
    variables *x=static_cast<variables*> (v);

    fstream* newfile = writeFile();

    fstream myfile(_inpFileName);

    (*newfile) << "Document Statistics :-" << "\n";     //printing Document Statistics
    if (*(x->no_of_lines()) != 0)
    {
        (*newfile) << "Lines : " << *(x->no_of_lines()) << "\n";
        (*newfile) << "Words : " << *(x->no_of_words()) << "\n";
        (*newfile) << "Characters (with spaces) : " << *(x->characters_with_spaces()) + *(x->no_of_lines()) - 1 << "\n";
        (*newfile) << "Characters (no spaces) : " << *(x->characters_with_spaces()) - *(x->spaces()) << "\n";
        (*newfile) << "Bytes : " << *(x->bytes()) - 1 << "\n" << "\n";
    }
    else
    {
        (*newfile) << "Lines : " << "0" << "\n";
        (*newfile) << "Words : " << "0" << "\n";
        (*newfile) << "Characters (with spaces) : " << "0" << "\n";
        (*newfile) << "Characters (no spaces) : " << "0" << "\n";
        (*newfile) << "Bytes : " << "0" << "\n" << "\n";
    }

    (*newfile) << "Original Document :-" << "\n";
    string str;
    
    if((*newfile) && myfile)   //copying file data to new file
    {
        while(getline(myfile, str))
        {
            (*newfile) << str << "\n";
        }
    }
    
}
