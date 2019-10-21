import _matrix_hal_nfc as nfc
import threading
from time import sleep

_nfc = nfc.reader()
t = threading.Thread
keep_alive = False

def _read(options, callback):
    global keep_alive
    while keep_alive:
        _nfc.read(options,callback)
        sleep(options["rate"])

# Spawn a new read thread
def start(options, callback):
    global t, keep_alive
    keep_alive = True
    t = threading.Thread(target=_read, args=(options, callback))
    t.start()

# Stop read loop and gracefully stop thread
def stop():
    global t, keep_alive
    keep_alive = False
    t.join()