
#include "HardwareTimerLL.h"

#include CHIP_PERIPHERAL_INCLUDE

#ifdef TIM2  
	HardwareTimerLL* interruptTimer2;
#endif


static void handleInterrupt(HardwareTimerLL *timer);

HardwareTimerLL::HardwareTimerLL(TIM_TypeDef *instance) 
	:timer(instance)
{
}

void HardwareTimerLL::pause() {
    LL_TIM_DisableCounter(timer);
}

void HardwareTimerLL::resume(void) {
	bool hasInterrupt = false;	  
	if (callbacks[0] != NULL) {		
		hasInterrupt = true;	
	}

#ifdef TIM2
	if (timer == TIM2)
	{
		LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2); 
		interruptTimer2 = this;
		if (hasInterrupt) {
			NVIC_SetPriority(TIM2_IRQn, 0);
			NVIC_EnableIRQ(TIM2_IRQn);
		}
	}
#endif
	/* Set counter mode */
	/* Reset value is LL_TIM_COUNTERMODE_UP */
	LL_TIM_SetCounterMode(timer, LL_TIM_COUNTERMODE_UP);
	/* Set the pre-scaler value to have TIM2 counter clock equal to 10 kHz      */
	/*
		In this example TIM2 input clock (TIM2CLK)  is set to APB1 clock (PCLK1),
		since APB1 prescaler is equal to 1.
			  TIM2CLK = PCLK1
			  PCLK1 = HCLK
			  => TIM2CLK = HCLK = SystemCoreClock
		To get TIM2 counter clock at 10 KHz, the Prescaler is computed as following:
		Prescaler = (TIM2CLK / TIM2 counter clock) - 1
		Prescaler = (SystemCoreClock /10 KHz) - 1
	*/
  	LL_TIM_SetPrescaler(timer, __LL_TIM_CALC_PSC(SystemCoreClock, 10000));
  
  	/* Set the auto-reload value to have an initial update event frequency of 10 Hz */
    /* TIM2CLK = SystemCoreClock / (APB prescaler & multiplier)                 */
  	uint32_t TimOutClock = SystemCoreClock / 2;
  
  	uint32_t InitialAutoreload = __LL_TIM_CALC_ARR(TimOutClock, LL_TIM_GetPrescaler(timer), 10);
  	LL_TIM_SetAutoReload(timer, InitialAutoreload);

  	if (callbacks[0] != NULL) {        
  		LL_TIM_EnableIT_UPDATE(timer);   
  	} 

	/* Enable counter */
  	LL_TIM_EnableCounter(timer);
  
  	/* Force update generation */
  	LL_TIM_GenerateEvent_UPDATE(timer);

}

uint32_t HardwareTimerLL::getPrescaleFactor() {    
	return LL_TIM_GetPrescaler(timer);
}

void HardwareTimerLL::setPrescaleFactor(uint32_t prescaler) {    
	LL_TIM_SetPrescaler(timer, prescaler);
}

void HardwareTimerLL::setTimerFrequency(uint32_t freq)
{
	LL_TIM_SetPrescaler(timer, __LL_TIM_CALC_PSC(SystemCoreClock, freq));
}


uint32_t HardwareTimerLL::getOverflow() {    
	return LL_TIM_GetAutoReload(timer);
}

void HardwareTimerLL::setOverflow(uint32_t overflow) {    
	LL_TIM_SetAutoReload(timer, overflow);
}

void HardwareTimerLL::setPeriodFrequency(uint32_t freq)
{
	LL_TIM_SetAutoReload(timer, __LL_TIM_CALC_ARR(SystemCoreClock, LL_TIM_GetPrescaler(timer), freq));	
}


uint32_t HardwareTimerLL::setPeriod(uint32_t microseconds) { 
	if (!microseconds) {
		this->setPrescaleFactor(1);
		this->setOverflow(1);       
		return this->getOverflow();
	}
    // 这种做法不精准，因为存在忽略的小数，
    // 若要精准，应使prescaler的值被 SystemCoreClock整除，
    // 如1,2,4,6,8, 9,12,18,36,72.......
	uint32_t period_cyc = microseconds * (SystemCoreClock  / 1000000); //TODO!    
	uint32_t prescaler = (uint32_t)(period_cyc / MAX_RELOAD + 1);    
	uint32_t overflow = (uint32_t)(period_cyc / prescaler);
		
	this->setPrescaleFactor(prescaler);    
	this->setOverflow(overflow);    
	return overflow;
}


uint32_t HardwareTimerLL::getCount(void)
{
	return LL_TIM_GetCounter(timer);	
}

void HardwareTimerLL::setCount(uint32_t val)
{
	LL_TIM_SetCounter(timer, val);	
}

uint32_t HardwareTimerLL::getBaseFrequency()
{
	LL_RCC_ClocksTypeDef *clocks = new LL_RCC_ClocksTypeDef;
	LL_RCC_GetSystemClocksFreq(clocks);
	uint32_t baseFreq = 2 * clocks->PCLK1_Frequency;
	delete clocks;

	return baseFreq;
}


static void handleInterrupt(HardwareTimerLL *timer) {    
	if(LL_TIM_IsActiveFlag_UPDATE(timer->timer) == SET) 
	{        
		LL_TIM_ClearFlag_UPDATE(timer->timer);        
		if (timer->callbacks[0] != NULL) 
			timer->callbacks[0]();    
	}
}

#ifdef TIM2
	HardwareTimerLL TimerLL2(TIM2);
	extern "C" void TIM2_IRQHandler(void)
	{
		if (interruptTimer2 != NULL) 
			handleInterrupt(interruptTimer2);
	}
#endif


