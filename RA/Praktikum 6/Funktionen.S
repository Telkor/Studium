// Programmgeruest zur Aufgabe Termin6 WS2013
// von: Manfred Pester
// vom: 18.09.2013
// @ int Operationen(volatile unsigned int* u_int_Taster, volatile unsigned int* u_int_LedsOn) 
@ Diese Funktion soll auf 
@ - LED DS1 (Bit 8) das Ergebnis von SW1 AND SW2 anzeigen 
@ - LED DS2 (Bit 9) das Ergebnis von SW1 OR SW2 anzeigen 
@ - LED DS3 (Bit 10) das Ergebnis von SW1 EOR SW2 anzeigen 
@ - LED DS4 und 5 (Bit 11/12) das Ergebnis von SW1 ADD SW2 anzeigen 
@ - LED DS6 und 7 (Bit 13/14) das Ergebnis von SW1 SUB SW2 anzeigen 
@ und bei gedrueckter TASTE SW3 (Bit 5) soll die Funktion ein TRUE (Wert ungleich 0) ansonsten FALSE (Wert gleich 0) an das aufrufende Programm zurueck geben.
@ ACHTUNG die Tasten und auch die Leuchtdioden sind Low-Aktiv beschaltet.
	.file	"Funktionen.S" 
	.text 
	.align	2 
	.global	Operationen 
	.type	Operationen, %function 
Operationen:

	push {r4, lr}
  
	LDR r2, [r0]		//PDSR einlesen
	eor r2, r2, #0x18
	mov r3, r2, lsr #3
	mov r4, r2, lsr #4
	mov r0, r2, lsr #5
	and r0, r0, #1 //Ruekgabewert
	and r3, r3, #1
	and r4, r4, #1

	 
// AND	 
	and r2, r3, r4
	mov r2, r2, lsl #8
	str r2, [r1]

// OR	 
	orr r2, r3, r4
	mov r2, r2, lsl #9
	str r2, [r1] 
	
	
// EOR 
	eor r2, r3, r4
	mov r2, r2, lsl #10
	str r2, [r1]

// ADDITION	 
	add r2, r3, r4
	mov r2, r2, lsl #11
	str r2, [r1]
	
// SUBTRAKTION 
	sub r2, r3, r4
	and r2, r2, #3
	mov r2, r2, lsl #13	
	str r2, [r1]
	 
// Beenden 

	pop {r4, pc}
 
.Lfe1: 
	.size	Operationen,.Lfe1- Operationen 
// End of File
