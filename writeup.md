## Describe the effect each of the P, I, D components had in your implementation.

Proportional (P): the proportional component of the PID controller. It steers the car along to road center. The larger the corresponding coefficient (parameter of the PID controller) the steeper steering angles. Setting only P control is agressive and has oscillations.

Integral (I): the integral component of the PID controller. It is responsible for compensating the bias that the car's steering wheel might have. If there is bias in system, the integral accumulates and cancels the bias. When this component is used alone, the car leaves the road and starts the circular motion.

Derivative (D): the differential component of the PID controller. It is responsible for smoothing the car's oscillations around the reference line.When this component used alone, the car is irresponsive to the road steepness and reacts only to little changes in the steepness.



## Describe how the final hyperparameters were chosen.

First I set throttle to be fixed and tune the steering parameters. I started with (0.1,0.03,2.0) and applied twiddle algorithm. In each run, one parameter was changed by adding the dp value for the parameter. At the end of the run, if the car was able to complete the track, in other words, able to drive for the given size of steps, the mean cte error value and the mean steering value were compared with the lowest error and steering values. If they are both less than the previous best values, the parameters were selected as new best parameters. 

The twiddle algorithm has run for several times. After each run, the best parameters were set to start with a new run. In addition, it was required to decrease the Kp values to find better parameters. All values are printed in terminal to be easily picked.

My final parameters for steering are (0.13, 0.0001, 1.0), and for throttle are (0.1, 0.002, 1.0).