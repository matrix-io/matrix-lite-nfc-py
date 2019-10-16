#include <pybind11/pybind11.h>
#include "pages.h"
#include "../../nfc.h"

namespace py = pybind11;

// Python object for NFC Pages
void nfc_pages_values(py::module &m) {
    // Pages
    py::class_<pages_data>(m, "pages_data")
        .def_readonly("read_complete", &pages_data::read_complete)
        .def_readonly("read_status", &pages_data::read_status)
        .def("__repr__", [](const pages_data &pages) {
            return "";
        });
}

// Populate with last scanned NFC tag
pages_data::pages_data(){
    // If new tag scanned, give populated struct
    if (nfc_data.pages.recently_updated) {
        // * Fix for C++ boolean
        read_complete = nfc_data.pages.read_complete ? Py_True : Py_False;
    }
    // Else give empty struct
    else {
        read_complete = Py_False;
    }
}