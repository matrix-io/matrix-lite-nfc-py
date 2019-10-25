#ifndef pages_H
#define pages_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "../../nfc.h"

namespace py = pybind11;

struct pages_data {
    pages_data();
    std::string toString();
    bool read_complete;
    int read_status;
    std::vector<std::vector<uint8_t>> content;
};

void nfc_pages_values(py::module &);

#endif