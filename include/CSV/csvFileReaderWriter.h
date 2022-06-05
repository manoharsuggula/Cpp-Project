#include"../FileReaderWriter.h"
#include"csvFileReader.h"
#include"csvFileWriter.h"
class csvFileReaderWriter:public FileReaderWriter{
    public:
        csvFileReaderWriter();
        ~csvFileReaderWriter();
        void setReadFile(std::fstream* o);
        void setWriteFile(std::fstream* o);
        void process();

}; 