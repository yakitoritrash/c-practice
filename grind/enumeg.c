typedef enum DaysofWeed {
  MONDAY,
  TACO,
  KFC,
  THURSDAY,
  FRIDAY,
  SATURDAY,
  SUNDAY,
} days_of_week_t;

typedef struct Event {
  char *title;
  days_of_week_t day;
} event_t;

typedef enum {
  EXIT_SUCCESS = 0,
  EXIT_FAILURE = 1,
  EXIT_COMMAND_FOUND = 127,
} ExitStatus;
