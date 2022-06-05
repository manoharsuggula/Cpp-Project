#include "../../include/PLY/PLYFileWriter.h"
#include "../../include/PLY/PLYObject.h"

PLYFileWriter::PLYFileWriter()
: FileWriter() {}

PLYFileWriter::PLYFileWriter(std::fstream* o) 
: FileWriter(o) {}

PLYFileWriter::~PLYFileWriter() {}

void PLYFileWriter::write(void* o) {
    PLYObject* obj = (PLYObject*)o;
    std::fstream* out = writeFile();
    (*out) << "ply\n";
    (*out) << "format ascii 1.0\n";
    (*out) << "element vertex " + std::to_string(obj->vertices().size()) + "\n";
    (*out) << "property float32 x\nproperty float32 y\nproperty float32 z\n";
    (*out) << "element face " + std::to_string(obj->faces().size()) + "\n";
    (*out) << "property list uint8 int32 vertex_index\nend_header\n";
    for (auto vert: obj->vertices()) {
        (*out) << vert->x() << " " << vert->y() << ' ' << vert->z() << '\n';
    }
    for (auto face: obj->faces()) {
        (*out) << face->vertices().size() << ' ';
        for (auto vert: face->vertices()) {
            (*out) << vert << ' ';
        }
        (*out) << '\n';
    }
}