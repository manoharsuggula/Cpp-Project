#include"../FileWriter.h"
#include"ios"
class csvFileWriter: public FileWriter{
    public:
        csvFileWriter();
        csvFileWriter(std::fstream *o);
        void write(void*);
};