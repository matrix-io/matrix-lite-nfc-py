#include <pybind11/pybind11.h>
#include "./read.h"
#include "../nfc.h"
#include <iostream>

int read_nfc(int test){
    return test+1;
    // std::cout << "Read Results:" << std::endl;
}

namespace py = pybind11;
void init_reader(py::module &m) {
    m.def("read", &read_nfc);
}