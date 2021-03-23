/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#ifndef __BMPC_H_
#define __BMPC_H_

#include <stdint.h>

#include "color.h"

typedef struct bmpc_screen_t
{
    char        *name;
    uint16_t    width;
    uint16_t    height;
    uint8_t     *buffer;
    uint8_t     brightness;
}bmpc_screen_s;

#ifdef __cplusplus
extern "C" {
#endif

uint8_t*    bmpc_init(bmpc_screen_s *obj,char * name,uint16_t width,uint16_t height);

uint16_t    bmpc_get_height(bmpc_screen_s *obj);
uint16_t    bmpc_get_width(bmpc_screen_s *obj);

void        bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,color_rgb_s color);
color_rgb_s bmpc_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y);

void        bmpc_fill_rect(bmpc_screen_s *obj,int16_t x, int16_t y, int16_t w, int16_t h,color_rgb_s color);
void        bmpc_fill_screen(bmpc_screen_s *obj,color_rgb_s color);
void        bmpc_clear_screen(bmpc_screen_s *obj);

void        bmpc_set_brightness(bmpc_screen_s *obj,uint8_t new_brightness);

void        bmpc_update(bmpc_screen_s *obj);
void        bmpc_free(bmpc_screen_s *obj);

#ifdef __cplusplus
}
#endif

#endif//__BMPC_H_
