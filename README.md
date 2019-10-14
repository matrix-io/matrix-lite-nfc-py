# MATRIX-Lite-NFC-Py

MATRIX Lite NFC Py is a package that allows users of varying skill levels to easily program NFC with their MATRIX Creator.

# Smartphone Apps For Debugging
- [IOS App](https://apps.apple.com/us/app/nfc-taginfo-by-nxp/id1246143596)
- [Android App](https://play.google.com/store/apps/details?id=com.nxp.nfc.tagwriter&hl=en_US)

# Roadmap
- [x] Reading Info  (All tags)
- [ ] Reading Pages (MIFARE Ultralight & NTAG)
- [ ] Writing Page  (MIFARE Ultralight & NTAG)
- [ ] Reading NDEF  (MIFARE Ultralight & NTAG)
- [ ] Writing NDEF  (MIFARE Ultralight & NTAG)

# Installation
1. Install [matrix-hal-nfc](https://github.com/matrix-io/matrix-hal-nfc) to use this library.

# Building Locally For Development
Download the repository.
```
git clone https://github.com/matrix-io/matrix-lite-nfc-py
```

Compile and install library
```
sudo python3 -m pip install ./matrix-lite-nfc-py
```

<!-- # Testing pybind11
```
# manual
git clone https://github.com/pybind/pybind11
cd pybind11

# compile examples
mkdir build
cd build
cmake ..
make check -j 4


# setup.py (not finished yet)
git clone https://github.com/matrix-io/matrix-hal-nfc
# sudo python3 -m pip install pybind11
# sudo python3 -m pip install setuptools
sudo python3 -m pip install ./matrix-lite-nfc-py

``` 

-->