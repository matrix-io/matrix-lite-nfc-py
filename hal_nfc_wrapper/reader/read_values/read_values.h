#ifndef READ_DATA_H
#define READ_DATA_H

#include <pybind11/pybind11.h>
#include "./read_values.h"
#include "./info.h"

namespace py = pybind11;

// Holds all nfc read data
typedef struct nfc_read_result {
    nfc_read_result();

    info_data info;

    
} nfc_read_result;

void nfc_read_result_classes(py::module &);

#endif