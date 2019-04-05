### Part 1
This part is a simulation where random vehicles (van, car, motorbike, bicycle) enter and exit the parking lot over a given period of time.
We read local time form the computer. The given period of time was set to 100. The price depends on the type of vehicle and time spent.
Output:
Arrival ticket containing time of arrival, type of the vehicle, some information (hint) on where to and an empty slot.
Departure ticket containing time spent in the parking lot, type of vehicle, price.

### Part 2
This part is to draw an interstellar parking lot and drive a car into a free slot. The parking lot has ten slots. There are 3 kinds of vehicles, UFO, Spacecraft, Car. Also a rectangle represents a reserved slot that not vehicles can park into. Specifications: a UFO spins on itself, a spacecraft continuously zooms in and out, a rectangle changes color as time changes.
There are several parts of our code.
The basic figure-rectangle, trapezium, circle, half circle and lines.
The part that draws all the vehicles.
The part that draw the route depends on the slot the vehicles head on.
The part that generate random vehicles and the reserved slots.
