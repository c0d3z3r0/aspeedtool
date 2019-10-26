/*
 * aspeedtool - dump all registers on an Aspeed SoC based systemd
 *
 * Original work:
 * Copyright (C) 2008-2010 by coresystems GmbH
 * written by Stefan Reinauer <stepan@coresystems.de>
 * Copyright (C) 2009 Carl-Daniel Hailfinger
 * Copyright (C) 2017 secunet Security Networks AG
 *
 * Derived work:
 * Copyright (C) 2019 Michael Niewöhner <foss@mniewoehner.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>

#include "aspeedtool.h"
#include "registers.h"

static int fd_mem;

void *map_physical(uint64_t phys_addr, size_t len)
{
	void *virt_addr;

	if ((fd_mem = open("/dev/mem", O_RDWR)) < 0) {
		perror("Can not open /dev/mem");
		exit(1);
	}

 	virt_addr = mmap(0, len, PROT_WRITE | PROT_READ, MAP_SHARED,
		fd_mem, (off_t) phys_addr);

	if (virt_addr == MAP_FAILED) {
		printf("Error mapping physical memory 0x%08" PRIx64 "[0x%zx], error %i\n",
			phys_addr, len, errno);
		return NULL;
	}

 	return virt_addr;
}

void unmap_physical(void *virt_addr, size_t len)
{
	munmap(virt_addr, len);
}

int main() {
	void *mmio;
	size_t i, o;
	const subsystem_t const* subsystem;

	for (i = 0; i < ARRAY_SIZE(ast2400_subsystems); i++) {
		subsystem = &ast2400_subsystems[i];
		printf("\n---------- %s (0x%08X) ----------\n\n", subsystem->name, subsystem->addr);

		mmio = map_physical(subsystem->addr, 0x1000);
		if (mmio == NULL)
			continue;

		for (o = 0; o <= subsystem->max; o+=4)
			printf("0x%04X: 0x%08x\n", o, MMIO(o));

		unmap_physical(mmio, 0x1000);
	}

	return 0;
}
