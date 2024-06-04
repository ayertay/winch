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

lib.WinchDelivery(20)
#lib.WinchSetPos(10, 10)

bPWM_Min = 0
while True:
	sleep(1)
	fpos = lib.WinchGetPos();
	pwm_duty = lib.WinchGetPWMDuty();
	pwm_period = lib.WinchGetPWMPeriod();
	
	spos = round(fpos, 4);
	sPWMDuty = round(pwm_duty, 3);	
	sPWMPeriod = round(pwm_period, 3);
	
#	print("PWM_Duty = ")
#	print(sPWMDuty)

	#use PWM to control winch delivery, reset
	if pwm_duty>78.0:
		if bPWM_Min>0:
			lib.WinchDelivery(20)
		bPWM_Min = 0
	if pwm_duty<60.0 and pwm_duty>42.0:
		bPWM_Min = 2
	if pwm_duty<42.0:
		if bPWM_Min>1:
			lib.WinchReset()
		bPWM_Min = 1
	
#	print("pos = " + fpos + "PWM_Duty = " + fPWMDuty +  + "PWM_Period = " + fPWMPeriod)
	print("pos=" + str(fpos) + "    PWM_Duty=" + str(pwm_duty) + "%   PWM_Period=" + str(pwm_period)+"Hz")
