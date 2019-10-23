# MATRIX-Lite-NFC-Py

MATRIX Lite NFC Py is a package that allows users of varying skill levels to easily program NFC with their MATRIX Creator.

# Smartphone Apps For Debugging
- [IOS App](https://apps.apple.com/us/app/nfc-taginfo-by-nxp/id1246143596)
- [Android App](https://play.google.com/store/apps/details?id=com.nxp.nfc.tagwriter&hl=en_US)

# Roadmap
- [x] Reading Info  (All tags)
- [x] Reading Pages (MIFARE Ultralight & NTAG)
- [ ] Writing Page  (MIFARE Ultralight & NTAG)
- [ ] Reading NDEF  (MIFARE Ultralight & NTAG)
- [ ] Writing NDEF  (MIFARE Ultralight & NTAG)

# Installation
1. Install [matrix-hal-nfc](https://github.com/matrix-io/matrix-hal-nfc) to use this library.

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
There can only be one instance of NFC reading. This is a hardware limitation that will not change.

### Synchronous Read
This is a straightforward read that returns an object with tag data.
```py
nfc.read.scan()
```

### Starting Read Loop
This read is a non-blocking loop that passes tag data to a callback.
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
    # At least 1 read options is required. Less options -> faster reading!
    "info": True,  # Generic information for any NFC tag
    "pages": True, # All page data
    "ndef": True,  # A single page(faster than pages)
    "page": 0,     # All NDEF data
}, read_callback)
```

### Stopping Read Loop
```py
nfc.read.stop()
```


# Building Locally For Development
Download the repository.
```
git clone https://github.com/matrix-io/matrix-lite-nfc-py
```

Compile and install library
```
sudo python3 -m pip install ./matrix-lite-nfc-py
```