#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <map>
#include "./nfc.h"
#include "./reader/read.h"
#include "./writer/write.h"
#include "./ndef_types/ndef_parser.h"

matrix_hal::NFC nfc;
matrix_hal::NFCData nfc_data;
std::mutex nfc_usage;

// Returns a string for the given status code.
// given by: activate, read, & write functions
std::string status (int code) {
  return matrix_hal::NFCStatus(code);
}

// Exported Python module
namespace py = pybind11;
PYBIND11_MODULE(_matrix_hal_nfc, m) {
    m.doc() = R"pbdoc(Docs coming soon)pbdoc";
    m.def("status", &status);

    init_reader(m);
    init_writer(m);
    init_ndef_parser(m);

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}

// Helper functions for pybind11
namespace pyHelp {
    // - Convert python String to lowercase c++ string
    std::string to_lower_case(py::str py_str){
        std::string str = py_str.cast<std::string>();

        for(uint i=0;i<str.length();i++)
            str.at(i)=std::tolower(str.at(i));

        return str;
    }

    // - Return c++ map from python dictionary
    std::map<std::string, pybind11::handle> dict_to_map(py::dict dict){
        std::map<std::string, pybind11::handle> map;
        
        for (auto item : dict)
            map[std::string(py::str(item.first))]=item.second;
        
        return map;
    }
}