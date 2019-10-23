import _matrix_hal_nfc as hal
# from matrix_lite_nfc import read
import time
import asyncio

########################
## SIMPLE READ FUNC   ##
reader = hal.reader()

# results = reader.scan({"rate": 1000,"info": True,"pages": True,"ndef": True,"page": 0,})