// Name:		Matrikelnummer:
// Name:		Matrikelnummer:
// Datum:

	.file	"aufgabe2.S"
	.text			@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align	2		@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen
				@ unteren 2 Bit sind 0
	.global	main		@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type	main,function
	
main:
	mov r6, #113
	ADR r1, marke 

	MSR CPSR, r6
marke: 
	mov r0, #10 


	bne marke
		



	
.Lfe1:
	.size	main,.Lfe1-main

// End of File
