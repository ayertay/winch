import ctypes

lib = ctypes.cdll.LoadLibrary("./libStWinchLib.so")

lib.add.argtypes = [ctypes.c_int, ctypes.c_int]
lib.add.restype = ctypes.c_int


lib.CoreRun.argtypes = [ctypes.c_int]
lib.CoreRun.restype = ctypes.c_int

lib.WinchReset.argtypes = [ctypes.c_void]
lib.WinchReset.restype = ctypes.c_void

lib.WinchDelivery.argtypes = [ctypes.c_int]
lib.WinchDelivery.restype = ctypes.c_void

result = lib.add(3, 4)
print("add = " + str(result))
