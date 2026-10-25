
out/teste.o:	file format elf32-littlearm

Disassembly of section .strtab:

00000000 <.strtab>:
       0: 2e00         	cmp	r6, #0x0
       2: 6574         	str	r4, [r6, #0x54]
       4: 7478         	strb	r0, [r7, #0x11]
       6: 2400         	movs	r4, #0x0
       8: 0074         	lsls	r4, r6, #0x1
       a: 412e         	asrs	r6, r5
       c: 4d52         	ldr	r5, [pc, #0x148]        @ 0x158 <.strtab+0x158>
       e: 612e         	str	r6, [r5, #0x10]
      10: 7474         	strb	r4, [r6, #0x11]
      12: 6972         	ldr	r2, [r6, #0x14]
      14: 7562         	strb	r2, [r4, #0x15]
      16: 6574         	str	r4, [r6, #0x54]
      18: 0073         	lsls	r3, r6, #0x1
      1a: 722e         	strb	r6, [r5, #0x8]
      1c: 6c65         	ldr	r5, [r4, #0x44]
      1e: 412e         	asrs	r6, r5
      20: 4d52         	ldr	r5, [pc, #0x148]        @ 0x16c <.strtab+0x16c>
      22: 652e         	str	r6, [r5, #0x50]
      24: 6978         	ldr	r0, [r7, #0x14]
      26: 7864         	ldrb	r4, [r4, #0x1]
      28: 742e         	strb	r6, [r5, #0x10]
      2a: 7865         	ldrb	r5, [r4, #0x1]
      2c: 2e74         	cmp	r6, #0x74
      2e: 6f63         	ldr	r3, [r4, #0x74]
      30: 746e         	strb	r6, [r5, #0x11]
      32: 7261         	strb	r1, [r4, #0x9]
      34: 2e00         	cmp	r6, #0x0
      36: 6f6e         	ldr	r6, [r5, #0x74]
      38: 6574         	str	r4, [r6, #0x54]
      3a: 472e         	bx	r5
      3c: 554e         	strb	r6, [r1, r5]
      3e: 732d         	strb	r5, [r5, #0xc]
      40: 6174         	str	r4, [r6, #0x14]
      42: 6b63         	ldr	r3, [r4, #0x34]
      44: 7400         	strb	r0, [r0, #0x10]
      46: 7365         	strb	r5, [r4, #0xd]
      48: 6574         	str	r4, [r6, #0x54]
      4a: 722e         	strb	r6, [r5, #0x8]
      4c: 626f         	str	r7, [r5, #0x24]
      4e: 2e00         	cmp	r6, #0x0
      50: 7473         	strb	r3, [r6, #0x11]
      52: 7472         	strb	r2, [r6, #0x11]
      54: 6261         	str	r1, [r4, #0x24]
      56: 2e00         	cmp	r6, #0x0
      58: 7973         	ldrb	r3, [r6, #0x5]
      5a: 746d         	strb	r5, [r5, #0x11]
      5c: 6261         	str	r1, [r4, #0x24]
      5e: 00           	<unknown>

Disassembly of section .text.contar:

00000000 <contar>:
       0: b580         	push	{r7, lr}
       2: 466f         	mov	r7, sp
       4: ea20 70e0    	bic.w	r0, r0, r0, asr #31
       8: bd80         	pop	{r7, pc}

Disassembly of section .ARM.exidx.text.contar:

00000000 <.ARM.exidx.text.contar>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 0001         	movs	r1, r0
       6: 0000         	movs	r0, r0

Disassembly of section .rel.ARM.exidx.text.contar:

00000000 <.rel.ARM.exidx.text.contar>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 022a         	lsls	r2, r5, #0x8
       6: 0000         	movs	r0, r0

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
       0: 3a41         	subs	r2, #0x41
       2: 0000         	movs	r0, r0
       4: 6100         	str	r0, [r0, #0x10]
       6: 6165         	str	r5, [r4, #0x14]
       8: 6962         	ldr	r2, [r4, #0x14]
       a: 0100         	lsls	r0, r0, #0x4
       c: 0030         	movs	r0, r6
       e: 0000         	movs	r0, r0
      10: 3243         	adds	r2, #0x43
      12: 302e         	adds	r0, #0x2e
      14: 0039         	movs	r1, r7
      16: 6305         	str	r5, [r0, #0x30]
      18: 726f         	strb	r7, [r5, #0x9]
      1a: 6574         	str	r4, [r6, #0x54]
      1c: 2d78         	cmp	r5, #0x78
      1e: 336d         	adds	r3, #0x6d
      20: 0600         	lsls	r0, r0, #0x18
      22: 070a         	lsls	r2, r1, #0x1c
      24: 084d         	lsrs	r5, r1, #0x1
      26: 0900         	lsrs	r0, r0, #0x4
      28: 0e02         	lsrs	r2, r0, #0x18
      2a: 1100         	asrs	r0, r0, #0x4
      2c: 1401         	asrs	r1, r0, #0x10
      2e: 1501         	asrs	r1, r0, #0x14
      30: 1700         	asrs	r0, r0, #0x1c
      32: 1803         	adds	r3, r0, r0
      34: 1901         	adds	r1, r0, r4
      36: 2201         	movs	r2, #0x1
      38: 2601         	movs	r6, #0x1
      3a: 01           	<unknown>

Disassembly of section .symtab:

00000000 <.symtab>:
		...
      10: 0045         	lsls	r5, r0, #0x1
		...
      1a: 0000         	movs	r0, r0
      1c: 0004         	movs	r4, r0
      1e: fff1 0000    	<unknown>
		...
      2a: 0000         	movs	r0, r0
      2c: 0003         	movs	r3, r0
      2e: 0003         	movs	r3, r0
      30: 0007         	movs	r7, r0
		...
      3e: 0003         	movs	r3, r0
      40: 002e         	movs	r6, r5
      42: 0000         	movs	r0, r0
      44: 0001         	movs	r1, r0
      46: 0000         	movs	r0, r0
      48: 000a         	movs	r2, r1
      4a: 0000         	movs	r0, r0
      4c: 0012         	movs	r2, r2
      4e: 0003         	movs	r3, r0
