import ctypes
#from gpiozero import Button
from time import sleep

#button1 = Button(18)
#button2 = Button(22)
#button1 = Button(3)
#button2 = Button(2)

lib = ctypes.cdll.LoadLibrary("./libStWinchLib.so")

lib.add.argtypes = [ctypes.c_int, ctypes.c_int]
lib.add.restype = ctypes.c_int

lib.WinchCoreRun.argtypes = [ctypes.c_int]
lib.WinchCoreRun.restype = ctypes.c_int

#lib.WinchReset

lib.WinchDelivery.argtypes = [ctypes.c_int]
lib.WinchDelivery.restype = ctypes.c_void_p

lib.WinchSetSpeed.argtypes = [ctypes.c_int]
lib.WinchSetPos.argtypes = [ctypes.c_int, ctypes.c_int]
#lib.WinchLoad
#lib.WinchLoadUP

lib.WinchGetPos.restype = ctypes.c_float
lib.WinchGetPWMDuty.restype = ctypes.c_float
lib.WinchGetPWMPeriod.restype = ctypes.c_float
lib.WinchGetTorque.restype = ctypes.c_float

result = lib.add(3, 4)
print("add = " + str(result))
result2 = lib.WinchCoreRun(3)


#lib.WinchSetPos(10, 10)
lib.WinchReset()
sleep(5)
lib.WinchSetPos(10, 5)
sleep(5)
lib.WinchSetPos(10, 10)
sleep(1)
lib.WinchSetPos(50, 50)
while lib.WinchGetPos() < 40:
    sleep(0.1)
    print(lib.WinchGetPos())
lib.WinchSetPos(10, 60)
sleep(3)
lib.WinchSetPos(10, 40)
sleep(3)
if abs(lib.WinchGetTorque()) < 0.12:
    lib.WinchSetPos(10, 10)
    sleep(5)
    lib.WinchReset()
else:
    print("Stuck")
bPWM_Min = 0
