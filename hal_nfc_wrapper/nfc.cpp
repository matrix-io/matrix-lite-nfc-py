#include <pybind11/pybind11.h>

#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
// #include "ndef_types/ndef_parser.h"
// #include "ndef_types/ndef_record.h"

matrix_hal::NFC nfc;
matrix_hal::NFCData nfc_data;

// std::string status (int code) {
//   return matrix_hal::NFCStatus(code);
// }

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

PYBIND11_MODULE(hal_nfc, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: hal_nfc

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(add things)pbdoc");

    // m.def("status", &status, R"pbdoc(add things)pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}