#include <pybind11/pybind11.h>
#include "./read_data.h"
#include "../nfc.h"

namespace py = pybind11;

void nfc_read_result_classes(py::module &m) {
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
        .def_readonly("updated", &info_data::updated)
        .def_readonly("read_status", &info_data::read_status);

    // Object to hold all data
    py::class_<nfc_read_result>(m, "nfc_read_result")
        .def(py::init())
        .def_readonly("info", &nfc_read_result::info);
}

// Initializer to populate read result with NFC read data
nfc_read_result::nfc_read_result(){

    // Populate info
    info = nfc_read_result::info;
    info.technology = nfc_data.info.technology;
    info.type = nfc_data.info.type;
    info.UID = nfc_data.info.UIDToHex().erase(0,2);
    info.ATQ = nfc_data.info.ATQToHex().erase(0,2);
    info.SAK = nfc_data.info.SAKToHex().erase(0,2);
    info.card_family = nfc_data.info.card_family;
    info.IC_type = nfc_data.info.IC_type;
    info.bit_rate = nfc_data.info.bit_rate;
    info.storage_size = nfc_data.info.storage_size;
    info.updated = nfc_data.info.recently_updated;
}