import _matrix_hal_nfc as nfc
# from matrix_lite_nfc import read
import time
import asyncio

########################
##  SIMPLE READ FUNC  ##
reader = nfc.reader()
write = nfc.writer()

print(reader.scan({"info": True,"ndef": True, "pages": True}))
# print(reader.scan({"info": True, "page": 25, "ndef":True}).ndef)