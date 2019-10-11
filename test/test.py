import _matrix_hal_nfc as hal
from time import sleep

print(hal)

reader = hal.read()

while True:
    tag = reader.read_nfc({'info': True})

    print(tag.info.UID)
    print(tag.info.updated)
    print(tag.info.technology)

    sleep(0.3)