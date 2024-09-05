# BMPC - Simulate BMP as TFT LCD

**Discontinued: It is recommended to use [SIMLCD](https://github.com/liyanboy74/simlcd) instead of BMPC !** <br>
⚠️ *BMPC maybe damage your hard drive!*

<hr>

This library simply saves frames in BMP-24 windows format with any dimensions. For more flexibility, the execution of files is entrusted to other software.

### Clone
	git clone --recursive https://github.com/liyanboy74/bmpc.git

### Example
- [one-frame](./examples/one-frame.c)
- [multi-frame](./examples/multi-frame.c)
- [animated](./examples/animated.c)
- [test-dispcolor](./examples/test-dispcolor.c)

### Compile
	cd bmpc
	mkdir build && cd build
	cmake ..
	make
