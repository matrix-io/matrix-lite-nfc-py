#ifndef NDEF_PARSER_H
#define NDEF_PARSER_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_ndef_parser(py::module &);

#endif