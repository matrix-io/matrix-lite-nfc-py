#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "./read.h"
#include "./read_values/read_values.h"
#include "../nfc.h"
#include <iostream>
#include <map>

namespace py = pybind11;
using namespace pybind11::literals;

// NFC reader class
class reader {
    public:
    reader(){};

    // Main logic for reading requested data from an NFC tag
    nfc_read_result nfc_read(py::dict config){
        // Avoid reading, if NFC is being used by another thread
        if (!nfc_usage.try_lock()){
            return nfc_read_result{}; // we avoid queuing since .read() will be in an endless loop
        }

        int nfc_status, info_status, pages_status, ndef_status;
        std::vector<uint8_t> nfc_page;

        auto options = pyHelp::dict_to_map(config);

        // Read requested data from NFC tag //
        // Values are stored in a global nfc object.
        if (options["info"] && options["info"].cast<bool>()) {
            nfc_status = nfc.Activate();
            info_status = nfc.ReadInfo(&nfc_data.info);
            nfc.Deactivate();
        }
        if (options["pages"] && options["pages"].cast<bool>()) {
            nfc_status = nfc.Activate();
            pages_status = nfc.mful.ReadPages(&nfc_data.pages);
            nfc.Deactivate();
        }
        if (options["page"]){
            int page = options["page"].cast<int>();
            if (page > -1){
                nfc_status = nfc.Activate();
                nfc_page = nfc.mful.ReadPage(page);
                nfc.Deactivate();
            }
        }
        if (options["ndef"] && options["ndef"].cast<bool>()) {
            nfc_status = nfc.Activate();
            ndef_status = nfc.ndef.Read(&nfc_data.ndef);
            nfc.Deactivate();
        }

        // Populate results with last scanned NFC tag
        nfc_read_result result = nfc_read_result();
        
        // Add remaining values to result
        result.info.read_status = info_status;
        result.pages.read_status = pages_status;
        result.page = nfc_page;
        result.ndef.read_status = ndef_status;
        result.status = nfc_status;

        // Allow other threads to use NFC
        nfc_usage.unlock();

        return result;
    }

    // * Not currently needed
    // - Read results are passed to the callback given
    // void read_callback(py::dict config, const std::function<void(nfc_read_result)> &callback) {
    //     callback(nfc_read(config));
    // }

    // - Read results are directly given
    nfc_read_result read(py::dict config) {
        py::gil_scoped_release release;
        auto result = nfc_read(config);
        
        py::gil_scoped_acquire acquire;
        return result;
    }
};

// **Exported NFC Reader class** //
void init_reader(py::module &m) {
    // Include class for nfc read data
    nfc_read_values(m);

    py::class_<reader>(m, "reader")
        .def(py::init())
        // .def("read", &reader::read_callback) // Currently unused
        .def("scan", &reader::read);
}