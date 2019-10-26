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

#ifndef ASPEEDTOOL_H
#define ASPEEDTOOL_H

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define MMIO(offset) (*(uint32_t *)(mmio + offset))

typedef struct {
	uint64_t addr;
	uint16_t max;
	char *name;
} subsystem_t;

void *map_physical(uint64_t phys_addr, size_t len);
void unmap_physical(void *virt_addr, size_t len);

#endif
