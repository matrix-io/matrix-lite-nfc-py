import _matrix_hal_nfc as nfc
# from matrix_lite_nfc import read
import time
import asyncio

########################
##  SIMPLE READ FUNC  ##
reader = nfc.reader()
write = nfc.writer()

results = reader.scan({"ndef": True})
msg = nfc.Message(results.ndef.content)
print(msg)
print(msg.getRecords())


print(nfc.write.erase())