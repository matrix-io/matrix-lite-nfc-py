import _matrix_hal_nfc as hal
from time import sleep

def read_nfc(code,tag):
    print("nfc status:",code)
    print(tag.info)

reader = hal.read()

while True:
    reader.read_nfc({'info': True}, read_nfc)

    # print(tag.info)
    # print(hal.status(tag.info.read_status),"\n")
    # print(hal.status(tag.info.read_status))

    sleep(4)