#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/stl.h>
#include "./ndef_parser.h"
#include "../nfc.h"
#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
#include <iostream>

class ndef_parser {
    public:
    ndef_parser(){
        parser = matrix_hal::NDEFParser();
    };

    private:
    matrix_hal::NDEFParser parser;
};

// **Exported NDEF Parser class** //
void init_ndef_parser(py::module &m) {
    py::class_<ndef_parser>(m, "message")
        .def(py::init())
        // .def("scan", &ndef_parser::read);
        ;
}