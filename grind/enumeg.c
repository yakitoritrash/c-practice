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
