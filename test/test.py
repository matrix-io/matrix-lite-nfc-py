import _matrix_hal_nfc as hal
from time import sleep

print(hal)

reader = hal.read()

while True:
    tag = reader.read_nfc({'info': True})

    print(tag.info)
    print(hal.status(tag.info.read_status),"\n")
    # print(hal.status(tag.info.read_status))

    sleep(4)