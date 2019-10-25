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


# msg = nfc.Message()
# msg.addTextRecord("Hello")
# msg.addTextRecord("Hola", "es")
# msg.addUriRecord("https://community.matrix.one")
# msg.addMimeMediaRecord("text/json", '{"answer": 42}')

# print(msg.__dir__())
# print(msg.toString(),'\n')
# print(msg.getRecordCount(),"\n*")

print(write.page(40, [65,65,65,65]))
time.sleep(1)
print(reader.scan({"page": 40}).page)
