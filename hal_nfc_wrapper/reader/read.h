
#ifndef READ_H
#define READ_H

// TODO: create readResults struct

// Determines which read functions to use in read()
struct readOptions {
  bool info;
  bool pages;
  int page;
  bool ndef;
};

readOptions read(/*add a return*/);

#endif