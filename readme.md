# BMPC - Simulate BMP as TFT LCD 

In microcontroller programming, if you've worked with LCDs, you know that the code you write is usually not what you see on an LCD. **BMPC** can simulate all LCDs, so you can see everything you program for LCDs without wasting time on repeated compile and program.

![compas](https://user-images.githubusercontent.com/64005694/111913422-451fe880-8a83-11eb-96a2-ffc1e51f10a5.gif) &nbsp; &nbsp; &nbsp; &nbsp; ![clock](https://user-images.githubusercontent.com/64005694/111913407-376a6300-8a83-11eb-841d-3c30eb592a6e.gif)

**BMPC** Written in C by standard libraries.
This library simply saves frames in BMP-24 windows format with any dimensions. For more flexibility, the execution of files is entrusted to other software. 

It is recommended to use [ImageGlass](https://imageglass.org/) for open `.bmp` file.
### Clone
	git clone --recursive https://github.com/liyanboy74/bmpc.git

### Example:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "bmpc.h"

bmpc_screen_s Screen;

int main(int argc, char** argv)
{
    bmpc_init(&Screen,"Screen",500,500);

    bmpc_fill_screen(&Screen,color_s(0,255,0));
    bmpc_fill_rect(&Screen,100,100,300,300,color_s(0,0,255));
    bmpc_set_brightness(&Screen,80);

    bmpc_update(&Screen);
}
```
### Higher layer 

You can use [Dispcolor](https://github.com/liyanboy74/dispcolor) for more functions. 

