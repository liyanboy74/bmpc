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

uint16_t bmpc_convert_color_to16(color24_s color)
{
    uint16_t cc=0;

	cc|=(((int)round((color.b*(float)0.1215686)))&0x1f)<<0 ;//B5
	cc|=(((int)round((color.g*(float)0.2470588)))&0x3f)<<5 ;//G6
	cc|=(((int)round((color.r*(float)0.1215686)))&0x1f)<<11;//R5

	return cc;
}

color24_s bmpc_convert_color_to24(uint16_t color)
{
    color24_s Ret;

    Ret.b=(color>>00)&0x1f;
    Ret.g=(color>>05)&0x3f;
    Ret.r=(color>>11)&0x1f;

    Ret.b=(int)round(8.2258*Ret.b);
    Ret.g=(int)round(4.0476*Ret.g);
    Ret.r=(int)round(8.2258*Ret.r);

	return Ret;
}

uint16_t bmpc_convert_color(uint8_t r,uint8_t g,uint8_t b)
{
    uint16_t cc=0;

	cc|=(((int)round((b*(float)0.1215686)))&0x1f)<<0 ;//B5
	cc|=(((int)round((g*(float)0.2470588)))&0x3f)<<5 ;//G6
	cc|=(((int)round((r*(float)0.1215686)))&0x1f)<<11;//R5

	return cc;
}

void bmpc_set_brightness(bmpc_screen_s *obj,uint8_t new_brightness)
{
    int i,j;
    float k;
    uint8_t old_brightness;
    color24_s c;
    uint16_t width;

    if(new_brightness>100)new_brightness=100;

    old_brightness=obj->brightness;
    k=new_brightness/(float)old_brightness;
    obj->brightness=new_brightness;

    for(i=0;i<obj->height;i++)
    {
        for(j=0;j<obj->width;j++)
        {
            c=bmcp_read_pixel_24(obj,j,i);
            c.b*=k;
            c.g*=k;
            c.r*=k;
            bmpc_draw_pixel_24(obj,j,i,c);
        }
    }

}

void bmpc_draw_pixel_24(bmpc_screen_s *obj,uint16_t x,uint16_t y,color24_s color)
{
    uint16_t width;

    if(x>=(obj->width)||y>=(obj->height))return;
    if(obj->buffer==NULL)return;

    //x=(obj->width-1)-x;
    y=(obj->height-1)-y;

    width=obj->width;

    memcpy(obj->buffer+(y*width*3)+(x*3)+0,&color.b,sizeof(uint8_t));
    memcpy(obj->buffer+(y*width*3)+(x*3)+1,&color.g,sizeof(uint8_t));
    memcpy(obj->buffer+(y*width*3)+(x*3)+2,&color.r,sizeof(uint8_t));
}

void bmpc_draw_pixel_16(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color)
{
    color24_s c24;
    c24=bmpc_convert_color_to24(color);
    bmpc_draw_pixel_24(obj,x,y,c24);
}

void bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,uint16_t color)
{
    bmpc_draw_pixel_16(obj,x,y,color);
}

color24_s bmcp_read_pixel_24(bmpc_screen_s *obj,uint16_t x,uint16_t y)
{
    color24_s c={0,0,0};
    uint16_t width;

    if(x>=(obj->width)||y>=(obj->height))return c;
    if(obj->buffer==NULL)return c;

    //x=(obj->width-1)-x;
    y=(obj->height-1)-y;

    width=obj->width;

    memcpy(&c.b,obj->buffer+(y*width*3)+(x*3)+0,sizeof(uint8_t));
    memcpy(&c.g,obj->buffer+(y*width*3)+(x*3)+1,sizeof(uint8_t));
    memcpy(&c.r,obj->buffer+(y*width*3)+(x*3)+2,sizeof(uint8_t));

    return c;
}

uint16_t bmcp_read_pixel_16(bmpc_screen_s *obj,uint16_t x,uint16_t y)
{
    color24_s c;
    c=bmcp_read_pixel_24(obj,x,y);
    return bmpc_convert_color_to16(c);
}

uint16_t bmcp_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y)
{
    return bmcp_read_pixel_16(obj,x,y);
}

void bmpc_fill_rect(bmpc_screen_s *obj,int16_t x, int16_t y, int16_t w, int16_t h,uint16_t color)
{
    int i,j;
    color24_s c;
    uint16_t width,iy;

    if(x+w>(obj->width)||y+h>(obj->height))return;
    if(obj->buffer==NULL)return;

    width=obj->width;
    iy=(obj->height-1)-y;

    c=bmpc_convert_color_to24(color);

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+0,&c.b,sizeof(uint8_t));
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+1,&c.g,sizeof(uint8_t));
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+2,&c.r,sizeof(uint8_t));
        }
    }
}

void bmpc_fill_screen(bmpc_screen_s *obj,uint16_t color)
{
    bmpc_fill_rect(obj,0,0,obj->width,obj->height,color);
}

void bmpc_clear_screen(bmpc_screen_s *obj)
{
    memset(obj->buffer,0x00,obj->height*obj->width*3);
}

uint8_t* bmpc_init(bmpc_screen_s *obj,char * name,uint16_t width,uint16_t height)
{
    obj->name=name;
    obj->width=width;
    obj->height=height;
    obj->brightness=100;
    obj->buffer=(uint8_t*)calloc(width*height*3,sizeof(uint8_t));
    memset(obj->buffer,0x00,height*width*3);
    return obj->buffer;
}

uint16_t bmpc_get_height(bmpc_screen_s *obj)
{
    return obj->height;
}

uint16_t bmpc_get_width(bmpc_screen_s *obj)
{
    return obj->width;
}

void bmpc_update(bmpc_screen_s *obj)
{
    SaveBitmap24File(obj->name,obj->width,obj->height,obj->buffer);
}

void bmpc_free(bmpc_screen_s *obj)
{
    if(obj->buffer!=NULL)free(obj->buffer);
}


