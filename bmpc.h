/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#ifndef __BMPC_H_
#define __BMPC_H_

typedef struct{
    uint8_t b,g,r;
}color24_s;

typedef struct bmpc_screen_t
{
    uint8_t     *name;
    uint16_t    width;
    uint16_t    height;
    uint8_t     *buffer;
    uint8_t     brightness;
}bmpc_screen_s;

uint16_t    bmpc_convert_color(uint8_t r,uint8_t g,uint8_t b);
uint16_t    bmpc_convert_color_to16(color24_s color);
color24_s   bmpc_convert_color_to24(uint16_t color);

uint8_t*    bmpc_init(bmpc_screen_s *obj,char * name,uint16_t width,uint16_t height);

uint16_t    bmpc_get_height(bmpc_screen_s *obj);
uint16_t    bmpc_get_width(bmpc_screen_s *obj);

void        bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color);
void        bmpc_draw_pixel_24(bmpc_screen_s *obj,uint16_t x,uint16_t y,color24_s color);
void        bmpc_draw_pixel_16(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color);

uint16_t    bmcp_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y);
uint16_t    bmcp_read_pixel_16(bmpc_screen_s *obj,uint16_t x,uint16_t y);
color24_s   bmcp_read_pixel_24(bmpc_screen_s *obj,uint16_t x,uint16_t y);

void        bmpc_fill_rect(bmpc_screen_s *obj,int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color);
void        bmpc_fill_screen(bmpc_screen_s *obj,uint16_t color);
void        bmpc_clear_screen(bmpc_screen_s *obj);

void        bmpc_set_brightness(bmpc_screen_s *obj,uint8_t new_brightness);

void        bmpc_update(bmpc_screen_s *obj);
void        bmpc_free(bmpc_screen_s *obj);

#endif//__BMPC_H_