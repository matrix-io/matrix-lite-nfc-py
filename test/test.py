import _matrix_hal_nfc as hal
print(hal)
print(hal.__dir__())
# print(hal.status(1024))
# print(hal.status(256))

reader = hal.read()
tag = reader.read_nfc({'info': True})

print(tag)

print(tag.info)