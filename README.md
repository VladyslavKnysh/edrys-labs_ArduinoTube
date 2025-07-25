# edrys-labs PIDtube

This online lab demonstrates a control system that uses an Arduino-based setup to levitate a ball in the air and maintain its position using a PID (Proportional-Integral-Derivative) controller. The system involves a fan that adjusts its output based on feedback from a laser sensor, allowing the ball to remain suspended at a set height. Students can interact with the system remotely, programming their own PID controller in real time to observe the effects on system stability, responsiveness, and accuracy. The lab offers hands-on experience in control theory and real-world PID implementation.

## Apperance
The appearance of the system can be seen in the photo below. A transparent PVC pipe 1 m long and a laboratory stand were used to create the frame of the system. The mounts were printed on a 3D printer.

<a href="url"><img src="https://github.com/VladyslavKnysh/edrys-labs_PIDtube/blob/main/media/photo.jpg" width="100" ></a>

## Code
The sample code can be found in the file example.ino .

## BOM
To build similar laboratory equipment next items: 

| Component            | Used in example      | Substitution                                                   | Function                                               |
| :-------------------:|:--------------------:| :--------------------------------------------------------------| :------------------------------------------------------|
| MCU                  | ArduinoNano          | Any Arduino or ESP board with 5V logic level and PWM functions | Controls the whole system + connects with the terminal |
| Transistor           | IRF520               | Any N-chanel MOSFET with low enough Vgs                        | Controls power supply of a motor                       |
| Diode                | SF26                 | Any fast diode                                                 | Electrical protection                                  |
| Laser-ranging module | VL53L0X              | Any similar module                                             | Measures the position of the ball                      |
| Motor                | 50000RPM drone motor | Any similar high-speed DC motor                                | Creates an air flow                                    |
| Ball                 | Ping-pong ball       | One and only                                                   | Acts as a liftable object                              |
| Cam                  | USB web-cam          | Any USB web-cam                                                | Shows the expirement to the whole wide world           |
| Power Supply         | 5V 2A DC PS          | PS unit that meets the requirements of your system             | Powers the whole system                                |
It should be noted that the thrust of the system greatly depends on the motor parameters, i.e., a more powerful motor will require lower coefficients and vice versa.

## Schematic
You can see the full electrical schematil on the picture lower:

![alt text](https://github.com/VladyslavKnysh/edrys-labs_PIDtube/blob/main/media/FullSchematic.png)


