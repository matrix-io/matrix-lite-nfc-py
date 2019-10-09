#include <pybind11/pybind11.h>
#include "./read.h"
#include "../nfc.h"

namespace py = pybind11;
using namespace pybind11::literals;

// Functions to get data from the last scanned NFC tag //
// Appends status given to final python dictionary

py::dict get_nfc_info(int status) {
    return py::dict(
        "technology"_a=nfc_data.info.technology,
        "type"_a=nfc_data.info.type,
        "UID"_a=nfc_data.info.UIDToHex().erase(0,2),
        "ATQ"_a=nfc_data.info.ATQToHex().erase(0,2),
        "SAK"_a=nfc_data.info.SAKToHex().erase(0,2),
        "card_family"_a=nfc_data.info.card_family,
        "IC_type"_a=nfc_data.info.IC_type,
        "bit_rate"_a=nfc_data.info.bit_rate,
        "storage_size"_a=nfc_data.info.storage_size,
        "updated"_a=nfc_data.info.recently_updated,
        "read_status"_a=status
    );
}

// TODO: pages

// TODO: page

// TODO: ndef