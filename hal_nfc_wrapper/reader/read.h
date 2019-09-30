
#ifndef READ_H
#define READ_H

#include <pybind11/pybind11.h>
namespace py = pybind11;

// TODO: create readResults struct

// Determines which read functions to use in read()
struct readOptions {
  bool info;
  bool pages;
  int page;
  bool ndef;
};

void init_reader(py::module &);

#endif