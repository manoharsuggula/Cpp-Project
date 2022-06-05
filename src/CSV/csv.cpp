#include "../../include/CSV/csv.h"

csv::csv(){}

csv::csv(vector<vector<string>> Matrix){
    setTable(Matrix);
}

void csv::setTable(vector<vector<string>> Matrix){
    for(int i=0;i<Matrix.size();i++){
        (this->Table).push_back(Matrix[i]);
    }
}

vector<vector<string>> csv::getTable(){
    return this->Table;
}

vector<vector<string>> csv::getCopyTable(){
    return this->TableCopy;
}

void csv::setCopyTable(vector<vector<string>> Matrix){
    for(int i=0;i<Matrix.size();i++){
        (this->TableCopy).push_back(Matrix[i]);
    }
}

void csv::operator=(const csv &csv1){
    Table = csv1.Table;
    TableCopy = csv1.TableCopy;
}