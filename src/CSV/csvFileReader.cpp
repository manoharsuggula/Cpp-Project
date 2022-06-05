#include "../../include/CSV/csvFileReader.h"
#include "../../include/CSV/csv.h"
#include <string>
#include <vector>

csvFileReader::csvFileReader(std::fstream* o):FileReader(o){

}
void* csvFileReader::read(){
    std::fstream *fin = readFile();
    int i{0},j{0};
    std::vector<std::vector<std::string>> Table,TableCopy;
    // fin->open(filename);
    std::string line, word, temp;
    if(fin->is_open()){
        while (!fin->eof()) { 
            std::vector<std::string> row; 
            Table.push_back(row); 
            std::vector<std::string> str;
            TableCopy.push_back(str); 
            getline(*fin, line); 
            std::stringstream s(line); 
            while (getline(s, word,',')) { 
                Table[i].push_back(word);
            }
            i++;
        }
    }
    csv *file = new csv(Table);
    return file;
}