import ctypes
#from gpiozero import Button
from time import sleep

#button1 = Button(18)
#button2 = Button(22)
#button1 = Button(3)
#button2 = Button(2)

#=====================================================
#libStWinchLib interface defination
#==================================
#lib = ctypes.cdll.LoadLibrary("./libStWinchLib.so.1.0.0")
lib = ctypes.cdll.LoadLibrary("./libStWinchLib.so")

lib.add.argtypes = [ctypes.c_int, ctypes.c_int]
lib.add.restype = ctypes.c_int

lib.WinchCoreRun.argtypes = [ctypes.c_int]
lib.WinchCoreRun.restype = ctypes.c_int

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


lib.WINCH_DELIVER.argtypes = [ctypes.c_float, ctypes.c_float]
lib.WINCH_DELIVER.restype = ctypes.c_void_p

#lib.WINCH_RETRACT.argtypes = [ctypes.c_float]
#lib.WINCH_RETRACT.restype = ctypes.c_void_p
#lib.WINCH_RELAXED

lib.WINCH_LINE_LENGTH.restype = ctypes.c_float

lib.WINCH_CAN_ECHO.argtypes = [ctypes.c_int]

#=====================================================

result = lib.add(3, 4)
print("add = " + str(result))

result2 = lib.WinchCoreRun(3)
lib.WINCH_CAN_ECHO(0)
sleep(3)

#lib.WINCH_LATCH_UNLOCK()
#print("WINCH_LATCH_UNLOCK")
#sleep(10)
#lib.WinchSetPos(5, 55)
#print("WinchSetPos(5, 55)")
#sleep(50)

#sleep(10)
#lib.WINCH_RELAXED()
#print("WINCH_RELAXED")
#sleep(5)

f_line_len = lib.WINCH_LINE_LENGTH()
print("WINCH_LINE_LENGTH = " + str(f_line_len) + "  rad")
sleep(5)
lib.WINCH_CAN_ECHO(1)

while True:
	sleep(1)
    
	lib.WINCH_LOCK()
	sleep(2)
	print("LOCK")
	sleep(10)

	lib.WINCH_DELIVER(0, 10.0)
	sleep(10)
	print("WINCH_DELIVER")
	sleep(60)

#	fpos = lib.WinchGetPos();
#	pwm_duty = lib.WinchGetPWMDuty();
#	pwm_period = lib.WinchGetPWMPeriod();
	
#	spos = round(fpos, 4);
#	sPWMDuty = round(pwm_duty, 3);	
#	sPWMPeriod = round(pwm_period, 3);
	
#	print("pos=" + str(fpos) + "    PWM_Duty=" + str(pwm_duty) + "%   PWM_Period=" + str(pwm_period)+"Hz")


