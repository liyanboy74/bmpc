# BMPC - Simulate BMP as TFT LCD 

It is recommended to use [ImageGlass](https://imageglass.org/) for open `.pmp` file.

#### Example:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bmpc.h"
bmpc_screen_s Screen1;
int main(int argc, char** argv)
{
    bmpc_init(&Screen1,"Screen1",500,500);
    bmpc_fill_screen(&Screen1,bmpc_convert_color(0,0xff,0xff));
    bmpc_fill_rect(&Screen1,100,100,300,300,bmpc_convert_color(0x00,0x00,0xff));
    bmpc_update(&Screen1);
}
```
#### Higher layer 

You can use [Dispcolor](https://github.com/liyanboy74/dispcolor) for more functions. 
