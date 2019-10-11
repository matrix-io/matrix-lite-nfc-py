#include <pybind11/pybind11.h>
#include "info.h"
#include "../../nfc.h"

namespace py = pybind11;

void nfc_info_values(py::module &m) {
    // Info
    py::class_<info_data>(m, "info_data")
        .def_readonly("technology", &info_data::technology)
        .def_readonly("type", &info_data::type)
        .def_readonly("UID", &info_data::UID)
        .def_readonly("ATQ", &info_data::ATQ)
        .def_readonly("SAK", &info_data::SAK)
        .def_readonly("card_family", &info_data::card_family)
        .def_readonly("IC_type", &info_data::IC_type)
        .def_readonly("bit_rate", &info_data::bit_rate)
        .def_readonly("storage_size", &info_data::storage_size)
        .def_readonly("read_status", &info_data::read_status)
        .def("__repr__", [](const info_data &info) {
                return "TODO: make this string";
            }
        );
}

// Populate with last scanned NFC tag
info_data::info_data(){
    if (nfc_data.info.recently_updated){
        technology = nfc_data.info.technology;
        type = nfc_data.info.type;
        UID = nfc_data.info.UIDToHex().erase(0,2);
        ATQ = nfc_data.info.ATQToHex().erase(0,2);
        SAK = nfc_data.info.SAKToHex().erase(0,2);
        card_family = nfc_data.info.card_family;
        IC_type = nfc_data.info.IC_type;
        bit_rate = nfc_data.info.bit_rate;
        storage_size = nfc_data.info.storage_size;
    }
    // Else pass empty struct
    else{
        technology = "";
        type = "";
        UID = "";
        ATQ = "";
        SAK = "";
        card_family = "";
        IC_type = "";
        bit_rate = 0;
        storage_size = 0;
    }
}