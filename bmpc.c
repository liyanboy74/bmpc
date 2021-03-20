/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "bmp.h"
#include "bmpc.h"

static void swap_bytes(uint16_t *color) {
    uint8_t temp = *color >> 8;
    *color = (*color << 8) | temp;
}

uint16_t convert_color_to16(color_s color)
{
    uint16_t cc=0;

	cc|=(((int)round((color.b*(float)0.1215686)))&0x1f)<<0 ;//B5
	cc|=(((int)round((color.g*(float)0.2470588)))&0x3f)<<5 ;//G6
	cc|=(((int)round((color.r*(float)0.1215686)))&0x1f)<<11;//R5

	return cc;
}

color_s convert_color_to24(uint16_t color)
{
    color_s Ret;

    Ret.b=(color>>00)&0x1f;
    Ret.g=(color>>05)&0x3f;
    Ret.r=(color>>11)&0x1f;

    Ret.b=(int)round(8.2258*Ret.b);
    Ret.g=(int)round(4.0476*Ret.g);
    Ret.r=(int)round(8.2258*Ret.r);

	return Ret;
}

void bmpc_set_brightness(bmpc_screen_s *obj,uint8_t value)
{
}

void bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color)
{
    color_s c;
    uint16_t width;

    if(x>=(obj->width)||y>=(obj->hight))return;
    if(obj->buffer==NULL)return;

    //x=(obj->width-1)-x;
    y=(obj->hight-1)-y;

    c=convert_color_to24(color);
    width=obj->width;

    memcpy(obj->buffer+(y*width*3)+(x*3)+0,&c.b,sizeof(uint8_t));
    memcpy(obj->buffer+(y*width*3)+(x*3)+1,&c.g,sizeof(uint8_t));
    memcpy(obj->buffer+(y*width*3)+(x*3)+2,&c.r,sizeof(uint8_t));
}

uint16_t bmcp_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y)
{
    color_s c;
    uint16_t width;

    if(x>=(obj->width)||y>=(obj->hight))return 0;
    if(obj->buffer==NULL)return 0;

    //x=(obj->width-1)-x;
    y=(obj->hight-1)-y;

    width=obj->width;

    memcpy(&c.b,obj->buffer+(y*width*3)+(x*3)+0,sizeof(uint8_t));
    memcpy(&c.g,obj->buffer+(y*width*3)+(x*3)+1,sizeof(uint8_t));
    memcpy(&c.r,obj->buffer+(y*width*3)+(x*3)+2,sizeof(uint8_t));

    return convert_color_to16(c);
}

uint8_t* bmpc_init(bmpc_screen_s *obj,char * name,uint16_t width,uint16_t hight)
{
    obj->name=name;
    obj->width=width;
    obj->hight=hight;
    obj->buffer=(uint8_t*)calloc(width*hight*3,sizeof(uint8_t));
    memset(obj->buffer,0x00,hight*width*3);
    return obj->buffer;
}

void bmpc_update(bmpc_screen_s *obj)
{
    SaveBitmap24File(obj->name,obj->width,obj->hight,obj->buffer);
}

void bmpc_free(bmpc_screen_s *obj)
{
    if(obj->buffer!=NULL)free(obj->buffer);
}


