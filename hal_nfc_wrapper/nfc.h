#ifndef NFC_H
#define NFC_H

#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
#include <mutex>
#include <pybind11/pybind11.h>
#include <map>

namespace py = pybind11;

extern matrix_hal::NFC nfc;
extern matrix_hal::NFCData nfc_data;
extern std::mutex nfc_usage;

// Helpful functions for pybind11
namespace pyHelp {
    std::string to_lower_case(py::str);
    std::map<std::string, pybind11::handle> dict_to_map(py::dict);
}
#endif
