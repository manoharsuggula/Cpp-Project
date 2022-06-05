#include "../../include/PLY/PLYFileReader.h"

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static inline std::string trim(std::string &s) {
    ltrim(s);
    rtrim(s);
    return s;
}

PLYFileReader::PLYFileReader() {}

PLYFileReader::PLYFileReader(std::fstream* o)
: FileReader(o) {}

void* PLYFileReader::read() {
    std::fstream* o = readFile();
    while (o->good()) {
        std::string line;
        std::getline(*o, line);
        std::stringstream ss(line);
        std::vector<std::string> ins;
        while (ss.good()) {
            std::string s;
            ss >> s;
            ins.push_back(s);
        }
        _instructions.push_back(ins);
    }
    return _getPLYObject();
}

PLYFileReader::~PLYFileReader() {}

PLYObject* PLYFileReader::_getPLYObject() {
    size_t i = 2;
    // if (_instructions[i++][0] != "ply") throw "Invalid Start of File";
    // if (trim(_instructions[i][0]) != "format" || trim(_instructions[i][1]) == "ascii" || trim(_instructions[i++][2]) == "1.0") 
        //throw "Invalid Format Specifier";
    size_t numVertices = 0;
    size_t numFaces = 0;
    bool takeVertexProperty = false;
    std::vector<std::string> vertex_id;
    bool takeFaceProperty = false;
    while (_instructions[i][0] != "end_header") {
        if (_instructions[i][0] == "comment") {
            i++;
            continue;
        }
        /*
        if (takeVertexProperty && _instructions[i][0] == "property") {
            if (_instructions[i][0] == "x" && (std::find(vertex_id.begin(), vertex_id.end(), "x") == vertex_id.end())) {
                
            }
        } else {
            throw "Invalid Instruction Line";
        }
        */
        if (_instructions[i][0] == "element") {
            if (_instructions[i][1] == "vertex") {
                numVertices = atoi(_instructions[i][2].c_str());
                takeVertexProperty = true;
            }
            if (_instructions[i][1] == "face") {
                numFaces = atoi(_instructions[i][2].c_str());
                takeFaceProperty = true;
            }
        }
        i++;
    }
    i++;
    VertexVectorType vertices;
    for (size_t j = 0; j < numVertices; j++, i++) {
        double x = atof(_instructions[i][0].c_str());
        double y = atof(_instructions[i][1].c_str());
        double z = atof(_instructions[i][2].c_str());
        vertices.push_back(new VertexType(x, y, z));
    }
    FaceVectorType faces;
    for (size_t j = 0; j < numFaces; j++, i++) {
        int numVerticesinFace = atoi(_instructions[i][0].c_str());
        Face* face = new Face();
        for (int k = 0; k < numVerticesinFace; k++) {
            int vertIndex = atoi(_instructions[i][k + 1].c_str());
            face->addVertex(vertIndex);
        }
        faces.push_back(face);
    }
    return new PLYObject(vertices, faces);
}