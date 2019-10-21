#include <pybind11/pybind11.h>
#include "./ndef.h"
#include "../../nfc.h"

namespace py = pybind11;

// Python object for NFC NDEF
void nfc_ndef_values(py::module &m) {
    py::class_<ndef_data>(m, "ndef_data")
        .def_readonly("valid", &ndef_data::valid)
        .def_readonly("content", &ndef_data::content)
        .def_readonly("read_status", &ndef_data::read_status)

        .def("__repr__", [](const ndef_data &ndef) {
            return "";
        });
}

// Populate with last scanned NFC tag
ndef_data::ndef_data(){
    // If new tag scanned, populate struct
    if (nfc_data.ndef.recently_updated) {
        valid = nfc_data.ndef.valid; // ** Fix for C++ boolean conversion
        content = nfc_data.ndef.content;
    }
    // Else set struct as empty
    else {
        valid = false;
    }
}