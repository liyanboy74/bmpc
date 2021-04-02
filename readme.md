# BMPC - Simulate BMP as TFT LCD 

In microcontroller programming, if you've worked with LCDs, you know that the code you write is usually not what you see on an LCD. **BMPC** can simulate all LCDs, so you can see everything you program for LCDs without wasting time on repeated compile and program.

![compas](https://user-images.githubusercontent.com/64005694/111913422-451fe880-8a83-11eb-96a2-ffc1e51f10a5.gif) &nbsp; &nbsp; &nbsp; &nbsp; ![clock](https://user-images.githubusercontent.com/64005694/111913407-376a6300-8a83-11eb-841d-3c30eb592a6e.gif)

**BMPC** Written in C by standard libraries.
This library simply saves frames in BMP-24 windows format with any dimensions. For more flexibility, the execution of files is entrusted to other software. 

It is recommended to use [ImageGlass](https://imageglass.org/) for open `.bmp` file.
### Clone
	git clone --recursive https://github.com/liyanboy74/bmpc.git

### Example
- [one-frame](./examples/one-frame.c)
- [multi-frame](./examples/multi-frame.c)
- [animated](./examples/animated.c)

### Compile & Run
	gcc examples/example.c bmpc.c bmp/bmp.c color/color.c -I. -Ibmp -Icolor -orun -lm
	./run

### Higher layer 

You can use [Dispcolor](https://github.com/liyanboy74/dispcolor) for more functions. 

