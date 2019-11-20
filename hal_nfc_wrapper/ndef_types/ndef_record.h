#ifndef NDEF_RECORD_H
#define NDEF_RECORD_H

#include <pybind11/pybind11.h>
#include "matrix_nfc/nfc.h"
#include "matrix_nfc/nfc_data.h"

namespace py = pybind11;

std::string getTnf(matrix_hal::NDEFRecord *record);

typedef struct ndef_record {
    std::string          tnf;
    std::string          type;
    std::string          payload;
    int                  byteSize;
    int                  typeLength;
    int                  payloadLength;
    int                  IdLength;
 
} record;

void record_data(py::module &);

#endif