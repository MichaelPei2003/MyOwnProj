import time 
from dronekit import connect, VehicleMode, LocationGlobalRelative 
from pymavlink import mavutil 
import send_body_ned_velocity

def to_release_area(vehicle):
    #30m
    flag1 = 0 #is bucket detected
    flag2 = 0 #double check bucket detected
    for i in 15:
        send_body_ned_velocity(0.8, 0, 0, 0.5, vehicle)
        #leave takeoff area
    for i in 23:
        send_body_ned_velocity(0.8, 0, 0, 0.5, vehicle)
        # flag1 = 
        if flag1 != 0:
            time.sleep(0.1)
            # flag2 = 
            # read detection outputs
            if flag2 != 0:
                break #release area reached
            
