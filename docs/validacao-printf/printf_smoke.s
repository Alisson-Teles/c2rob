
out-printf/printf_smoke.o:	file format elf32-littlearm

Disassembly of section .strtab:

00000000 <.strtab>:
       0: 2e00         	cmp	r6, #0x0
       2: 6574         	str	r4, [r6, #0x54]
       4: 7478         	strb	r0, [r7, #0x11]
       6: 2e00         	cmp	r6, #0x0
       8: 6572         	str	r2, [r6, #0x54]
       a: 2e6c         	cmp	r6, #0x6c
       c: 5241         	strh	r1, [r0, r1]
       e: 2e4d         	cmp	r6, #0x4d
      10: 7865         	ldrb	r5, [r4, #0x1]
      12: 6469         	str	r1, [r5, #0x44]
      14: 2e78         	cmp	r6, #0x78
      16: 6574         	str	r4, [r6, #0x54]
      18: 7478         	strb	r0, [r7, #0x11]
      1a: 6e2e         	ldr	r6, [r5, #0x60]
      1c: 7865         	ldrb	r5, [r4, #0x1]
      1e: 0074         	lsls	r4, r6, #0x1
      20: 722e         	strb	r6, [r5, #0x8]
      22: 6c65         	ldr	r5, [r4, #0x44]
      24: 742e         	strb	r6, [r5, #0x10]
      26: 7865         	ldrb	r5, [r4, #0x1]
      28: 2e74         	cmp	r6, #0x74
      2a: 656e         	str	r6, [r5, #0x54]
      2c: 7478         	strb	r0, [r7, #0x11]
      2e: 2400         	movs	r4, #0x0
      30: 0074         	lsls	r4, r6, #0x1
      32: 622e         	str	r6, [r5, #0x20]
      34: 7373         	strb	r3, [r6, #0xd]
      36: 632e         	str	r6, [r5, #0x30]
      38: 6c61         	ldr	r1, [r4, #0x44]
      3a: 736c         	strb	r4, [r5, #0xd]
      3c: 2e00         	cmp	r6, #0x0
      3e: 5241         	strh	r1, [r0, r1]
      40: 2e4d         	cmp	r6, #0x4d
      42: 7461         	strb	r1, [r4, #0x11]
      44: 7274         	strb	r4, [r6, #0x9]
      46: 6269         	str	r1, [r5, #0x24]
      48: 7475         	strb	r5, [r6, #0x11]
      4a: 7365         	strb	r5, [r4, #0xd]
      4c: 2e00         	cmp	r6, #0x0
      4e: 6f72         	ldr	r2, [r6, #0x74]
      50: 6164         	str	r4, [r4, #0x14]
      52: 6174         	str	r4, [r6, #0x14]
      54: 2e2e         	cmp	r6, #0x2e
      56: 634c         	str	r4, [r1, #0x34]
      58: 6e6f         	ldr	r7, [r5, #0x64]
      5a: 7473         	strb	r3, [r6, #0x11]
      5c: 7473         	strb	r3, [r6, #0x11]
      5e: 0072         	lsls	r2, r6, #0x1
      60: 722e         	strb	r6, [r5, #0x8]
      62: 6c65         	ldr	r5, [r4, #0x44]
      64: 412e         	asrs	r6, r5
      66: 4d52         	ldr	r5, [pc, #0x148]        @ 0x1b0 <.strtab+0x1b0>
      68: 652e         	str	r6, [r5, #0x50]
      6a: 6978         	ldr	r0, [r7, #0x14]
      6c: 7864         	ldrb	r4, [r4, #0x1]
      6e: 742e         	strb	r6, [r5, #0x10]
      70: 7865         	ldrb	r5, [r4, #0x1]
      72: 2e74         	cmp	r6, #0x74
      74: 616d         	str	r5, [r5, #0x14]
      76: 6e69         	ldr	r1, [r5, #0x64]
      78: 2e00         	cmp	r6, #0x0
      7a: 6572         	str	r2, [r6, #0x54]
      7c: 2e6c         	cmp	r6, #0x6c
      7e: 6574         	str	r4, [r6, #0x54]
      80: 7478         	strb	r0, [r7, #0x11]
      82: 6d2e         	ldr	r6, [r5, #0x50]
      84: 6961         	ldr	r1, [r4, #0x14]
      86: 006e         	lsls	r6, r5, #0x1
      88: 6e2e         	ldr	r6, [r5, #0x60]
      8a: 746f         	strb	r7, [r5, #0x11]
      8c: 2e65         	cmp	r6, #0x65
      8e: 4e47         	ldr	r6, [pc, #0x11c]        @ 0x1ac <.strtab+0x1ac>
      90: 2d55         	cmp	r5, #0x55
      92: 7473         	strb	r3, [r6, #0x11]
      94: 6361         	str	r1, [r4, #0x34]
      96: 006b         	lsls	r3, r5, #0x1
      98: 7270         	strb	r0, [r6, #0x9]
      9a: 6e69         	ldr	r1, [r5, #0x64]
      9c: 6674         	str	r4, [r6, #0x64]
      9e: 7000         	strb	r0, [r0]
      a0: 6972         	ldr	r2, [r6, #0x14]
      a2: 746e         	strb	r6, [r5, #0x11]
      a4: 5f66         	ldrsh	r6, [r4, r5]
      a6: 6d73         	ldr	r3, [r6, #0x54]
      a8: 6b6f         	ldr	r7, [r5, #0x34]
      aa: 2e65         	cmp	r6, #0x65
      ac: 6f72         	ldr	r2, [r6, #0x74]
      ae: 0062         	lsls	r2, r4, #0x1
      b0: 732e         	strb	r6, [r5, #0xc]
      b2: 7274         	strb	r4, [r6, #0x9]
      b4: 6174         	str	r4, [r6, #0x14]
      b6: 0062         	lsls	r2, r4, #0x1
      b8: 732e         	strb	r6, [r5, #0xc]
      ba: 6d79         	ldr	r1, [r7, #0x54]
      bc: 6174         	str	r4, [r6, #0x14]
      be: 0062         	lsls	r2, r4, #0x1
      c0: 5f5f         	ldrsh	r7, [r3, r5]
      c2: 6561         	str	r1, [r4, #0x54]
      c4: 6261         	str	r1, [r4, #0x24]
      c6: 5f69         	ldrsh	r1, [r5, r5]
      c8: 6e75         	ldr	r5, [r6, #0x64]
      ca: 6977         	ldr	r7, [r6, #0x14]
      cc: 646e         	str	r6, [r5, #0x44]
      ce: 635f         	str	r7, [r3, #0x34]
      d0: 7070         	strb	r0, [r6, #0x1]
      d2: 705f         	strb	r7, [r3, #0x1]
      d4: 3072         	adds	r0, #0x72
      d6: 00           	<unknown>

Disassembly of section .text.next:

00000000 <next>:
       0: f240 0100    	movw	r1, #0x0
       4: f2c0 0100    	movt	r1, #0x0
       8: 6808         	ldr	r0, [r1]
       a: 1c42         	adds	r2, r0, #0x1
       c: 3003         	adds	r0, #0x3
       e: 600a         	str	r2, [r1]
      10: 4770         	bx	lr

Disassembly of section .rel.text.next:

00000000 <.rel.text.next>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 082f         	lsrs	r7, r5, #0x20
       6: 0000         	movs	r0, r0
       8: 0004         	movs	r4, r0
       a: 0000         	movs	r0, r0
       c: 0830         	lsrs	r0, r6, #0x20
       e: 0000         	movs	r0, r0

Disassembly of section .ARM.exidx.text.next:

00000000 <.ARM.exidx.text.next>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 0001         	movs	r1, r0
       6: 0000         	movs	r0, r0

Disassembly of section .rel.ARM.exidx.text.next:

00000000 <.rel.ARM.exidx.text.next>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 022a         	lsls	r2, r5, #0x8
       6: 0000         	movs	r0, r0

Disassembly of section .text.main:

00000000 <main>:
       0: b5d0         	push	{r4, r6, r7, lr}
       2: af02         	add	r7, sp, #0x8
       4: b086         	sub	sp, #0x18
       6: f240 0400    	movw	r4, #0x0
       a: f2c0 0400    	movt	r4, #0x0
       e: 6820         	ldr	r0, [r4]
      10: 2200         	movs	r2, #0x0
      12: 1c41         	adds	r1, r0, #0x1
      14: 3003         	adds	r0, #0x3
      16: 6021         	str	r1, [r4]
      18: 17c1         	asrs	r1, r0, #0x1f
      1a: 2301         	movs	r3, #0x1
      1c: e9cd 0104    	strd	r0, r1, [sp, #16]
      20: f240 0000    	movw	r0, #0x0
      24: 9201         	str	r2, [sp, #0x4]
      26: 9300         	str	r3, [sp]
      28: e9cd 3202    	strd	r3, r2, [sp, #8]
      2c: f2c0 0000    	movt	r0, #0x0
      30: 4669         	mov	r1, sp
      32: 2209         	movs	r2, #0x9
      34: 2303         	movs	r3, #0x3
      36: f7ff fffe    	bl	0x36 <main+0x36>        @ imm = #-0x4
      3a: 6820         	ldr	r0, [r4]
      3c: b006         	add	sp, #0x18
      3e: bdd0         	pop	{r4, r6, r7, pc}

Disassembly of section .rel.text.main:

00000000 <.rel.text.main>:
       0: 0006         	movs	r6, r0
       2: 0000         	movs	r0, r0
       4: 082f         	lsrs	r7, r5, #0x20
       6: 0000         	movs	r0, r0
       8: 000a         	movs	r2, r1
       a: 0000         	movs	r0, r0
       c: 0830         	lsrs	r0, r6, #0x20
       e: 0000         	movs	r0, r0
      10: 0020         	movs	r0, r4
      12: 0000         	movs	r0, r0
      14: 062f         	lsls	r7, r5, #0x18
      16: 0000         	movs	r0, r0
      18: 002c         	movs	r4, r5
      1a: 0000         	movs	r0, r0
      1c: 0630         	lsls	r0, r6, #0x18
      1e: 0000         	movs	r0, r0
      20: 0036         	movs	r6, r6
      22: 0000         	movs	r0, r0
      24: 0a0a         	lsrs	r2, r1, #0x8
      26: 0000         	movs	r0, r0

Disassembly of section .ARM.exidx.text.main:

00000000 <.ARM.exidx.text.main>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: b0b0         	sub	sp, #0xc0
       6: 80b0         	strh	r0, [r6, #0x4]

Disassembly of section .rel.ARM.exidx.text.main:

00000000 <.rel.ARM.exidx.text.main>:
       0: 0000         	movs	r0, r0
       2: 0000         	movs	r0, r0
       4: 0b00         	lsrs	r0, r0, #0xc
       6: 0000         	movs	r0, r0
       8: 0000         	movs	r0, r0
       a: 0000         	movs	r0, r0
       c: 042a         	lsls	r2, r5, #0x10
       e: 0000         	movs	r0, r0

Disassembly of section .bss.calls:

00000000 <calls>:
...

Disassembly of section .rodata..Lconststr:

00000000 <.Lconststr>:
       0: 6176         	str	r6, [r6, #0x14]
       2: 756c         	strb	r4, [r5, #0x15]
       4: 3d65         	subs	r5, #0x65
       6: 6425         	str	r5, [r4, #0x40]
       8: 0a           	<unknown>

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
      10: 009f         	lsls	r7, r3, #0x2
		...
      1a: 0000         	movs	r0, r0
      1c: 0004         	movs	r4, r0
      1e: fff1 0000    	<unknown>
		...
      2a: 0000         	movs	r0, r0
      2c: 0003         	movs	r3, r0
      2e: 0003         	movs	r3, r0
      30: 002f         	movs	r7, r5
		...
      3e: 0003         	movs	r3, r0
		...
      4c: 0003         	movs	r3, r0
      4e: 0007         	movs	r7, r0
      50: 002f         	movs	r7, r5
		...
      5e: 0007         	movs	r7, r0
      60: 0055         	lsls	r5, r2, #0x1
      62: 0000         	movs	r0, r0
      64: 0000         	movs	r0, r0
      66: 0000         	movs	r0, r0
      68: 0009         	movs	r1, r1
      6a: 0000         	movs	r0, r0
      6c: 0001         	movs	r1, r0
      6e: 000c         	movs	r4, r1
      70: 002a         	movs	r2, r5
      72: 0000         	movs	r0, r0
      74: 0001         	movs	r1, r0
      76: 0000         	movs	r0, r0
      78: 0012         	movs	r2, r2
      7a: 0000         	movs	r0, r0
      7c: 0012         	movs	r2, r2
      7e: 0003         	movs	r3, r0
      80: 0037         	movs	r7, r6
      82: 0000         	movs	r0, r0
      84: 0000         	movs	r0, r0
      86: 0000         	movs	r0, r0
      88: 0004         	movs	r4, r0
      8a: 0000         	movs	r0, r0
      8c: 0011         	movs	r1, r2
      8e: 000b         	movs	r3, r1
      90: 0083         	lsls	r3, r0, #0x2
      92: 0000         	movs	r0, r0
      94: 0001         	movs	r1, r0
      96: 0000         	movs	r0, r0
      98: 0040         	lsls	r0, r0, #0x1
      9a: 0000         	movs	r0, r0
      9c: 0012         	movs	r2, r2
      9e: 0007         	movs	r7, r0
      a0: 0098         	lsls	r0, r3, #0x2
		...
      aa: 0000         	movs	r0, r0
      ac: 0010         	movs	r0, r2
      ae: 0000         	movs	r0, r0
      b0: 00c0         	lsls	r0, r0, #0x3
		...
      ba: 0000         	movs	r0, r0
      bc: 0010         	movs	r0, r2
      be: 0000         	movs	r0, r0
