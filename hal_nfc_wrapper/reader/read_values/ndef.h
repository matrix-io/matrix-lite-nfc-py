#ifndef ndef_H
#define ndef_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../../nfc.h"

namespace py = pybind11;

struct ndef_data {
    ndef_data();
    bool valid;
    std::vector<uint8_t> content;
    int read_status;
};

void nfc_ndef_values(py::module &);

#endif