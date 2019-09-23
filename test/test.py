import hal_nfc as hal
import matrix_lite_nfc as m

# assert m.__version__ == '0.0.1'
assert m.add(1, 2) == 3
print(hal.add(7,7))
print(m.add(1,6))
# assert m.subtract(1, 2) == -1