# MATRIX-Lite-NFC-Py

![](https://github.com/matrix-io/matrix-lite-nfc-py/workflows/PyPi%20Deployment/badge.svg)

MATRIX Lite NFC Py is a package that allows users of varying skill levels to easily program NFC with their MATRIX Creator.

# Smartphone Apps For Debugging
- [IOS App](https://apps.apple.com/us/app/nfc-taginfo-by-nxp/id1246143596)
- [Android App](https://play.google.com/store/apps/details?id=com.nxp.nfc.tagwriter&hl=en_US)

# Roadmap
- [x] Reading Info  (All tags)
- [x] Reading Pages (MIFARE Ultralight & NTAG)
- [x] Writing Page  (MIFARE Ultralight & NTAG)
- [x] Reading NDEF  (MIFARE Ultralight & NTAG)
- [x] Writing NDEF  (MIFARE Ultralight & NTAG)

# Installation

## 1. Install MATRIX HAL NFC
https://github.com/matrix-io/matrix-hal-nfc

## 2. Install Python 3
> To call your scripts with python 3, use `python3 YOUR_SCRIPT.py`
```
sudo apt-get install python3-pip
```
## 3. Upgrade PIP
```
python3 -m pip install --upgrade pip
```

## 4. Install matrix-lite-nfc-py
```
python3 -m pip install --user matrix-lite
```

# Reference

## Import Statement
```py
import matrix_lite_nfc as nfc
```

## nfc.status
When a read or write function completes, it will contain a status code to indicate the result. nfc.Status returns a string of what that number means.
```py
nfc.status(/*number*/)
```

## nfc.read
> There can only be one instance of NFC reading. This is a hardware limitation that will not change.

### Synchronous Read
A simple read that returns an object with tag data.
```py
nfc.read.scan({
    # At least 1 read options is required. Less options -> faster reading!
    "info": True,  # Generic information for any NFC tag
    "pages": True, # All page data
    "ndef": True,  # A single page(faster than pages)
    "page": 0,     # All NDEF data
})
```

### Starting Read Loop
A non-blocking loop that passes tag data to a callback.
```py
def read_callback(tag):
    if(tag.status == 256):
        print("NFC Tag Scanned!")
        print(tag)
    elif(tag.status == 1024):
        print("Nothing Scanned!")

# Configure what you want to read
nfc.read.start({
    "rate": 0.5, # Read loop speed (Seconds)
    "info": True,
    "pages": True,
    "ndef": True,
    "page": 0,
}, read_callback)
```

### Stopping Read Loop
```py
nfc.read.stop()
```

## nfc.Message

### 1. Creating a new NDEF Message 
```py
# Create an empty NDEF message
msg = nfc.Message()

# Add NDEF Records to message
msg.addUriRecord("https://community.matrix.one")
msg.addUriRecord("tel:+14085551212")
msg.addTextRecord("Hello World")
msg.addTextRecord("Hola Mundo", "es")
msg.addMimeMediaRecord("text/json", '{"answer": 42}')

# You then pass msg into nfc.write.message(msg)
```

### 2. Reading a new NDEF Message 
```py
# Get NDEF data from scanned tag
tag = nfc.read.scan({"ndef": True})

# Create & print NDEF message
msg = nfc.Message(tag.ndef.content)
print(msg.getRecords())
```

## nfc.write
Writing to an NFC tag should normally be done inside the read loop.

### Writing an NDEF message
```py
# Create new message
msg = nfc.Message()
msg.addUriRecord("https://community.matrix.one")

# Write and then Print status codes for activation & writing
print(nfc.write.message(msg))
```

### Erasing an NDEF message
```py
print(nfc.write.erase())
```

### Writing to a tag's page (WARNING)
Be careful when writing to a page. You can accidentally lock your NFC tag!
```py
# arg1: page you want to overwrite
# arg2: Array of numbers that represents a byte
print(nfc.write.page(25, [48,45,59,21]))
```

# Building Locally For Development
Download the repository.
```
git clone https://github.com/matrix-io/matrix-lite-nfc-py
```

Install pybind11.
```
sudo python3 -m pip install pybind11
```

Compile and install library.
```
sudo python3 -m pip install ./matrix-lite-nfc-py
```

Test your changes by importing any of the following libraries into a `.py` file.
```py
# Direct C++ bindings
import _matrix_hal_nfc as hal_nfc

# Abstractions to _matrix_hal_nfc
import matrix_lite_nfc as nfc
```
