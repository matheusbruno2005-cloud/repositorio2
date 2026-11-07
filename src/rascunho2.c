#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/vector.h>
#include <stdio.h>
#include <unistd.h>
#include "led_rgb.h"

volatile uint64_t ticks = 0;

void sys_tick_handler(void)
{

    ticks++;
}

int main(void)
{

    rcc_clock_setup_pll(&rcc_hse_configs[RCC_CLOCK_HSE8_72MHZ]);
    setup_leds();
    setup_pinos();

    systick_set_frequency(1000, rcc_ahb_frequency);
    systick_counter_enable();
    systick_interrupt_enable();

    usart_set_baudrate(USART2, 9600);
    usart_set_databits(USART2, 8);
    usart_set_stopbits(USART2, USART_STOPBITS_1);
    usart_set_mode(USART2, USART_MODE_TX_RX);
    usart_set_parity(USART2, USART_PARITY_NONE);
    usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);
    usart_enable(USART2);

    unsigned int now = 0;

    unsigned int start = ticks;
    while (1)
    {
        now = ticks;
        if ((ticks - start) > 1000 && (ticks - start) < 2000)
        {
            usart_send_blocking(USART2, 'R');
            char buffer = usart_recv_blocking(USART2);
            if(buffer == 'R')
            {
                ascender_vermelho();
            }
            start = ticks;

        }
    }
}