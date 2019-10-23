#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/stl.h>
#include "./ndef_parser.h"
#include "../nfc.h"
#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
#include <iostream>

class ndef_parser {
    public:
    ndef_parser(){
        parser = matrix_hal::NDEFParser();
    };

    std::string toString() {
        return parser.ToString();
    }

    void addTextRecord(std::string text) {
        parser.AddTextRecord(text);
    }

    void addTextRecord(std::string text, std::string lang) {
        parser.AddTextRecord(text, lang);
    }

    void addUriRecord(std::string text) {
        parser.AddTextRecord(text);
    }

    void addEmptyRecord() {
        parser.AddEmptyRecord();
    }

    void addMimeMediaRecord(std::string mimeType, std::string payload) {
        parser.AddMimeMediaRecord(mimeType, payload);
    }

    int getRecordCount() {
        return parser.GetRecordCount();
    }

    int getEncodedSize() {
        return parser.GetEncodedSize();
    }

    private:
    matrix_hal::NDEFParser parser;
};

// **Exported NDEF Parser class** //
void init_ndef_parser(py::module &m) {
    py::class_<ndef_parser>(m, "Message")
        .def(py::init())
        .def("getEncodedSize", &ndef_parser::getEncodedSize)
        .def("getRecordCount", &ndef_parser::getRecordCount)
        .def("toString", &ndef_parser::toString)
        .def("addMimeMediaRecord", &ndef_parser::addMimeMediaRecord)
        .def("addEmptyRecord", &ndef_parser::addEmptyRecord)
        .def("addUriRecord", &ndef_parser::addUriRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string)) &ndef_parser::addTextRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string, std::string)) &ndef_parser::addTextRecord);
}