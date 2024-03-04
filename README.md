### Parking Sensor System

This embedded project utilizes AVR microcontrollers to create a distance measurement system using an ultrasonic sensor. The system is designed to provide real-time distance measurements and visual/audio feedback based on the measured distance to help parking the car.

#### Features:
- **Distance Measurement**: The system accurately measures distances using an ultrasonic sensor.
- **LCD Display**: Distance measurements are displayed in real-time on an LCD screen.
- **Audible Feedback**: The system provides audible feedback through a buzzer based on the measured distance.
- **Dynamic Display**: The LCD screen dynamically updates based on changes in the measured distance.
- **Intelligent Stop Sign Display**: The system intelligently displays stop signs on the LCD screen based on the proximity of obstacles.

#### Components Used:
- AVR Microcontroller
- Ultrasonic Sensor
- LCD Display
- Buzzer

#### Project Structure:
1. Application Layer (APP)
  - **main.c**: The main application file that orchestrates the interaction between different modules and controls the overall system behavior.
    
2. Hardware Abstraction Layer (HAL)
  - **LCD Driver**: Facilitates communication with the LCD display to numbers and results.
  - **ultrasonic.c/h**: Contains functions for initializing and controlling the ultrasonic sensor.
  - **buzzer.c/h**: Provides functionality for controlling the buzzer and generating audible feedback.
    
3. Microcontroller Abstraction Layer (MCAL)
  - **GPIO Driver**: Manages the MCU PINS and PORTS and the communcation between any external device.
  - **icu.c/h**: Implements the Input Capture Unit (ICU) driver for precise timing measurements.
  - **pwm.c/h**: Provides PWM signal generation for controlling the buzzer.

#### Usage:
1. Connect the AVR microcontroller to the necessary hardware components, including the ultrasonic sensor, LCD display, and buzzer.
2. Compile the project using an AVR development environment (e.g., Atmel Studio or eclipse ide).
3. Upload the compiled binary to the microcontroller.
4. Power on the system and observe the distance measurements displayed on the LCD screen.
5. The buzzer provides audible feedback based on the measured distance, alerting users to obstacles in their path.
6. You can run the simulation circuit using proteus simulation app. 

#### Note:
- Ensure proper wiring and connections between the microcontroller and hardware components.
- Adjust system parameters as needed for optimal performance and accuracy.
- Refer to the provided source code and documentation for detailed implementation and customization instructions.
