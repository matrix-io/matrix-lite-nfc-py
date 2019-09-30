#include <pybind11/pybind11.h>
#include "./nfc.h"
#include "./reader/read.h"

matrix_hal::NFC nfc;
matrix_hal::NFCData nfc_data;

// Returns a string for the given status code.
// given by: activate, read, & write functions
std::string status (int code) {
  return matrix_hal::NFCStatus(code);
}

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(hal_nfc, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    m.def("status", &status, R"pbdoc(add things)pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}