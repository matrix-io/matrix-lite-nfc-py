#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "./read_values.h"
#include "./info.h"
#include "./pages.h"
#include "../../nfc.h"

namespace py = pybind11;

void nfc_read_values(py::module &m) {
    // Include NFC return values
    nfc_info_values(m);
    nfc_pages_values(m);
    //nfc_ndef_values(m);


    // Object to hold all data
    py::class_<nfc_read_result>(m, "nfc_read_result")
        .def(py::init())
        .def_readonly("info", &nfc_read_result::info)
        .def_readonly("pages", &nfc_read_result::pages)
        .def_readonly("page", &nfc_read_result::page)
        // .def_readonly("ndef", &nfc_read_result::ndef)
        .def("__repr__", [](const nfc_read_result &result) {
            return "TODO:";
        }
    );
}

// Populate read result with NFC read data
nfc_read_result::nfc_read_result(){

    // Populate struct with read data
    info = info_data();
    pages = pages_data();
    // ndef = ndef_data();   // doesn't exist yet
}