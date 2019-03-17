#ifndef LED_H
#define LED_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
    char r;
    char g;
    char b;
    
    char pin_r;
    char pin_g;
    char pin_b;
} led_t;

void led_Setup(void *p_context, char pin_r, char pin_g, char pin_b);
void led_SetColor(void *p_context, char r, char g, char b);
void led_Poll(void *p_context);

#ifdef __cplusplus
}
#endif

#endif
