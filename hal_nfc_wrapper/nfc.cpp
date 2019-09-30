#include <pybind11/pybind11.h>
#include "./nfc.h"

matrix_hal::NFC nfc;
matrix_hal::NFCData nfc_data;

std::string status (int code) {
  return matrix_hal::NFCStatus(code);
}

int add(int i, int j) {
    return i + j;
}

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(hal_nfc, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    m.def("add", &add, R"pbdoc(add things)pbdoc");
    m.def("status", &status, R"pbdoc(add things)pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}