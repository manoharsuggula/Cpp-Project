#include "../../include/PPM/PPMFileWriter.h"

PPMFileWriter::PPMFileWriter(std::fstream* _obj) : FileWriter(_obj)
{}

PPMFileWriter::PPMFileWriter(){}


void PPMFileWriter::write(void* _obj)
{
    PPM* _object = (PPM*)(_obj);
    std::fstream* _writer = writeFile();
    (*_writer) << (*_object).get_format() <<"\n";
    (*_writer) << (*_object).get_columns() << " " << (*_object).get_rows() << "\n";
    (*_writer) << (*_object).get_highest() << "\n";
    vector<Pixel> pixels = (*_object).get_pix();
    for(int i=0; i<pixels.size();i++)
    {
        if(i%15 == 0)
        {
            (*_writer << "\n");
        }
        (*_writer) << pixels.at(i).get_red()<<" ";
        (*_writer) << pixels.at(i).get_green()<<" ";
        (*_writer) << pixels.at(i).get_blue()<<" ";
    }
}
