#ifndef HARDWARETIMERLL_H_
#define HARDWARETIMERLL_H_

#include <Arduino.h>
#include "stm32_gpio_af.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_rcc.h"


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

#define MAX_RELOAD ((1 << 16) - 1) // Not always! 32 bit timers!

class HardwareTimerLL {
public:
    HardwareTimerLL(TIM_TypeDef *instance);

    void pause(void);

    void resume(void);

	uint32_t getPrescaleFactor();
	void setPrescaleFactor(uint32_t factor);
	void setTimerFrequency(uint32_t freq);
	
	uint32_t getOverflow();    
	void setOverflow(uint32_t val); 
	void setPeriodFrequency(uint32_t freq);
	
	uint32_t getCount(void);
	void setCount(uint32_t val);

	uint32_t setPeriod(uint32_t microseconds);

    //Add interrupt to period update
    void attachInterrupt(void (*handler)(void)) {
    	callbacks[0] = handler;
    }

    void detachInterrupt() {
		callbacks[0] = 0;
    }
    
	uint32_t getBaseFrequency();

	TIM_TypeDef *timer;
	
    //Callbacks: 0 for update, 1-4 for channels
    void (*callbacks[1])(void);

};

#pragma GCC diagnostic pop

#ifdef TIM2    
	extern HardwareTimerLL TimerLL2;
#endif


#endif //HARDWARETIMERLL_H_

