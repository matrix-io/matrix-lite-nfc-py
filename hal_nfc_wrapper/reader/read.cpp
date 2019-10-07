#include <pybind11/pybind11.h>
#include "./read.h"
#include "../nfc.h"
#include <iostream>
#include <map>

int read_nfc(py::dict options){
    read_options default_options {false,false,-1,false};
    
    // Set each given option
    for (auto item : options){
        std::cout << "key=" << std::string(py::str(item.first)) << ", "
            << "value=" << std::string(py::str(item.second)) << std::endl;
    }
    
    std::cout << "Read Results:" << std::endl;
    return 2222;
    // std::cout << "Read Results:" << std::endl;
}

namespace py = pybind11;
void init_reader(py::module &m) {
    m.def("read", &read_nfc);
}