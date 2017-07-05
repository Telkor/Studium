// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe4.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
main:
	push {lr}

		ldr	r0, =Count
		ldr	r1, =Total
		ldr	r2, =Table
		ldr	r0, [r0]
		ldr	r1, [r1]
		b Add_ins
		
Add_ins:
		ldr	r3, [r2], #4
		add	r1, r1, r3
		subs	r0, r0, #1
		bpl	Add_ins
		ldr	r5, =Total
		str 	r1, [r5]
		pop {pc}

.Lfe1:
	.size	main,.Lfe1-main
		

.data
				
//; Data definitions
//Total 	DEFW 0 ; Total - initially zero
Total:	.word	0
//One 	DEFW 1 ; The number one
//Count 	DEFW 4 ; Loop counter (loop 5x)
Count:	.word	4
//Table 	DEFW 39 ; The numbers to total ...
//	DEFW 25 ;
//	DEFW 4 ;
//	DEFW 98 ;
//	DEFW 17 ;
Table:	.word	39, 25, 4, 98, 17



// End of File

