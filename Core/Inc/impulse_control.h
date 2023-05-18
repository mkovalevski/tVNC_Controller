#ifndef INC_IMPULSE_CONTROL_H_
#define INC_IMPULSE_CONTROL_H_

#include <stdint.h>

typedef enum {
	SUCCESS,
	ERROR
} PWM_STATUS;



uint8_t change_current(uint32_t current);
uint8_t change_frequency(uint32_t freq);
uint8_t change_pulse_duration(uint32_t duration, uint32_t on_s, uint32_t off_s);

#endif /* INC_IMPULSE_CONTROL_H_ */
