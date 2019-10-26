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

#ifndef ASPEEDTOOL_REGISTERS_H
#define ASPEEDTOOL_REGISTERS_H

const subsystem_t ast2400_subsystems[] = {
	{ 0x16000000, 0x01c, "Legacy Static Memory Controller" },
	{ 0x1E620000, 0x094, "New Static Memory Controller" },
	{ 0x1E600000, 0x08c, "AHB Bus Controller" },
	{ 0x1E630000, 0x014, "SPI Flash Controller" },
	{ 0x1E640000, 0x024, "Memory Integrity Check Controller" },
	{ 0x1E660000, 0x14c, "Fast Ethernet MAC Controller #1" },
	{ 0x1E680000, 0x14c, "Fast Ethernet MAC Controller #2" },
	{ 0x1E6A0000, 0x03f, "USB2.0 Virtual Hub Controller (Root)" },
	{ 0x1E6A0100, 0x10f, "USB2.0 Virtual Hub Controller (Dev #1)" },
	{ 0x1E6A0110, 0x11f, "USB2.0 Virtual Hub Controller (Dev #2)" },
	{ 0x1E6A0120, 0x12f, "USB2.0 Virtual Hub Controller (Dev #3)" },
	{ 0x1E6A0130, 0x13f, "USB2.0 Virtual Hub Controller (Dev #4)" },
	{ 0x1E6A0140, 0x14f, "USB2.0 Virtual Hub Controller (Dev #5)" },
	{ 0x1E6A0200, 0x20f, "USB2.0 Virtual Hub Controller (Prog. Ep. #0)" },
	{ 0x1E6A0210, 0x21f, "USB2.0 Virtual Hub Controller (Prog. Ep. #1)" },
	{ 0x1E6A0220, 0x22f, "USB2.0 Virtual Hub Controller (Prog. Ep. #2)" },
	{ 0x1E6A0230, 0x23f, "USB2.0 Virtual Hub Controller (Prog. Ep. #3)" },
	{ 0x1E6A0240, 0x24f, "USB2.0 Virtual Hub Controller (Prog. Ep. #4)" },
	{ 0x1E6A0250, 0x25f, "USB2.0 Virtual Hub Controller (Prog. Ep. #5)" },
	{ 0x1E6A0260, 0x26f, "USB2.0 Virtual Hub Controller (Prog. Ep. #6)" },
	{ 0x1E6A0270, 0x27f, "USB2.0 Virtual Hub Controller (Prog. Ep. #7)" },
	{ 0x1E6A0280, 0x28f, "USB2.0 Virtual Hub Controller (Prog. Ep. #8)" },
	{ 0x1E6A0290, 0x29f, "USB2.0 Virtual Hub Controller (Prog. Ep. #9)" },
	{ 0x1E6A02a0, 0x2af, "USB2.0 Virtual Hub Controller (Prog. Ep. #10)" },
	{ 0x1E6A02b0, 0x2bf, "USB2.0 Virtual Hub Controller (Prog. Ep. #11)" },
	{ 0x1E6A02c0, 0x2cf, "USB2.0 Virtual Hub Controller (Prog. Ep. #12)" },
	{ 0x1E6A02d0, 0x2df, "USB2.0 Virtual Hub Controller (Prog. Ep. #13)" },
	{ 0x1E6A02e0, 0x2ef, "USB2.0 Virtual Hub Controller (Prog. Ep. #14)" },
	{ 0x1E6A1000, 0x08c, "USB2.0 Host Controller" },
	{ 0x1E6B0000, 0x094, "USB1.1 Host Controller" },
	{ 0x1E6C0000, 0x0e4, "Interrupt Controller" },
	{ 0x1E6C1000, 0x03c, "Interrupt Controller" },
	{ 0x1E6C2000, 0x03c, "Interrupt Controller" },
	{ 0x1E6E0000, 0x170, "SDRAM Controller (MMC)" },
	{ 0x1E6E1000, 0x040, "USB1.1 Controller" },
	{ 0x1E6E2000, 0x1a4, "System Control Unit (SCU)" },
	{ 0x1E6E3000, 0x060, "Hash & Crypto Engine (HACE)" },
	{ 0x1E6E4000, 0x014, "JTAG Master" },
	{ 0x1E6E6000, 0x0fc, "Graphics Display Controller (CRT)" },
	{ 0x1E6E7000, 0x078, "X-DMA Controller" },
	{ 0x1E6E8000, 0x018, "MCTP Controller" },
	{ 0x1E6E9000, 0x0c0, "ADC Voltage Monitor" },
	{ 0x1E700000, 0x4fc, "Video Engine" },
	{ 0x1E740000, 0x258, "SD/SDIO Controller" },
	{ 0x1E760000, 0x1fc, "2D Engine" },
	{ 0x1E780000, 0x320, "GPIO Controller" },
	{ 0x1E781000, 0x014, "Real-Time Clock (RTC)" },
	{ 0x1E782000, 0x08c, "Timer Controller" },
	{ 0x1E783000, 0x01c, "UART - #1 (LPC UART1)" },
	{ 0x1E78D000, 0x01c, "UART - #2 (LPC UART2)" },
	{ 0x1E78E000, 0x01c, "UART - #3" },
	{ 0x1E78F000, 0x01c, "UART - #4" },
	{ 0x1E784000, 0x01c, "UART - #5 (BMC Debug)" },
	{ 0x1E787000, 0x03c, "Virtual UART (VUART)" },
	{ 0x1E788000, 0x03c, "Pass Through UART (PUART)" },
	{ 0x1E785000, 0x038, "Watchdog Timer (WDT)" },
	{ 0x1E786000, 0x078, "PWM & Fan Tacho Controller" },
	{ 0x1E789000, 0x25c, "LPC Controller" },
	{ 0x1E6EC000, 0x034, "LPC+ Controller" },
	{ 0x1E78A000, 0x008, "I2C/SMBus Controller" },
	{ 0x1E78A040, 0x020, "I2C/SMBus Device #1" },
	{ 0x1E78A080, 0x020, "I2C/SMBus Device #2" },
	{ 0x1E78A0C0, 0x020, "I2C/SMBus Device #3" },
	{ 0x1E78A100, 0x020, "I2C/SMBus Device #4" },
	{ 0x1E78A140, 0x020, "I2C/SMBus Device #5" },
	{ 0x1E78A180, 0x020, "I2C/SMBus Device #6" },
	{ 0x1E78A1c0, 0x020, "I2C/SMBus Device #7" },
	{ 0x1E78A300, 0x020, "I2C/SMBus Device #8" },
	{ 0x1E78A340, 0x020, "I2C/SMBus Device #9" },
	{ 0x1E78A380, 0x020, "I2C/SMBus Device #10" },
	{ 0x1E78A3c0, 0x020, "I2C/SMBus Device #11" },
	{ 0x1E78A400, 0x020, "I2C/SMBus Device #12" },
	{ 0x1E78A440, 0x020, "I2C/SMBus Device #13" },
	{ 0x1E78A480, 0x020, "I2C/SMBus Device #14" },
	{ 0x1E78B000, 0x05c, "PECI Controller" },
};

#endif
