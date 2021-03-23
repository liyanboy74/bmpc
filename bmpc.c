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

void bmpc_set_brightness(bmpc_screen_s *obj,uint8_t new_brightness)
{
    int i,j;
    float k;
    uint8_t old_brightness;
    color_rgb_s c;

    if(new_brightness>100)new_brightness=100;

    old_brightness=obj->brightness;
    k=new_brightness/(float)old_brightness;
    obj->brightness=new_brightness;

    for(i=0;i<obj->height;i++)
    {
        for(j=0;j<obj->width;j++)
        {
            c=bmpc_read_pixel(obj,j,i);
            c.b*=k;
            c.g*=k;
            c.r*=k;
            bmpc_draw_pixel(obj,j,i,c);
        }
    }
}

void bmpc_draw_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y,color_rgb_s color)
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

color_rgb_s bmpc_read_pixel(bmpc_screen_s *obj,uint16_t x,uint16_t y)
{
    color_rgb_s c=COLOR_NOT_SET;
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

void bmpc_fill_rect(bmpc_screen_s *obj,int16_t x, int16_t y, int16_t w, int16_t h,color_rgb_s color)
{
    int i,j;
    uint16_t width,iy;

    if(x+w>(obj->width)||y+h>(obj->height))return;
    if(obj->buffer==NULL)return;

    width=obj->width;
    iy=(obj->height-1)-y;

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+0,&color.b,sizeof(uint8_t));
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+1,&color.g,sizeof(uint8_t));
            memcpy(obj->buffer+((iy-i)*width*3)+((x+j)*3)+2,&color.r,sizeof(uint8_t));
        }
    }
}

void bmpc_fill_screen(bmpc_screen_s *obj,color_rgb_s color)
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

