/*
 * C startup for STM32F103xB - replacement for assembly startup file.
 * This file defines the vector table and Reset handler in C.
 */

#include <stdint.h>

/* Linker script symbols (provided by the linker script) */
extern uint32_t _estack;
extern uint32_t _sidata; /* start of init values in flash */
extern uint32_t _sdata;  /* start of .data in RAM */
extern uint32_t _edata;  /* end of .data in RAM */
extern uint32_t _sbss;   /* start of .bss in RAM */
extern uint32_t _ebss;   /* end of .bss in RAM */

/* Forward declarations of handlers (implemented below or weakly aliased) */
void Reset_Handler(void);
void Default_Handler(void);

/* Cortex-M core handlers */
void NMI_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)           __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)       __attribute__((weak, alias("Default_Handler")));

/* Peripheral IRQ handlers (weak aliases to Default_Handler) */
void WWDG_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void TAMPER_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USB_HP_CAN1_TX_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void USB_LP_CAN1_RX0_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)              __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));

/* External functions provided elsewhere */
extern void SystemInit(void);
extern void __libc_init_array(void);
int main(void);

/* Vector table placed in .isr_vector section */
__attribute__((used, section(".isr_vector")))
const uint32_t g_pfnVectors[] = {
    (uint32_t)&_estack,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    0,
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,

    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)TAMPER_IRQHandler,
    (uint32_t)RTC_IRQHandler,
    (uint32_t)FLASH_IRQHandler,
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)ADC1_2_IRQHandler,
    (uint32_t)USB_HP_CAN1_TX_IRQHandler,
    (uint32_t)USB_LP_CAN1_RX0_IRQHandler,
    (uint32_t)CAN1_RX1_IRQHandler,
    (uint32_t)CAN1_SCE_IRQHandler,
    (uint32_t)EXTI9_5_IRQHandler,
    (uint32_t)TIM1_BRK_IRQHandler,
    (uint32_t)TIM1_UP_IRQHandler,
    (uint32_t)TIM1_TRG_COM_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTI15_10_IRQHandler,
    (uint32_t)RTC_Alarm_IRQHandler,
    (uint32_t)USBWakeUp_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)0xF108F85F  /* BootRAM signature as in original startup */
};

/* Default handler: infinite loop */
void Default_Handler(void)
{
    while (1) {
        __asm volatile ("bkpt #0");
    }
}

/* Reset handler: initializes system and runtime, then calls main() */
void Reset_Handler(void)
{
    /* Call SystemInit - keep this before data init to match original behavior */
    SystemInit();

    /* Copy .data from flash (_sidata) to SRAM (_sdata.._edata) */
    uint32_t *src = &_sidata;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero fill .bss (_sbss.._ebss) */
    uint32_t *b = &_sbss;
    while (b < &_ebss) {
        *b++ = 0U;
    }

    /* Call constructors */
    __libc_init_array();

    /* Call application's entry point. Do not return. */
    (void)main();

    /* If main returns, loop forever */
    while (1) {
    }
}
