// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe6.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	LDR	r0, Beispiel
	
	
	ldr	r1, = 0x0
	ldr	r2, = 0x0
	ldr	r7, = 0xFF00FF00
	
	mov	r1, r0, LSL#16	
	mov	r2, r0, LSR#16
	mov	r3, r1, LSL#8
	mov	r4, r1, LSR#8
	eor	r1, r3, r4
	mov	r1, r1, LSR#16
	mov	r5, r2, LSR#8
	mov	r6, r2, LSL#8
	eor	r2, r5, r6
	mov	r2, r2, LSL#16	
	
	
	EOR	r0, r1, r2
	
	
	
//..

	bx	lr
Beispiel:
	.word	0x1234ABCD
	
	
.Lfe1:
	.size	main,.Lfe1-main

// End of File
