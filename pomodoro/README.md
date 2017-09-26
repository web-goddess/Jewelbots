# Jewelbots Pomodoro Timer

This is a simple sketch to turn your Jewelbot into a [Pomodoro timer](https://en.wikipedia.org/wiki/Pomodoro_Technique)!

## How it works

After loading the sketch, unplug your Jewelbot and press the Magic Button to start the cycle.

1. TASK (25min) - extra short buzz and green lights
2. BREAK (5min) - short buzz and red lights
3. TASK (25min) - extra short buzz and green lights
4. BREAK (5min) - short buzz and red lights
5. TASK (25min) - extra short buzz and green lights
6. BREAK (5min) - short buzz and red lights
7. TASK (25min) - extra short buzz and green lights
8. LONG BREAK (15min) - long buzz and blue lights

Then it starts over again!

If you forget which step of the cycle you're in, you can do a short button press at any time and the lights will blink the appropriate colour to indicate.

If you'd like to stop the cycle entirely, just do a long press. You'll see a rainbow animation to indicate the timer has been reset. To start it again, do a short press and it will begin again from the first task.

## Configuration

In the sketch you can configure:

* length of tasks, breaks, and long breaks
* number of tasks before a long break
* colour of lights for each state

## Testing

If you'd like to test it out without waiting 25 minutes, just comment out the variables for the state length and uncomment the ones marked testing. That will change task length to 30 seconds, break to 15 seconds, and long break to one minute.

## Debugging

You can use USB serial output to debug by uncommenting this line: `//#define DEBUG`. Plug in your Jewelbot and open the Serial Monitor. Once you load the sketch, you should see "Setup." in the monitor. (If you get gibberish, try playing with the baud settings. Mine needed to be on 38400 baud.) Press the button to start the loop. Each state should update in the serial monitor as the cycle progresses.

Note: You can't do the long press to reset the loop while charging. This is because the long button press is reserved to put your Jewelbot into Upload Mode while plugged in.

## License

This project is licensed under the terms of the MIT license.

## Thanks

This project was inspired by [dvberkel](https://github.com/dvberkel/jewelbot-sketches/tree/master/pomodore)'s [Pomodore timer](http://community.jewelbots.com/t/turning-a-jewelbot-into-a-pomodore-timer/306) as well as tacochada's [similar project](http://community.jewelbots.com/t/pomodore-timer/532).
