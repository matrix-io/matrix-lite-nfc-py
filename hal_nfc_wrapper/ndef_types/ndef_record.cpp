#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/stl.h>
#include "./ndef_record.h"
#include "../nfc.h"
#include <iostream>

// **Exported NDEF Parser class** //
void record_data(py::module &m) {
    py::class_<ndef_record>(m, "Record")
        .def(py::init())
        .def_readonly("tnf", &ndef_record::tnf)
        .def_readonly("type", &ndef_record::type)
        .def_readonly("payload", &ndef_record::payload)
        .def_readonly("byteSize", &ndef_record::byteSize)
        .def_readonly("typeLength", &ndef_record::typeLength)
        .def_readonly("payloadLength", &ndef_record::payloadLength)
        .def_readonly("IdLength", &ndef_record::IdLength)
        .def("__repr__", [](const ndef_record &r) {
            return
            "tnf:"+              r.tnf+
            "\ntype: "+          r.type+
            "\npayload: "+       r.payload+
            "\nbyteSize: "+      std::to_string(r.byteSize)+
            "\ntypeLength: "+    std::to_string(r.typeLength)+
            "\npayloadLength: "+ std::to_string(r.payloadLength)+
            "\nIdLength: " +     std::to_string(r.IdLength)+"\n";
        });
}