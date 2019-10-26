
CC = arm-buildroot-linux-uclibcgnueabi-gcc

aspeedtool: aspeedtool.c
	$(CC) -o $@ $<
