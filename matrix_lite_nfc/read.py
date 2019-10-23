import _matrix_hal_nfc as nfc
from threading import Thread
from time import sleep
_nfc = nfc.reader()

# Synchronous read function
scan = _nfc.scan


#TODO improve async implementation
##################################
# Async Read Loop
##################################
t = Thread
_keep_alive = False

# Loop to be used in a new thread
def _read_loop(options, callback):
    # Default rate
    if not "rate" in options:
        options["rate"] = 0.5
    
    # Start read loop
    global _keep_alive
    while _keep_alive:
        callback(_nfc.scan(options))
        sleep(options["rate"])

# Spawn a new read thread
def start(options, callback):
    global t, _keep_alive
    _keep_alive = True
    t = Thread(target=_read_loop, args=(options, callback))
    t.start()

# Stop read loop and gracefully stop thread
def stop():
    global t, _keep_alive
    _keep_alive = False
    try:
        t.join()
    except:
        pass
    