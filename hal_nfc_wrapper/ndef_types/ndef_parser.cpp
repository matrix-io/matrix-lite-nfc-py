#include <pybind11/pybind11.h>
// #include <pybind11/functional.h>
#include <pybind11/stl.h>
#include "./ndef_parser.h"
#include "./ndef_record.h"
#include "../nfc.h"
#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
#include <iostream>
#include <list>

ndef_parser::ndef_parser() {
    parser = matrix_hal::NDEFParser();
}

ndef_parser::ndef_parser(std::vector<uint8_t> content) {
    // Create new NDEF content from user input
    matrix_hal::NDEFContent ndef_content;
    ndef_content.valid = true; // assume it's valid
    ndef_content.content = content;

    // Initialize ndef_parser with user's NDEF content
    parser = matrix_hal::NDEFParser(&ndef_content);
}

std::string ndef_parser::toString() {
    return parser.ToString();
}

void ndef_parser::addTextRecord(std::string text) {
    parser.AddTextRecord(text);
}

void ndef_parser::addTextRecord(std::string text, std::string lang) {
    parser.AddTextRecord(text, lang);
}

void ndef_parser::addUriRecord(std::string text) {
    parser.AddTextRecord(text);
}

void ndef_parser::addEmptyRecord() {
    parser.AddEmptyRecord();
}

void ndef_parser::addMimeMediaRecord(std::string mimeType, std::string payload) {
    parser.AddMimeMediaRecord(mimeType, payload);
}

int ndef_parser::getRecordCount() {
    return parser.GetRecordCount();
}

int ndef_parser::getEncodedSize() {
    return parser.GetEncodedSize();
}

matrix_hal::NDEFParser* ndef_parser::getParser(){
    return &parser;
}

ndef_record ndef_parser::getRecord(int index) {
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

std::list<ndef_record> ndef_parser::getRecords() {
    std::list<ndef_record> records = {};

    for (unsigned int i = 0; i < parser.GetRecordCount(); i++)
        records.push_back(getRecord(i));

    return records;
}

// **Exported NDEF Parser class** //
void init_ndef_parser(py::module &m) {
    record_data(m);

    py::class_<ndef_parser>(m, "Message")
        .def(py::init())
        .def(py::init<std::vector<uint8_t>>())
        .def("getRecords", &ndef_parser::getRecords)
        .def("getRecord", &ndef_parser::getRecord)
        .def("getEncodedSize", &ndef_parser::getEncodedSize)
        .def("getRecordCount", &ndef_parser::getRecordCount)
        .def("toString", &ndef_parser::toString)
        .def("addMimeMediaRecord", &ndef_parser::addMimeMediaRecord)
        // .def("addEmptyRecord", &ndef_parser::addEmptyRecord) // Removed because it seems buggy 
        .def("addUriRecord", &ndef_parser::addUriRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string)) &ndef_parser::addTextRecord)
        .def("addTextRecord", (void (ndef_parser::*)(std::string, std::string)) &ndef_parser::addTextRecord);
}