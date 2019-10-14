# import _matrix_hal_nfc as hal
# import matrix_lite_nfc as nfc
from matrix_lite_nfc import read
import time
import asyncio

# print(nfc.read)
print(read)




# def read_nfc(code,tag):
#     print("nfc status:",code)
#     print(tag.info)

# def led_loop():
#     everloop = [{}] * led.length
#     everloop[0] = {'b':100}
#     while True:
#         print("led moving", everloop[0])
#         everloop.append(everloop.pop(0))
#         led.set(everloop)
#         time.sleep(0.05)

# start main
# led_loop()