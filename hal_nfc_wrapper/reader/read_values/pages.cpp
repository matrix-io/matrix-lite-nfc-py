#include <pybind11/pybind11.h>
#include "./pages.h"
#include "../../nfc.h"

namespace py = pybind11;

// Python object for NFC Pages
void nfc_pages_values(py::module &m) {
    py::class_<pages_data>(m, "pages_data")
        .def_readonly("read_complete", &pages_data::read_complete)
        .def_readonly("content", &pages_data::content)
        .def_readonly("read_status", &pages_data::read_status)
        .def("__repr__", &pages_data::toString);
}

// Populate with last scanned NFC tag
pages_data::pages_data() {
    // If new tag scanned, populate struct
    if (nfc_data.pages.recently_updated) {
        read_complete = nfc_data.pages.read_complete;// ** Fix for C++ boolean conversion
        content = nfc_data.pages.content;
    }
    // Else set struct as empty
    else {
        read_complete = false;
    }
}

std::string pages_data::toString() const {
    // Create string from 2D vector
    std::string printed_content = "[\n";
    for ( std::vector<uint8_t> &page : nfc_data.pages.content ) {
        printed_content += "[ ";
        for ( int x : page ) printed_content.append(std::to_string(x)+", ");
        printed_content.append("], ");
    }
    printed_content += "]";

    return
        "pages {\n\tread_complete: "+std::to_string(read_complete)+
        "\n\tcontent: "+printed_content+
        "\n\tread_status: "+std::to_string(read_status)+
    "\n}\n";
}