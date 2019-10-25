import _matrix_hal_nfc as nfc
__name__ = "matrix_lite_nfc"
__all__ = ["status", "read", "write"]

# Exported variables
status = nfc.status
Message = nfc.Message
write = nfc.writer()
import matrix_lite_nfc.read as read