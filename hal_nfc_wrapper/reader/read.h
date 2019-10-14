#ifndef READ_H
#define READ_H

#include <pybind11/pybind11.h>
#include "./read_values/read_values.h"

namespace py = pybind11;

void init_reader(py::module &);

#endif