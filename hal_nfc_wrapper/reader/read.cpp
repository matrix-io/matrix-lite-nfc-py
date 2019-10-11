#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include "./read.h"
#include "./read_values/read_values.h"
#include "../nfc.h"
#include <iostream>
#include <map>

namespace py = pybind11;
using namespace pybind11::literals;

reader::reader(){}

// **Exported NFC Reader class** //
void init_reader(py::module &m) {
    nfc_read_result_classes(m);

    py::class_<reader>(m, "read")
        .def(py::init())
        .def("read_nfc", &reader::read_nfc);
}

// TODO:
// 1. return void
// 2. accept callback
// 3. pass (nfc_read_result, nfc_status) to callback
// 4. allow async
nfc_read_result reader::read_nfc(py::dict config) {
    // Avoid reading, if NFC is being used by another thread
    if (!nfc_usage.try_lock()){
      return nfc_read_result{}; // we avoid queuing since .read() will be in an endless loop
    }

    int nfc_status, info_status, pages_status, ndef_status;
    std::vector<uint8_t> nfc_page;

    auto options = pyHelp::dict_to_map(config);

    // Read requested data from NFC tag //
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

    // Append read status to final result
    nfc_read_result result = nfc_read_result();
    result.info.read_status = info_status;
    // result.pages.read_status = pages_status; //Does not exist yet
    // result.page.read_status = page_status;   //Does not exist yet
    // result.ndef.read_status = ndef_status;   //Does not exist yet

    // Allow other threads to use NFC
    nfc_usage.unlock();

    return result;
}