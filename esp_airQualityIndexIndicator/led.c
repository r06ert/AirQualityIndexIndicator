#include "led.h"

/*
 * @brief Setup LEDs pins as output, configure struct.
 * 
 * @param  *p_context Pointer of struct.
 * @param  pin_r Pin R LED.
 * @param  pin_g Pin G LED.
 * @param  pin_b Pin B LED.
 * @return none
 */
void led_Setup(void *p_context, char pin_r, char pin_g, char pin_b) {

  led_t * p_led = p_context;

  //set structure
  p_led->pin_r = pin_r;
  p_led->pin_g = pin_g;
  p_led->pin_b = pin_b;
  
  // set pin to outputs
  pinMode(p_led->pin_r, 1);
  pinMode(p_led->pin_g, 1);
  pinMode(p_led->pin_b, 1);
  
  // turn off LEDs
  analogWrite(p_led->pin_r, 0);       
  analogWrite(p_led->pin_g, 0);       
  analogWrite(p_led->pin_b, 0);       
}

/*
 * @brief Setup LEDs pins as output, configure struct.
 * 
 * @param  *p_context Pointer of struct.
 * @param  r R LED value.
 * @param  g G LED value.
 * @param  b B LED value.
 * @return none
 */
void led_SetColor(void *p_context, char r, char g, char b) {

  led_t * p_led = p_context;
  
  p_led->r = r;
  p_led->g = g;
  p_led->b = b;
}

/*
 * @brief Setup LEDs pins as output, configure struct.
 * 
 * @param  *p_context Pointer of struct.
 * @return none
 */
void led_Poll(void *p_context) {

  led_t * p_led = p_context;
  
  analogWrite(p_led->pin_r, p_led->r);
  analogWrite(p_led->pin_g, p_led->g);
  analogWrite(p_led->pin_b, p_led->b);
}
