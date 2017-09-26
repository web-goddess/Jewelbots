// set up some variables
const unsigned int REST = 1;
const unsigned int TASK = 2;
const unsigned int BREAK = 3;
const unsigned int LONG_BREAK = 4;

// timing values
const unsigned long MINUTES = 60;
const unsigned long TASK_TIME = 25 * MINUTES;
const unsigned long BREAK_TIME = 5 * MINUTES;
const unsigned long LONG_BREAK_TIME = 15 * MINUTES;
const unsigned int  TASKS_BEFORE_LONG_BREAK = 4;

// testing values
//const unsigned long TASK_TIME = 30;
//const unsigned long BREAK_TIME = 15;
//const unsigned long LONG_BREAK_TIME = 60;

const ColorLabel BREAK_COLOR = RED;
const ColorLabel LONG_BREAK_COLOR = BLUE;
const ColorLabel START_COLOR = GREEN;

unsigned int state;
unsigned int completed_tasks;

LED led;
Timer timer;
Buzzer buzzer;
Animation animation;

void setup() {
  // Used for testing
  //JWB_SERIAL("Setup.\n");
  //set_run_loop_charging();
  
  reset();
  
}

void loop() {
  // start pomodoro function
  pomodoro();
}

void pomodoro(void) {
  switch (state) {
    case REST:
    handle_rest();
    break;

    case TASK:
    handle_task();
    break;

    case BREAK:
    handle_break();
    break;

    case LONG_BREAK:
    handle_long_break();
    break;
  }
}

void handle_rest(void) {
  // Wait for a button press
}

void handle_task(void) {
  //JWB_SERIAL("Task start.\n");
  led.turn_on_all(START_COLOR);
  buzzer.extra_short_buzz();
  for (int i = 0; i < TASK_TIME && state == TASK; i++) {
    timer.pause(1000);
    led.turn_off_all();
  }
  //handle potential reset interrupts
  if (state == TASK) {
    completed_tasks += 1;
    //JWB_SERIAL_PRINTF("Completed tasks = %u\n", completed_tasks);
    if (completed_tasks == TASKS_BEFORE_LONG_BREAK) {
      state = LONG_BREAK;
    } else {
        state = BREAK;
    }
  }
}

void handle_break(void) {
  //JWB_SERIAL("Short break.\n");
  led.turn_on_all(BREAK_COLOR);
  buzzer.short_buzz();
  for (int i = 0; i < BREAK_TIME && state == BREAK; i++) {
    timer.pause(1000);
    led.turn_off_all();
  }
  //handle potential reset interrupts
  if (state == BREAK) {
    state = TASK;
  }
}

void handle_long_break(void) {
  //JWB_SERIAL("Long break.\n");
  led.turn_on_all(LONG_BREAK_COLOR);
  buzzer.long_buzz();
  completed_tasks = 0;
  for (int i = 0; i < LONG_BREAK_TIME && state == LONG_BREAK; i++) {
    timer.pause(1000);
    led.turn_off_all();
  }
  //handle potential reset interrupts
  if (state == LONG_BREAK) {
    state = TASK;
    //JWB_SERIAL("Tasks start over!\n");
  }
}

void button_press(void) {
  //JWB_SERIAL("Button press.\n");
  switch (state) {
    case REST:
    state = TASK;
    break;

    case TASK:
    led.turn_on_all(START_COLOR);
    break;

    case BREAK:
    led.turn_on_all(BREAK_COLOR);
    break;

    case LONG_BREAK:
    led.turn_on_all(LONG_BREAK_COLOR);
    break;
  }
}

void charging_button_press(void) {
  button_press();
}

void button_press_long(void) {
  reset();
  animation.rainbows();
}

void reset(void) {
  state = REST;
  completed_tasks = 0;
}
