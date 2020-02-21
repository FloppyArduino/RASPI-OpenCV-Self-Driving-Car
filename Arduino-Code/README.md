This is the 2 arduino files used to drive the car.
"Transmit" uses an NRF24L01 radio module to send a data struct with the motor variables on the car by getting serial data from my laptop.
The ai will generate 4 values(stop, forward, foward left and forward right) and send the value over serial.
the arduino will set the variables based on the movement and send it to the car.

"get" runs on the car also with the NRF module receiving the data and setting the hbridge accordingly to move the car
