#include "led_rgb.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

void setup_leds(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, _LED_RED_);
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, _LED_GREEN_);
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, _LED_BLUE_);

    gpio_set(GPIOA, _LED_RED_);
    gpio_set(GPIOA, _LED_GREEN_);
    gpio_set(GPIOA, _LED_BLUE_);
}

void setup_pinos(void)
{
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_USART2);
    rcc_periph_clock_enable(RCC_AFIO);

    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO2);
    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT, GPIO3);
}

void ascender_verde(void)
{
    gpio_set(GPIOA, _LED_RED_);
    gpio_clear(GPIOA, _LED_GREEN_);
    gpio_set(GPIOA, _LED_BLUE_);
}

void ascender_azul(void)
{
    gpio_set(GPIOA, _LED_RED_);
    gpio_set(GPIOA, _LED_GREEN_);
    gpio_clear(GPIOA, _LED_BLUE_);
}

void ascender_vermelho(void)
{
    gpio_clear(GPIOA, _LED_RED_);
    gpio_set(GPIOA, _LED_GREEN_);
    gpio_set(GPIOA, _LED_BLUE_);
}

void ascender_amarelo(void)
{
    gpio_clear(GPIOA, _LED_RED_);
    gpio_clear(GPIOA, _LED_GREEN_);
    gpio_set(GPIOA, _LED_BLUE_);
}

void ascender_ciano(void)
{
    gpio_set(GPIOA, _LED_RED_);
    gpio_clear(GPIOA, _LED_GREEN_);
    gpio_clear(GPIOA, _LED_BLUE_);
}

void ascender_roxo(void)
{
    gpio_clear(GPIOA, _LED_RED_);
    gpio_set(GPIOA, _LED_GREEN_);
    gpio_clear(GPIOA, _LED_BLUE_);
}

void ascender_branco(void)
{
    gpio_clear(GPIOA, _LED_RED_);
    gpio_clear(GPIOA, _LED_GREEN_);
    gpio_clear(GPIOA, _LED_BLUE_);
}

void apagar_led(void)
{
    gpio_set(GPIOA, _LED_RED_);
    gpio_set(GPIOA, _LED_GREEN_);
    gpio_set(GPIOA, _LED_BLUE_);
}