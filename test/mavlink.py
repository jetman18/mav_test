from pymavlink import mavutil

# Create the connection to the top-side computer as companion computer/autopilot
master = mavutil.mavlink_connection('udpout:localhost:8500', source_system=1)

# Send a message for QGC to read out loud

master.mav.statustext_send(mavutil.mavlink.MAV_SEVERITY_NOTICE,
                           "QGC will read this".encode())

print('done')