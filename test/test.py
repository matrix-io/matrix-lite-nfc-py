import _matrix_hal_nfc as hal
# from matrix_lite_nfc import read
import time
import asyncio

########################
## SIMPLE READ FUNC   ##
reader = hal.reader()

results = reader.scan({"rate": 1000,"info": True,"pages": True,"ndef": True,"page": 0,})
print(results.info)

########################
## READ WITH CALLBACK ##

# Handle NFC data
def read_callback(tag):
    print(tag.status, hal.status(tag.status))
    print(tag.info)
    # print(tag.pages)
    # print(tag.ndef)
    # print(tag.page)

# Start read loop
reader.read({
    "rate": 1000,
    "info": True,
    "pages": True,
    "ndef": True,
    "page": 0,
},read_callback)