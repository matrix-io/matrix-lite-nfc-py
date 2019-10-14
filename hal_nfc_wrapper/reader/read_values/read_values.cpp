#include <pybind11/pybind11.h>
#include "./read_values.h"
#include "./info.h"
#include "../../nfc.h"

namespace py = pybind11;

void nfc_read_values(py::module &m) {
    // Include NFC return values
    nfc_info_values(m);
    //nfc_pages_values(m);
    //nfc_page_values(m);
    //nfc_ndef_values(m);


    // Object to hold all data
    py::class_<nfc_read_result>(m, "nfc_read_result")
        .def(py::init())
        .def_readonly("info", &nfc_read_result::info)
        .def("__repr__", [](const nfc_read_result &result) {
            return "TODO:";
        }
    );
}

// Populate read result with NFC read data
nfc_read_result::nfc_read_result(){

    // Populate struct with read data
    info = info_data();
    // pages = nfc_read_result::pages; // doesn't exist yet
    // page = nfc_read_result::page;   // doesn't exist yet
    // ndef = nfc_read_result::ndef;   // doesn't exist yet
}