#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include "./read.h"
#include "../nfc.h"
#include <iostream>
#include <map>

namespace py = pybind11;
using namespace pybind11::literals;

// **Exported NFC Reader class** //
void init_reader(py::module &m) {
    py::class_<reader>(m, "read")
        .def(py::init())
        .def("read_nfc", &reader::read_nfc);
}

reader::reader() {}

// TODO enable async & run callback
// look into https://github.com/pybind/pybind11/issues/813
py::class_ reader::read_nfc(py::dict config) {
    int nfc_status, info_status, pages_status, ndef_status;
    std::vector<uint8_t> nfc_page;

    // Get requested NFC data //
    auto options = pyHelp::dict_to_map(config);

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
    if (options["ndef"] && options["ndef"].cast<bool>()){
        nfc_status = nfc.Activate();
        ndef_status = nfc.ndef.Read(&nfc_data.ndef);
        nfc.Deactivate();
    }


    //@ return nfc data

    // TODO fill
    results = py::class_<Nfc_Read_Result>(m, "tag")
        .def(py::init<const std::string &>())
        
        .def_readwrite("info", &Nfc_Read_Result::info)
        .def_readwrite("pages", &Nfc_Read_Result::pages)
        .def_readwrite("page", &Nfc_Read_Result::page)
        .def_readwrite("ndef", &Nfc_Read_Result::ndef)
        // .attr("info") = get_nfc_info(info_status)
        // .attr("pages") = py::dict()
        // .attr("page") = py::dict()
        // .attr("ndef") = py::dict()
        .def("__repr__",
            [](const Pet &a) {
                return "TODO: finish this string";
            }
        );

    return results;
}

