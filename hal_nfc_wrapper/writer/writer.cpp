#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "./write.h"
#include "../ndef_types/ndef_parser.h"
#include "../nfc.h"
#include <iostream>
#include <map>

namespace py = pybind11;

// Status codes for nfc.write
typedef struct nfc_write_result{
    int activation;
    int write;
} nfc_write_result;

// NFC reader class
class writer {
    public:
    writer(){};
    
    nfc_write_result page(int page_index, std::vector<uint8_t> page_byte){
        py::gil_scoped_release release;

        // Write to a page
        nfc_usage.lock();
        int nfc_status = nfc.Activate();
        int page_status = nfc.mful.WritePage(page_index, page_byte);
        nfc.Deactivate();
        nfc_usage.unlock();

        py::gil_scoped_acquire acquire;
        return nfc_write_result {nfc_status, page_status};
    }

    nfc_write_result erase(){
        py::gil_scoped_release release;

        // Erase NDEF message
        nfc_usage.lock();
        int nfc_status = nfc.Activate();
        int erase_status = nfc.ndef.Erase();
        nfc.Deactivate();
        nfc_usage.unlock();

        py::gil_scoped_acquire acquire;
        return nfc_write_result {nfc_status, erase_status};
    }

    nfc_write_result message(ndef_parser message){
        py::gil_scoped_release release;

        // Write NDEF message
        nfc_usage.lock();
        int nfc_status = nfc.Activate();
        int ndef_status = nfc.ndef.Write(message.getParser());
        nfc.Deactivate();
        nfc_usage.unlock();

        py::gil_scoped_acquire acquire;
        return nfc_write_result {nfc_status, ndef_status};
    }
};

// **Exported NFC Writer classes** //
void init_writer(py::module &m) {
    py::class_<nfc_write_result>(m, "nfc_write_result")
        .def(py::init())
        .def_readonly("activation", &nfc_write_result::activation)
        .def_readonly("write", &nfc_write_result::write)
        .def("__repr__", [](const nfc_write_result &status) {
            return
                "activation: "+std::to_string(status.activation)+
                "\nwrite: "   +std::to_string(status.write);
        });

    py::class_<writer>(m, "writer")
        .def(py::init())
        .def("page", &writer::page)
        .def("erase", &writer::erase)
        .def("message", &writer::message);
}