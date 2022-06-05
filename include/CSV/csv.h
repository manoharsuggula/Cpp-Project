#include <vector>
#include <string>

using namespace std;

class csv {
    private:
        vector<vector<string>> Table,TableCopy;
    public:
        csv();
        csv(vector<vector<string>> Matrix);
        void setTable(vector<vector<string>> Matrix);
        void setCopyTable(vector<vector<string>> Matrix);
        vector<vector<string>> getTable();
        vector<vector<string>> getCopyTable();
        void operator = (const csv &csv1);
};