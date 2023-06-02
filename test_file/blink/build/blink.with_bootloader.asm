
blink.with_bootloader.hex: formato do arquivo ihex


Desmontagem da seção .sec1:

00000000 <.sec1>:
   0:	0c 94 5c 00 	jmp	0xb8	;  0xb8
   4:	0c 94 6e 00 	jmp	0xdc	;  0xdc
   8:	0c 94 6e 00 	jmp	0xdc	;  0xdc
   c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  10:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  14:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  18:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  1c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  20:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  24:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  28:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  2c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  30:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  34:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  38:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  3c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  40:	0c 94 13 01 	jmp	0x226	;  0x226
  44:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  48:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  4c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  50:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  54:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  58:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  5c:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  60:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  64:	0c 94 6e 00 	jmp	0xdc	;  0xdc
  68:	00 00       	nop
  6a:	00 00       	nop
  6c:	24 00       	.word	0x0024	; ????
  6e:	27 00       	.word	0x0027	; ????
  70:	2a 00       	.word	0x002a	; ????
  72:	00 00       	nop
  74:	00 00       	nop
  76:	25 00       	.word	0x0025	; ????
  78:	28 00       	.word	0x0028	; ????
  7a:	2b 00       	.word	0x002b	; ????
  7c:	04 04       	cpc	r0, r4
  7e:	04 04       	cpc	r0, r4
  80:	04 04       	cpc	r0, r4
  82:	04 04       	cpc	r0, r4
  84:	02 02       	muls	r16, r18
  86:	02 02       	muls	r16, r18
  88:	02 02       	muls	r16, r18
  8a:	03 03       	mulsu	r16, r19
  8c:	03 03       	mulsu	r16, r19
  8e:	03 03       	mulsu	r16, r19
  90:	01 02       	muls	r16, r17
  92:	04 08       	sbc	r0, r4
  94:	10 20       	and	r1, r0
  96:	40 80       	ld	r4, Z
  98:	01 02       	muls	r16, r17
  9a:	04 08       	sbc	r0, r4
  9c:	10 20       	and	r1, r0
  9e:	01 02       	muls	r16, r17
  a0:	04 08       	sbc	r0, r4
  a2:	10 20       	and	r1, r0
  a4:	00 00       	nop
  a6:	00 08       	sbc	r0, r0
  a8:	00 02       	muls	r16, r16
  aa:	01 00       	.word	0x0001	; ????
  ac:	00 03       	mulsu	r16, r16
  ae:	04 07       	cpc	r16, r20
	...
  b8:	11 24       	eor	r1, r1
  ba:	1f be       	out	0x3f, r1	; 63
  bc:	cf ef       	ldi	r28, 0xFF	; 255
  be:	d8 e0       	ldi	r29, 0x08	; 8
  c0:	de bf       	out	0x3e, r29	; 62
  c2:	cd bf       	out	0x3d, r28	; 61
  c4:	21 e0       	ldi	r18, 0x01	; 1
  c6:	a0 e0       	ldi	r26, 0x00	; 0
  c8:	b1 e0       	ldi	r27, 0x01	; 1
  ca:	01 c0       	rjmp	.+2      	;  0xce
  cc:	1d 92       	st	X+, r1
  ce:	a9 30       	cpi	r26, 0x09	; 9
  d0:	b2 07       	cpc	r27, r18
  d2:	e1 f7       	brne	.-8      	;  0xcc
  d4:	0e 94 5d 01 	call	0x2ba	;  0x2ba
  d8:	0c 94 cc 01 	jmp	0x398	;  0x398
  dc:	0c 94 00 00 	jmp	0	;  0x0
  e0:	e1 eb       	ldi	r30, 0xB1	; 177
  e2:	f0 e0       	ldi	r31, 0x00	; 0
  e4:	24 91       	lpm	r18, Z
  e6:	ed e9       	ldi	r30, 0x9D	; 157
  e8:	f0 e0       	ldi	r31, 0x00	; 0
  ea:	94 91       	lpm	r25, Z
  ec:	e9 e8       	ldi	r30, 0x89	; 137
  ee:	f0 e0       	ldi	r31, 0x00	; 0
  f0:	e4 91       	lpm	r30, Z
  f2:	ee 23       	and	r30, r30
  f4:	c9 f0       	breq	.+50     	;  0x128
  f6:	22 23       	and	r18, r18
  f8:	39 f0       	breq	.+14     	;  0x108
  fa:	23 30       	cpi	r18, 0x03	; 3
  fc:	01 f1       	breq	.+64     	;  0x13e
  fe:	a8 f4       	brcc	.+42     	;  0x12a
 100:	21 30       	cpi	r18, 0x01	; 1
 102:	19 f1       	breq	.+70     	;  0x14a
 104:	22 30       	cpi	r18, 0x02	; 2
 106:	29 f1       	breq	.+74     	;  0x152
 108:	f0 e0       	ldi	r31, 0x00	; 0
 10a:	ee 0f       	add	r30, r30
 10c:	ff 1f       	adc	r31, r31
 10e:	ee 58       	subi	r30, 0x8E	; 142
 110:	ff 4f       	sbci	r31, 0xFF	; 255
 112:	a5 91       	lpm	r26, Z+
 114:	b4 91       	lpm	r27, Z
 116:	2f b7       	in	r18, 0x3f	; 63
 118:	f8 94       	cli
 11a:	ec 91       	ld	r30, X
 11c:	81 11       	cpse	r24, r1
 11e:	26 c0       	rjmp	.+76     	;  0x16c
 120:	90 95       	com	r25
 122:	9e 23       	and	r25, r30
 124:	9c 93       	st	X, r25
 126:	2f bf       	out	0x3f, r18	; 63
 128:	08 95       	ret
 12a:	27 30       	cpi	r18, 0x07	; 7
 12c:	a9 f0       	breq	.+42     	;  0x158
 12e:	28 30       	cpi	r18, 0x08	; 8
 130:	c9 f0       	breq	.+50     	;  0x164
 132:	24 30       	cpi	r18, 0x04	; 4
 134:	49 f7       	brne	.-46     	;  0x108
 136:	20 91 80 00 	lds	r18, 0x0080	;  0x800080
 13a:	2f 7d       	andi	r18, 0xDF	; 223
 13c:	03 c0       	rjmp	.+6      	;  0x144
 13e:	20 91 80 00 	lds	r18, 0x0080	;  0x800080
 142:	2f 77       	andi	r18, 0x7F	; 127
 144:	20 93 80 00 	sts	0x0080, r18	;  0x800080
 148:	df cf       	rjmp	.-66     	;  0x108
 14a:	24 b5       	in	r18, 0x24	; 36
 14c:	2f 77       	andi	r18, 0x7F	; 127
 14e:	24 bd       	out	0x24, r18	; 36
 150:	db cf       	rjmp	.-74     	;  0x108
 152:	24 b5       	in	r18, 0x24	; 36
 154:	2f 7d       	andi	r18, 0xDF	; 223
 156:	fb cf       	rjmp	.-10     	;  0x14e
 158:	20 91 b0 00 	lds	r18, 0x00B0	;  0x8000b0
 15c:	2f 77       	andi	r18, 0x7F	; 127
 15e:	20 93 b0 00 	sts	0x00B0, r18	;  0x8000b0
 162:	d2 cf       	rjmp	.-92     	;  0x108
 164:	20 91 b0 00 	lds	r18, 0x00B0	;  0x8000b0
 168:	2f 7d       	andi	r18, 0xDF	; 223
 16a:	f9 cf       	rjmp	.-14     	;  0x15e
 16c:	9e 2b       	or	r25, r30
 16e:	da cf       	rjmp	.-76     	;  0x124
 170:	3f b7       	in	r19, 0x3f	; 63
 172:	f8 94       	cli
 174:	80 91 05 01 	lds	r24, 0x0105	;  0x800105
 178:	90 91 06 01 	lds	r25, 0x0106	;  0x800106
 17c:	a0 91 07 01 	lds	r26, 0x0107	;  0x800107
 180:	b0 91 08 01 	lds	r27, 0x0108	;  0x800108
 184:	26 b5       	in	r18, 0x26	; 38
 186:	a8 9b       	sbis	0x15, 0	; 21
 188:	05 c0       	rjmp	.+10     	;  0x194
 18a:	2f 3f       	cpi	r18, 0xFF	; 255
 18c:	19 f0       	breq	.+6      	;  0x194
 18e:	01 96       	adiw	r24, 0x01	; 1
 190:	a1 1d       	adc	r26, r1
 192:	b1 1d       	adc	r27, r1
 194:	3f bf       	out	0x3f, r19	; 63
 196:	ba 2f       	mov	r27, r26
 198:	a9 2f       	mov	r26, r25
 19a:	98 2f       	mov	r25, r24
 19c:	88 27       	eor	r24, r24
 19e:	bc 01       	movw	r22, r24
 1a0:	cd 01       	movw	r24, r26
 1a2:	62 0f       	add	r22, r18
 1a4:	71 1d       	adc	r23, r1
 1a6:	81 1d       	adc	r24, r1
 1a8:	91 1d       	adc	r25, r1
 1aa:	42 e0       	ldi	r20, 0x02	; 2
 1ac:	66 0f       	add	r22, r22
 1ae:	77 1f       	adc	r23, r23
 1b0:	88 1f       	adc	r24, r24
 1b2:	99 1f       	adc	r25, r25
 1b4:	4a 95       	dec	r20
 1b6:	d1 f7       	brne	.-12     	;  0x1ac
 1b8:	08 95       	ret
 1ba:	8f 92       	push	r8
 1bc:	9f 92       	push	r9
 1be:	af 92       	push	r10
 1c0:	bf 92       	push	r11
 1c2:	cf 92       	push	r12
 1c4:	df 92       	push	r13
 1c6:	ef 92       	push	r14
 1c8:	ff 92       	push	r15
 1ca:	0e 94 b8 00 	call	0x170	;  0x170
 1ce:	4b 01       	movw	r8, r22
 1d0:	5c 01       	movw	r10, r24
 1d2:	88 ee       	ldi	r24, 0xE8	; 232
 1d4:	c8 2e       	mov	r12, r24
 1d6:	83 e0       	ldi	r24, 0x03	; 3
 1d8:	d8 2e       	mov	r13, r24
 1da:	e1 2c       	mov	r14, r1
 1dc:	f1 2c       	mov	r15, r1
 1de:	0e 94 b8 00 	call	0x170	;  0x170
 1e2:	68 19       	sub	r22, r8
 1e4:	79 09       	sbc	r23, r9
 1e6:	8a 09       	sbc	r24, r10
 1e8:	9b 09       	sbc	r25, r11
 1ea:	68 3e       	cpi	r22, 0xE8	; 232
 1ec:	73 40       	sbci	r23, 0x03	; 3
 1ee:	81 05       	cpc	r24, r1
 1f0:	91 05       	cpc	r25, r1
 1f2:	a8 f3       	brcs	.-22     	;  0x1de
 1f4:	21 e0       	ldi	r18, 0x01	; 1
 1f6:	c2 1a       	sub	r12, r18
 1f8:	d1 08       	sbc	r13, r1
 1fa:	e1 08       	sbc	r14, r1
 1fc:	f1 08       	sbc	r15, r1
 1fe:	88 ee       	ldi	r24, 0xE8	; 232
 200:	88 0e       	add	r8, r24
 202:	83 e0       	ldi	r24, 0x03	; 3
 204:	98 1e       	adc	r9, r24
 206:	a1 1c       	adc	r10, r1
 208:	b1 1c       	adc	r11, r1
 20a:	c1 14       	cp	r12, r1
 20c:	d1 04       	cpc	r13, r1
 20e:	e1 04       	cpc	r14, r1
 210:	f1 04       	cpc	r15, r1
 212:	29 f7       	brne	.-54     	;  0x1de
 214:	ff 90       	pop	r15
 216:	ef 90       	pop	r14
 218:	df 90       	pop	r13
 21a:	cf 90       	pop	r12
 21c:	bf 90       	pop	r11
 21e:	af 90       	pop	r10
 220:	9f 90       	pop	r9
 222:	8f 90       	pop	r8
 224:	08 95       	ret
 226:	1f 92       	push	r1
 228:	0f 92       	push	r0
 22a:	0f b6       	in	r0, 0x3f	; 63
 22c:	0f 92       	push	r0
 22e:	11 24       	eor	r1, r1
 230:	2f 93       	push	r18
 232:	3f 93       	push	r19
 234:	8f 93       	push	r24
 236:	9f 93       	push	r25
 238:	af 93       	push	r26
 23a:	bf 93       	push	r27
 23c:	80 91 01 01 	lds	r24, 0x0101	;  0x800101
 240:	90 91 02 01 	lds	r25, 0x0102	;  0x800102
 244:	a0 91 03 01 	lds	r26, 0x0103	;  0x800103
 248:	b0 91 04 01 	lds	r27, 0x0104	;  0x800104
 24c:	30 91 00 01 	lds	r19, 0x0100	;  0x800100
 250:	23 e0       	ldi	r18, 0x03	; 3
 252:	23 0f       	add	r18, r19
 254:	2d 37       	cpi	r18, 0x7D	; 125
 256:	58 f5       	brcc	.+86     	;  0x2ae
 258:	01 96       	adiw	r24, 0x01	; 1
 25a:	a1 1d       	adc	r26, r1
 25c:	b1 1d       	adc	r27, r1
 25e:	20 93 00 01 	sts	0x0100, r18	;  0x800100
 262:	80 93 01 01 	sts	0x0101, r24	;  0x800101
 266:	90 93 02 01 	sts	0x0102, r25	;  0x800102
 26a:	a0 93 03 01 	sts	0x0103, r26	;  0x800103
 26e:	b0 93 04 01 	sts	0x0104, r27	;  0x800104
 272:	80 91 05 01 	lds	r24, 0x0105	;  0x800105
 276:	90 91 06 01 	lds	r25, 0x0106	;  0x800106
 27a:	a0 91 07 01 	lds	r26, 0x0107	;  0x800107
 27e:	b0 91 08 01 	lds	r27, 0x0108	;  0x800108
 282:	01 96       	adiw	r24, 0x01	; 1
 284:	a1 1d       	adc	r26, r1
 286:	b1 1d       	adc	r27, r1
 288:	80 93 05 01 	sts	0x0105, r24	;  0x800105
 28c:	90 93 06 01 	sts	0x0106, r25	;  0x800106
 290:	a0 93 07 01 	sts	0x0107, r26	;  0x800107
 294:	b0 93 08 01 	sts	0x0108, r27	;  0x800108
 298:	bf 91       	pop	r27
 29a:	af 91       	pop	r26
 29c:	9f 91       	pop	r25
 29e:	8f 91       	pop	r24
 2a0:	3f 91       	pop	r19
 2a2:	2f 91       	pop	r18
 2a4:	0f 90       	pop	r0
 2a6:	0f be       	out	0x3f, r0	; 63
 2a8:	0f 90       	pop	r0
 2aa:	1f 90       	pop	r1
 2ac:	18 95       	reti
 2ae:	26 e8       	ldi	r18, 0x86	; 134
 2b0:	23 0f       	add	r18, r19
 2b2:	02 96       	adiw	r24, 0x02	; 2
 2b4:	a1 1d       	adc	r26, r1
 2b6:	b1 1d       	adc	r27, r1
 2b8:	d2 cf       	rjmp	.-92     	;  0x25e
 2ba:	78 94       	sei
 2bc:	84 b5       	in	r24, 0x24	; 36
 2be:	82 60       	ori	r24, 0x02	; 2
 2c0:	84 bd       	out	0x24, r24	; 36
 2c2:	84 b5       	in	r24, 0x24	; 36
 2c4:	81 60       	ori	r24, 0x01	; 1
 2c6:	84 bd       	out	0x24, r24	; 36
 2c8:	85 b5       	in	r24, 0x25	; 37
 2ca:	82 60       	ori	r24, 0x02	; 2
 2cc:	85 bd       	out	0x25, r24	; 37
 2ce:	85 b5       	in	r24, 0x25	; 37
 2d0:	81 60       	ori	r24, 0x01	; 1
 2d2:	85 bd       	out	0x25, r24	; 37
 2d4:	80 91 6e 00 	lds	r24, 0x006E	;  0x80006e
 2d8:	81 60       	ori	r24, 0x01	; 1
 2da:	80 93 6e 00 	sts	0x006E, r24	;  0x80006e
 2de:	10 92 81 00 	sts	0x0081, r1	;  0x800081
 2e2:	80 91 81 00 	lds	r24, 0x0081	;  0x800081
 2e6:	82 60       	ori	r24, 0x02	; 2
 2e8:	80 93 81 00 	sts	0x0081, r24	;  0x800081
 2ec:	80 91 81 00 	lds	r24, 0x0081	;  0x800081
 2f0:	81 60       	ori	r24, 0x01	; 1
 2f2:	80 93 81 00 	sts	0x0081, r24	;  0x800081
 2f6:	80 91 80 00 	lds	r24, 0x0080	;  0x800080
 2fa:	81 60       	ori	r24, 0x01	; 1
 2fc:	80 93 80 00 	sts	0x0080, r24	;  0x800080
 300:	80 91 b1 00 	lds	r24, 0x00B1	;  0x8000b1
 304:	84 60       	ori	r24, 0x04	; 4
 306:	80 93 b1 00 	sts	0x00B1, r24	;  0x8000b1
 30a:	80 91 b0 00 	lds	r24, 0x00B0	;  0x8000b0
 30e:	81 60       	ori	r24, 0x01	; 1
 310:	80 93 b0 00 	sts	0x00B0, r24	;  0x8000b0
 314:	80 91 7a 00 	lds	r24, 0x007A	;  0x80007a
 318:	84 60       	ori	r24, 0x04	; 4
 31a:	80 93 7a 00 	sts	0x007A, r24	;  0x80007a
 31e:	80 91 7a 00 	lds	r24, 0x007A	;  0x80007a
 322:	82 60       	ori	r24, 0x02	; 2
 324:	80 93 7a 00 	sts	0x007A, r24	;  0x80007a
 328:	80 91 7a 00 	lds	r24, 0x007A	;  0x80007a
 32c:	81 60       	ori	r24, 0x01	; 1
 32e:	80 93 7a 00 	sts	0x007A, r24	;  0x80007a
 332:	80 91 7a 00 	lds	r24, 0x007A	;  0x80007a
 336:	80 68       	ori	r24, 0x80	; 128
 338:	80 93 7a 00 	sts	0x007A, r24	;  0x80007a
 33c:	10 92 c1 00 	sts	0x00C1, r1	;  0x8000c1
 340:	ed e9       	ldi	r30, 0x9D	; 157
 342:	f0 e0       	ldi	r31, 0x00	; 0
 344:	24 91       	lpm	r18, Z
 346:	e9 e8       	ldi	r30, 0x89	; 137
 348:	f0 e0       	ldi	r31, 0x00	; 0
 34a:	84 91       	lpm	r24, Z
 34c:	88 23       	and	r24, r24
 34e:	99 f0       	breq	.+38     	;  0x376
 350:	90 e0       	ldi	r25, 0x00	; 0
 352:	88 0f       	add	r24, r24
 354:	99 1f       	adc	r25, r25
 356:	fc 01       	movw	r30, r24
 358:	e8 59       	subi	r30, 0x98	; 152
 35a:	ff 4f       	sbci	r31, 0xFF	; 255
 35c:	a5 91       	lpm	r26, Z+
 35e:	b4 91       	lpm	r27, Z
 360:	fc 01       	movw	r30, r24
 362:	ee 58       	subi	r30, 0x8E	; 142
 364:	ff 4f       	sbci	r31, 0xFF	; 255
 366:	85 91       	lpm	r24, Z+
 368:	94 91       	lpm	r25, Z
 36a:	8f b7       	in	r24, 0x3f	; 63
 36c:	f8 94       	cli
 36e:	ec 91       	ld	r30, X
 370:	e2 2b       	or	r30, r18
 372:	ec 93       	st	X, r30
 374:	8f bf       	out	0x3f, r24	; 63
 376:	c0 e0       	ldi	r28, 0x00	; 0
 378:	d0 e0       	ldi	r29, 0x00	; 0
 37a:	81 e0       	ldi	r24, 0x01	; 1
 37c:	0e 94 70 00 	call	0xe0	;  0xe0
 380:	0e 94 dd 00 	call	0x1ba	;  0x1ba
 384:	80 e0       	ldi	r24, 0x00	; 0
 386:	0e 94 70 00 	call	0xe0	;  0xe0
 38a:	0e 94 dd 00 	call	0x1ba	;  0x1ba
 38e:	20 97       	sbiw	r28, 0x00	; 0
 390:	a1 f3       	breq	.-24     	;  0x37a
 392:	0e 94 00 00 	call	0	;  0x0
 396:	f1 cf       	rjmp	.-30     	;  0x37a
 398:	f8 94       	cli
 39a:	ff cf       	rjmp	.-2      	;  0x39a

Desmontagem da seção .sec2:

00007e00 <.sec2>:
    7e00:	11 24       	eor	r1, r1
    7e02:	84 b7       	in	r24, 0x34	; 52
    7e04:	14 be       	out	0x34, r1	; 52
    7e06:	81 ff       	sbrs	r24, 1
    7e08:	f0 d0       	rcall	.+480    	;  0x7fea
    7e0a:	85 e0       	ldi	r24, 0x05	; 5
    7e0c:	80 93 81 00 	sts	0x0081, r24	;  0x800081
    7e10:	82 e0       	ldi	r24, 0x02	; 2
    7e12:	80 93 c0 00 	sts	0x00C0, r24	;  0x8000c0
    7e16:	88 e1       	ldi	r24, 0x18	; 24
    7e18:	80 93 c1 00 	sts	0x00C1, r24	;  0x8000c1
    7e1c:	86 e0       	ldi	r24, 0x06	; 6
    7e1e:	80 93 c2 00 	sts	0x00C2, r24	;  0x8000c2
    7e22:	80 e1       	ldi	r24, 0x10	; 16
    7e24:	80 93 c4 00 	sts	0x00C4, r24	;  0x8000c4
    7e28:	8e e0       	ldi	r24, 0x0E	; 14
    7e2a:	c9 d0       	rcall	.+402    	;  0x7fbe
    7e2c:	25 9a       	sbi	0x04, 5	; 4
    7e2e:	86 e0       	ldi	r24, 0x06	; 6
    7e30:	20 e3       	ldi	r18, 0x30	; 48
    7e32:	3c ef       	ldi	r19, 0xFC	; 252
    7e34:	91 e0       	ldi	r25, 0x01	; 1
    7e36:	30 93 85 00 	sts	0x0085, r19	;  0x800085
    7e3a:	20 93 84 00 	sts	0x0084, r18	;  0x800084
    7e3e:	96 bb       	out	0x16, r25	; 22
    7e40:	b0 9b       	sbis	0x16, 0	; 22
    7e42:	fe cf       	rjmp	.-4      	;  0x7e40
    7e44:	1d 9a       	sbi	0x03, 5	; 3
    7e46:	a8 95       	wdr
    7e48:	81 50       	subi	r24, 0x01	; 1
    7e4a:	a9 f7       	brne	.-22     	;  0x7e36
    7e4c:	cc 24       	eor	r12, r12
    7e4e:	dd 24       	eor	r13, r13
    7e50:	88 24       	eor	r8, r8
    7e52:	83 94       	inc	r8
    7e54:	b5 e0       	ldi	r27, 0x05	; 5
    7e56:	ab 2e       	mov	r10, r27
    7e58:	a1 e1       	ldi	r26, 0x11	; 17
    7e5a:	9a 2e       	mov	r9, r26
    7e5c:	f3 e0       	ldi	r31, 0x03	; 3
    7e5e:	bf 2e       	mov	r11, r31
    7e60:	a2 d0       	rcall	.+324    	;  0x7fa6
    7e62:	81 34       	cpi	r24, 0x41	; 65
    7e64:	61 f4       	brne	.+24     	;  0x7e7e
    7e66:	9f d0       	rcall	.+318    	;  0x7fa6
    7e68:	08 2f       	mov	r16, r24
    7e6a:	af d0       	rcall	.+350    	;  0x7fca
    7e6c:	02 38       	cpi	r16, 0x82	; 130
    7e6e:	11 f0       	breq	.+4      	;  0x7e74
    7e70:	01 38       	cpi	r16, 0x81	; 129
    7e72:	11 f4       	brne	.+4      	;  0x7e78
    7e74:	84 e0       	ldi	r24, 0x04	; 4
    7e76:	01 c0       	rjmp	.+2      	;  0x7e7a
    7e78:	83 e0       	ldi	r24, 0x03	; 3
    7e7a:	8d d0       	rcall	.+282    	;  0x7f96
    7e7c:	89 c0       	rjmp	.+274    	;  0x7f90
    7e7e:	82 34       	cpi	r24, 0x42	; 66
    7e80:	11 f4       	brne	.+4      	;  0x7e86
    7e82:	84 e1       	ldi	r24, 0x14	; 20
    7e84:	03 c0       	rjmp	.+6      	;  0x7e8c
    7e86:	85 34       	cpi	r24, 0x45	; 69
    7e88:	19 f4       	brne	.+6      	;  0x7e90
    7e8a:	85 e0       	ldi	r24, 0x05	; 5
    7e8c:	a6 d0       	rcall	.+332    	;  0x7fda
    7e8e:	80 c0       	rjmp	.+256    	;  0x7f90
    7e90:	85 35       	cpi	r24, 0x55	; 85
    7e92:	79 f4       	brne	.+30     	;  0x7eb2
    7e94:	88 d0       	rcall	.+272    	;  0x7fa6
    7e96:	e8 2e       	mov	r14, r24
    7e98:	ff 24       	eor	r15, r15
    7e9a:	85 d0       	rcall	.+266    	;  0x7fa6
    7e9c:	08 2f       	mov	r16, r24
    7e9e:	10 e0       	ldi	r17, 0x00	; 0
    7ea0:	10 2f       	mov	r17, r16
    7ea2:	00 27       	eor	r16, r16
    7ea4:	0e 29       	or	r16, r14
    7ea6:	1f 29       	or	r17, r15
    7ea8:	00 0f       	add	r16, r16
    7eaa:	11 1f       	adc	r17, r17
    7eac:	8e d0       	rcall	.+284    	;  0x7fca
    7eae:	68 01       	movw	r12, r16
    7eb0:	6f c0       	rjmp	.+222    	;  0x7f90
    7eb2:	86 35       	cpi	r24, 0x56	; 86
    7eb4:	21 f4       	brne	.+8      	;  0x7ebe
    7eb6:	84 e0       	ldi	r24, 0x04	; 4
    7eb8:	90 d0       	rcall	.+288    	;  0x7fda
    7eba:	80 e0       	ldi	r24, 0x00	; 0
    7ebc:	de cf       	rjmp	.-68     	;  0x7e7a
    7ebe:	84 36       	cpi	r24, 0x64	; 100
    7ec0:	09 f0       	breq	.+2      	;  0x7ec4
    7ec2:	40 c0       	rjmp	.+128    	;  0x7f44
    7ec4:	70 d0       	rcall	.+224    	;  0x7fa6
    7ec6:	6f d0       	rcall	.+222    	;  0x7fa6
    7ec8:	08 2f       	mov	r16, r24
    7eca:	6d d0       	rcall	.+218    	;  0x7fa6
    7ecc:	80 e0       	ldi	r24, 0x00	; 0
    7ece:	c8 16       	cp	r12, r24
    7ed0:	80 e7       	ldi	r24, 0x70	; 112
    7ed2:	d8 06       	cpc	r13, r24
    7ed4:	18 f4       	brcc	.+6      	;  0x7edc
    7ed6:	f6 01       	movw	r30, r12
    7ed8:	b7 be       	out	0x37, r11	; 55
    7eda:	e8 95       	spm
    7edc:	c0 e0       	ldi	r28, 0x00	; 0
    7ede:	d1 e0       	ldi	r29, 0x01	; 1
    7ee0:	62 d0       	rcall	.+196    	;  0x7fa6
    7ee2:	89 93       	st	Y+, r24
    7ee4:	0c 17       	cp	r16, r28
    7ee6:	e1 f7       	brne	.-8      	;  0x7ee0
    7ee8:	f0 e0       	ldi	r31, 0x00	; 0
    7eea:	cf 16       	cp	r12, r31
    7eec:	f0 e7       	ldi	r31, 0x70	; 112
    7eee:	df 06       	cpc	r13, r31
    7ef0:	18 f0       	brcs	.+6      	;  0x7ef8
    7ef2:	f6 01       	movw	r30, r12
    7ef4:	b7 be       	out	0x37, r11	; 55
    7ef6:	e8 95       	spm
    7ef8:	68 d0       	rcall	.+208    	;  0x7fca
    7efa:	07 b6       	in	r0, 0x37	; 55
    7efc:	00 fc       	sbrc	r0, 0
    7efe:	fd cf       	rjmp	.-6      	;  0x7efa
    7f00:	a6 01       	movw	r20, r12
    7f02:	a0 e0       	ldi	r26, 0x00	; 0
    7f04:	b1 e0       	ldi	r27, 0x01	; 1
    7f06:	2c 91       	ld	r18, X
    7f08:	30 e0       	ldi	r19, 0x00	; 0
    7f0a:	11 96       	adiw	r26, 0x01	; 1
    7f0c:	8c 91       	ld	r24, X
    7f0e:	11 97       	sbiw	r26, 0x01	; 1
    7f10:	90 e0       	ldi	r25, 0x00	; 0
    7f12:	98 2f       	mov	r25, r24
    7f14:	88 27       	eor	r24, r24
    7f16:	82 2b       	or	r24, r18
    7f18:	93 2b       	or	r25, r19
    7f1a:	12 96       	adiw	r26, 0x02	; 2
    7f1c:	fa 01       	movw	r30, r20
    7f1e:	0c 01       	movw	r0, r24
    7f20:	87 be       	out	0x37, r8	; 55
    7f22:	e8 95       	spm
    7f24:	11 24       	eor	r1, r1
    7f26:	4e 5f       	subi	r20, 0xFE	; 254
    7f28:	5f 4f       	sbci	r21, 0xFF	; 255
    7f2a:	f1 e0       	ldi	r31, 0x01	; 1
    7f2c:	a0 38       	cpi	r26, 0x80	; 128
    7f2e:	bf 07       	cpc	r27, r31
    7f30:	51 f7       	brne	.-44     	;  0x7f06
    7f32:	f6 01       	movw	r30, r12
    7f34:	a7 be       	out	0x37, r10	; 55
    7f36:	e8 95       	spm
    7f38:	07 b6       	in	r0, 0x37	; 55
    7f3a:	00 fc       	sbrc	r0, 0
    7f3c:	fd cf       	rjmp	.-6      	;  0x7f38
    7f3e:	97 be       	out	0x37, r9	; 55
    7f40:	e8 95       	spm
    7f42:	26 c0       	rjmp	.+76     	;  0x7f90
    7f44:	84 37       	cpi	r24, 0x74	; 116
    7f46:	b1 f4       	brne	.+44     	;  0x7f74
    7f48:	2e d0       	rcall	.+92     	;  0x7fa6
    7f4a:	2d d0       	rcall	.+90     	;  0x7fa6
    7f4c:	f8 2e       	mov	r15, r24
    7f4e:	2b d0       	rcall	.+86     	;  0x7fa6
    7f50:	3c d0       	rcall	.+120    	;  0x7fca
    7f52:	f6 01       	movw	r30, r12
    7f54:	ef 2c       	mov	r14, r15
    7f56:	8f 01       	movw	r16, r30
    7f58:	0f 5f       	subi	r16, 0xFF	; 255
    7f5a:	1f 4f       	sbci	r17, 0xFF	; 255
    7f5c:	84 91       	lpm	r24, Z
    7f5e:	1b d0       	rcall	.+54     	;  0x7f96
    7f60:	ea 94       	dec	r14
    7f62:	f8 01       	movw	r30, r16
    7f64:	c1 f7       	brne	.-16     	;  0x7f56
    7f66:	08 94       	sec
    7f68:	c1 1c       	adc	r12, r1
    7f6a:	d1 1c       	adc	r13, r1
    7f6c:	fa 94       	dec	r15
    7f6e:	cf 0c       	add	r12, r15
    7f70:	d1 1c       	adc	r13, r1
    7f72:	0e c0       	rjmp	.+28     	;  0x7f90
    7f74:	85 37       	cpi	r24, 0x75	; 117
    7f76:	39 f4       	brne	.+14     	;  0x7f86
    7f78:	28 d0       	rcall	.+80     	;  0x7fca
    7f7a:	8e e1       	ldi	r24, 0x1E	; 30
    7f7c:	0c d0       	rcall	.+24     	;  0x7f96
    7f7e:	85 e9       	ldi	r24, 0x95	; 149
    7f80:	0a d0       	rcall	.+20     	;  0x7f96
    7f82:	8f e0       	ldi	r24, 0x0F	; 15
    7f84:	7a cf       	rjmp	.-268    	;  0x7e7a
    7f86:	81 35       	cpi	r24, 0x51	; 81
    7f88:	11 f4       	brne	.+4      	;  0x7f8e
    7f8a:	88 e0       	ldi	r24, 0x08	; 8
    7f8c:	18 d0       	rcall	.+48     	;  0x7fbe
    7f8e:	1d d0       	rcall	.+58     	;  0x7fca
    7f90:	80 e1       	ldi	r24, 0x10	; 16
    7f92:	01 d0       	rcall	.+2      	;  0x7f96
    7f94:	65 cf       	rjmp	.-310    	;  0x7e60
    7f96:	98 2f       	mov	r25, r24
    7f98:	80 91 c0 00 	lds	r24, 0x00C0	;  0x8000c0
    7f9c:	85 ff       	sbrs	r24, 5
    7f9e:	fc cf       	rjmp	.-8      	;  0x7f98
    7fa0:	90 93 c6 00 	sts	0x00C6, r25	;  0x8000c6
    7fa4:	08 95       	ret
    7fa6:	80 91 c0 00 	lds	r24, 0x00C0	;  0x8000c0
    7faa:	87 ff       	sbrs	r24, 7
    7fac:	fc cf       	rjmp	.-8      	;  0x7fa6
    7fae:	80 91 c0 00 	lds	r24, 0x00C0	;  0x8000c0
    7fb2:	84 fd       	sbrc	r24, 4
    7fb4:	01 c0       	rjmp	.+2      	;  0x7fb8
    7fb6:	a8 95       	wdr
    7fb8:	80 91 c6 00 	lds	r24, 0x00C6	;  0x8000c6
    7fbc:	08 95       	ret
    7fbe:	e0 e6       	ldi	r30, 0x60	; 96
    7fc0:	f0 e0       	ldi	r31, 0x00	; 0
    7fc2:	98 e1       	ldi	r25, 0x18	; 24
    7fc4:	90 83       	st	Z, r25
    7fc6:	80 83       	st	Z, r24
    7fc8:	08 95       	ret
    7fca:	ed df       	rcall	.-38     	;  0x7fa6
    7fcc:	80 32       	cpi	r24, 0x20	; 32
    7fce:	19 f0       	breq	.+6      	;  0x7fd6
    7fd0:	88 e0       	ldi	r24, 0x08	; 8
    7fd2:	f5 df       	rcall	.-22     	;  0x7fbe
    7fd4:	ff cf       	rjmp	.-2      	;  0x7fd4
    7fd6:	84 e1       	ldi	r24, 0x14	; 20
    7fd8:	de cf       	rjmp	.-68     	;  0x7f96
    7fda:	1f 93       	push	r17
    7fdc:	18 2f       	mov	r17, r24
    7fde:	e3 df       	rcall	.-58     	;  0x7fa6
    7fe0:	11 50       	subi	r17, 0x01	; 1
    7fe2:	e9 f7       	brne	.-6      	;  0x7fde
    7fe4:	f2 df       	rcall	.-28     	;  0x7fca
    7fe6:	1f 91       	pop	r17
    7fe8:	08 95       	ret
    7fea:	80 e0       	ldi	r24, 0x00	; 0
    7fec:	e8 df       	rcall	.-48     	;  0x7fbe
    7fee:	ee 27       	eor	r30, r30
    7ff0:	ff 27       	eor	r31, r31
    7ff2:	09 94       	ijmp

Desmontagem da seção .sec3:

00007ffe <.sec3>:
    7ffe:	04 04       	cpc	r0, r4
