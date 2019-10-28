#ifndef INFO_H
#define INFO_H

#include <pybind11/pybind11.h>
#include "../../nfc.h"

namespace py = pybind11;

struct info_data {
    info_data();
    std::string toString() const;
    std::string technology;
    std::string type;
    std::string UID;
    std::string ATQ;
    std::string SAK;
    std::string card_family;
    std::string IC_type;
    int bit_rate;
    int storage_size;
    int read_status;
};

void nfc_info_values(py::module &);

#endif