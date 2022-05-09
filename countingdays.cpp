#include "countingdays.h"

int days = 1;
int h = 0;
int m = 0;

void lookAtClock(int hours, int minutes) {
  if(hours < h) {
    days +=1;
  } else if(hours == h) {
    if(minutes < m) {
      days += 1;
    }
  }
  m = minutes;
  h = hours;

}

int getDay() {
    return days;
}
