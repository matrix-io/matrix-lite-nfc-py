#ifndef pages_H
#define pages_H

#include <pybind11/pybind11.h>
#include "../../nfc.h"

namespace py = pybind11;

struct pages_data {
    pages_data();

    py::bool_ read_complete;
    int read_status;
};

void nfc_pages_values(py::module &);

#endif