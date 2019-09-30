import hal_nfc as hal
import matrix_lite_nfc as m

assert m.add(1, 2) == 3

print(hal)
print(hal.status(1024))
print(hal.status(256))