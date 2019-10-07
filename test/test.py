import matrix_lite_nfc as m

assert m.add(1, 2) == 3


import _hal_nfc as hal
print(hal)
print(hal.status(1024))
print(hal.status(256))
print("Read()", hal.read({'info': True, 'pages': True}))