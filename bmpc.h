/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#ifndef __BMPC_H_
#define __BMPC_H_

typedef struct{
    uint8_t b,g,r;
}color_s;

typedef struct bmpc_screen_t
{
    uint8_t     *name;
    uint16_t    width;
    uint16_t    hight;
    uint8_t     *buffer;
}bmpc_screen_s;

uint16_t    convert_color_to16(color_s color);
color_s     convert_color_to24(uint16_t color);

uint8_t*    bmpc_init(bmpc_screen_s *obj,char * name,uint16_t width,uint16_t hight);
void        bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color);
uint16_t    bmcp_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y);

void        bmpc_update(bmpc_screen_s *obj);
void        bmpc_free(bmpc_screen_s *obj);

#endif//__BMPC_H_