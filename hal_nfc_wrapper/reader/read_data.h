#ifndef READ_DATA_H
#define READ_DATA_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

struct info_data {
    std::string technology;
    std::string type;
    std::string UID;
    std::string ATQ;
    std::string SAK;
    std::string card_family;
    std::string IC_type;
    int bit_rate;
    int storage_size;
    bool updated;
    // int status;

    std::string __str__;
};

// Holds all nfc read data
typedef struct nfc_read_result {
    nfc_read_result();
    info_data info;

} nfc_read_result;

void nfc_read_result_classes(py::module &);

#endif