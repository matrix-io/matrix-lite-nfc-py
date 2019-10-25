#ifndef WRITE_H
#define WRITE_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_writer(py::module &);

#endif