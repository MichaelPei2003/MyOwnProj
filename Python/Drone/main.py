import time 
from dronekit import connect, VehicleMode, LocationGlobalRelative 
from pymavlink import mavutil 
import arm_and_takeoff, send_body_ned_velocity

#connect to drone
connection_string ='/dev/ttyACM0' #Com of current FCM connection
print('Connectingto vehicle on: %s' % connection_string) 
vehicle = connect(connection_string, wait_ready=False) 

arm_and_takeoff(1, vehicle) #arm_and_takeoff(aTargetAltitude, vehicle)

