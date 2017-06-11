// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe5.S"
	.text		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
			@ unteren 2 Bit sind 0
	.global	main	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	push	{r4, r5, lr}
	mov	r0, #1
	mov	r1, #-1
	mov	r2, #15
	mov	r3, #0x80000000
	
	MVN	r0, r0
	ADD 	r0, #1
	
	RSB	r1, #0
	
	SUB	r2, r2, LSL#1
	
	NEG	r4, r2
	
//..


	pop	{r4, r5, pc}
.Lfe1:
	.size	main,.Lfe1-main

// End of File
