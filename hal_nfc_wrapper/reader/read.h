#ifndef READ_H
#define READ_H

#include <pybind11/pybind11.h>

namespace py = pybind11;

// NFC read data objects
struct Nfc_Read_Result {
    // TODO: change dicts to classes
    py::dict info;
    py::dict pages;
    py::dict page;
    py::dict ndef;
}

// Retrun data from last scanned nfc tag
py::dict get_nfc_info(int);
py::dict get_nfc_pages(int);
py::dict get_nfc_page(int);
py::dict get_nfc_ndef(int);

class reader {
    public:
    reader();

    py::class_ read_nfc(py::dict config);
};

void init_reader(py::module &);

#endif