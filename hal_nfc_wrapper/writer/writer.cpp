#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/stl.h>
#include "./write.h"
#include "../ndef_types/ndef_parser.h"
#include "../nfc.h"
#include <iostream>
#include <map>

namespace py = pybind11;

// NFC reader class
class writer {
    public:
    writer(){};

    void page(int page_index, std::vector<uint8_t> page_byte){}
    // void message(ndef msg){}
};

// **Exported NFC Writer class** //
void init_writer(py::module &m) {
    py::class_<writer>(m, "writer")
        .def(py::init())
        // .def("message", &writer::message)
        .def("page", &writer::page);
}