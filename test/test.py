import _matrix_hal_nfc as hal
from time import sleep

print(hal)

reader = hal.read()

while True:
    tag = reader.read_nfc({'info': True})

    print("technology: ",tag.info.technology)
    print("type: ",tag.info.type)
    print("UID: ",tag.info.UID)
    print("ATQ: ",tag.info.ATQ)
    print("SAK: ",tag.info.SAK)
    print("card_family: ",tag.info.card_family)
    print("IC_type: ",tag.info.IC_type)
    print("bit_rate: ",tag.info.bit_rate)
    print("storage_size: ",tag.info.storage_size)
    print("read_status: ",tag.info.read_status)
    print("\n")
    # print(hal.status(tag.info.read_status))

    # sleep(0.05)