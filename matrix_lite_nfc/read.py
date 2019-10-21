import _matrix_hal_nfc as nfc
from threading import Thread
from time import sleep

_nfc = nfc.reader()
tag = _nfc.read


# Threading vars
t = Thread
keep_alive = False

# Loop to be used in a new thread
def _read_loop(options, callback):
    global keep_alive
    while keep_alive:
        _nfc.read(options,callback)
        sleep(options["rate"])

# Spawn a new read thread
def start(options, callback):
    global t, keep_alive
    keep_alive = True
    t = Thread(target=_read_loop, args=(options, callback))
    t.start()

# Stop read loop and gracefully stop thread
def stop():
    global t, keep_alive
    keep_alive = False
    t.join()