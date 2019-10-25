#ifndef NDEF_PARSER_H
#define NDEF_PARSER_H

#include <pybind11/pybind11.h>
#include "./ndef_record.h"
#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"
#include <list>

namespace py = pybind11;

class ndef_parser {
    private:
    matrix_hal::NDEFParser parser;

    public:
    ndef_parser();
    ndef_parser(std::vector<uint8_t> content);
    std::string toString();
    void addTextRecord(std::string text);
    void addTextRecord(std::string text, std::string lang);
    void addUriRecord(std::string text);
    void addEmptyRecord();
    void addMimeMediaRecord(std::string mimeType, std::string payload);
    int getRecordCount();
    int getEncodedSize();
    ndef_record getRecord(int index);
    std::list<ndef_record> getRecords();

    matrix_hal::NDEFParser* getParser();
};

void init_ndef_parser(py::module &);

#endif