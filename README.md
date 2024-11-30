# Remote Controlled Car

## Description
This project is a 4-wheeled remote-controlled car built using Arduino, eletronics, motors, servos, legos, and cardboard. It allows users to control the car with a custom designed remote controller.

### Key Features:
- Remote control via wireless communication.
- Rear Wheel Drive and Front Wheel Steering.
- Freedom of 20-25 degree steering.
- Custom LEGO steering system and custom LEGO holders for components.

## Hardware Overview
The car is made up of the following components:
- **Motor Driver**: L298N motor driver for controlling motor direction and speed.
- **Motors**: 12V DC 200 RPM Motor
- **Controller**: Arduino Mega 2560
- **Connectivity**: NRF24L01 Transciever 
- **Power Supply**: NiMH 12V and 9V Rechargable Battery

## Software Overview
The software controlling the car includes:
- **Motor Control**: L298N Digital Pins that set direction and speed of motors.
- **Remote Communication**: NRF24L01 1-Way communication between controller and car.
- **Steering Control**: Standard Servo Library for Arduino

### Main Scripts:
- **`car_control.py`**: The reciever side that maps the controller inputs to the motor PWM output and servo steering positions.
- **`sensor_test.py`**: The transmitter for sending data packets of controller inputs to the reciever.
