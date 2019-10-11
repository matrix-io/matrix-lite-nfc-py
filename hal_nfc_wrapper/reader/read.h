#ifndef READ_H
#define READ_H

#include <pybind11/pybind11.h>
#include "./read_data.h"

namespace py = pybind11;

class reader {
    public:
    reader();

    nfc_read_result read_nfc(py::dict config);
};

void init_reader(py::module &);

#endif