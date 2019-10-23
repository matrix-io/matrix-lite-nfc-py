#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
// #include <pybind11/stl.h>
#include "./ndef_parser.h"
#include "./ndef_record.h"
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

    ndef_record getRecord(int index) {
        // Grab desired record
        matrix_hal::NDEFRecord record = parser[index];
        
        // Create record data to return
        ndef_record result;
        result.tnf           = record.GetTnf();
        result.type          = record.GetType();
        result.payload       = record.GetPayload();
        result.byteSize      = record.GetEncodedSize();
        result.typeLength    = record.GetTypeLength();
        result.payloadLength = record.GetPayloadLength();
        result.IdLength      = record.GetIdLength();

        return result;
    }

    // Return an array of ndef_records
    ndef_record* getRecords() {
        int records[parser.GetRecordCount()];

        std::cout << "Record Count: " << parser.GetRecordCount() << std::endl;

        for (int i = 0; i < parser.GetRecordCount(); i++){
            std::cout << i << std::endl;
        }

        return records;
    }

    private:
    matrix_hal::NDEFParser parser;
};

// **Exported NDEF Parser class** //
void init_ndef_parser(py::module &m) {
    record_data(m);

    py::class_<ndef_parser>(m, "Message")
        .def(py::init())
        .def("getRecords", &ndef_parser::getRecords)
        .def("getRecord", &ndef_parser::getRecord)
        .def("getEncodedSize", &ndef_parser::getEncodedSize)
        .def("getRecordCount", &ndef_parser::getRecordCount)
        .def("toString", &ndef_parser::toString)
        .def("addMimeMediaRecord", &ndef_parser::addMimeMediaRecord)
        // Removed because it seems buggy // .def("addEmptyRecord", &ndef_parser::addEmptyRecord)
        .def("addUriRecord", &ndef_parser::addUriRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string)) &ndef_parser::addTextRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string, std::string)) &ndef_parser::addTextRecord);
}