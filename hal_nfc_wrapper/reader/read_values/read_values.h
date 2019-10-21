#ifndef READ_DATA_H
#define READ_DATA_H

#include <pybind11/pybind11.h>
#include "./read_values.h"
#include "./info.h"
#include "./pages.h"
#include "./ndef.h"

namespace py = pybind11;

// Represents all possible nfc read data
typedef struct nfc_read_result {
    nfc_read_result();

    info_data            info;
    pages_data           pages;
    std::vector<uint8_t> page;
    ndef_data            ndef;
 
} nfc_read_result;

void nfc_read_values(py::module &);

#endif