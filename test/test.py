import hal_nfc as hal
import matrix_lite_nfc as m

assert m.add(1, 2) == 3

print(hal)
print(hal.add(7,7))
print(hal.status(0))