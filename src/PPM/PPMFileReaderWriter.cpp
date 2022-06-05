#include "../../include/PPM/PPMFileReaderWriter.h"

PPMFileReaderWriter::PPMFileReaderWriter() : FileReaderWriter()
{}

PPMFileReaderWriter::~PPMFileReaderWriter() {
    delete (PPM*)object();
}

void PPMFileReaderWriter::setReadFile(std::fstream* o)
{
    PPMFileReader* reader = new PPMFileReader(o);
    setReader(reader);
}


void PPMFileReaderWriter::setWriteFile(std::fstream* o)
{
    PPMFileWriter* writer = new PPMFileWriter(o);
    setWriter(writer);
}

void PPMFileReaderWriter::process()
{
    void* _object = object();
    PPM* _obj = (PPM*)(_object);
    vector<Pixel> pixels =_obj->get_pix();
    for(int i=0;i<pixels.size();i++)
    {
        int r,g,b;
        r = pixels.at(i).get_red();
        g = pixels.at(i).get_green();
        b = pixels.at(i).get_blue();
        pixels.at(i).set_red(b);
        pixels.at(i).set_green(r);
        pixels.at(i).set_blue(g);
    }
    _obj->set_pix(pixels);
    _object = _obj;
}