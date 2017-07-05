// Loesung Aufgabe 3 und 4 von Termin4 Rechnerarchitektur SS2013
// Name: 	Matrikelnummer:
// Name: 	Matrikelnummer:
// Datum:
	.file "aufgabe3.S"
	.text 		@ legt eine Textsection fuer PrgrammCode + Konstanten an
	.align 2 	@ sorgt dafuer, dass nachfolgende Anweisungen auf einer durch 4 teilbaren Adresse liegen	
			@ unteren 2 Bit sind 0
	.global main 	@ nimmt das Symbol main in die globale Sysmboltabelle auf
	.type main,function
main:
	stmfd sp!, {r4, r5, lr} @ Ruecksprungadresse und Register sichern
kopieren:
@ hier Ihr Programm zum Kopieren einer Byte-Tabelle (je 8Bit) in eine Word-Tabelle (je 32Bit) einfuegen

	LDR r1, =Liste1 @r1 zeigt auf Liste1
	LDR r2, =Liste2 @r2 Zeigt auf Liste2
	LDRB r3, [r1] @Anzahl der Elemente aus Liste1
	STR r3, [r2]
	ADD r2, #4
	ADD r1, #1
	SUB r3, #1

loop:

	SUBS r3, #1 @ Anzahl der Elemente - 1
	LDRSB r0,[r1] @ lade ersten Wert & konvertierung von 8Bit auf vorzeichenrichtige 32Bit-Zahlen
	STR r0,[r2] @ speichere ihn in Liste2

	ADD r1, #1 @ Lesezeiger verschieben
	ADD r2, #4 @ Schreibzeiger verschieben
	
	

	@ LDR r0,[r1, #4] @ lade zweiten Wert
	@ STR r0,[r2, #4] @ speichere ihn in Liste2
	
	bne loop
	
sortieren:
@bubblesort

	LDR r3, =Liste2 @ listenpointer holen
	LDRB r4, [r3] @erstes element holen aka groeﬂe
	SUB r4, #2
	
    
	aeussereSchleife:
		LDR r3, =Liste2
		mov r5, r4 @aktuelle anzahl der unsortieren elemente fuer innere schleife holen
    
	innereSchleife:
		ADD r3, #4
		LDR r1, [r3]
		LDR r2, [r3, #4]
    
	ueberpruefung:
		cmp r2, r1 @ r1-r2 und ergebnis verwerfen
		
		STRMI r2, [r3]
		STRMI r1, [r3, #4]
    
	bmi swap @falls negativ flag, tauschen
	
        schieber:
		STR r1, [r3]
		STR r2, [r3, #4]
		subs r5, #1 @ inneren schleifenzaeahler
		bne innereSchleife @falls noch nicht 0 nochmal
    
		subs r4, #1 @aueﬂere schleife runterzaehlen
		
		bne aeussereSchleife
		bal fertig
    
	swap:
	   	mov r0, r1 @ dreieckstausch
	    	mov r1, r2
	    	mov r2, r0
	  	bal schieber


fertig:
	ldmfd sp!, {r4, r5, pc} @ Ruecksprungadresse und Register

TAB2: .word Liste2 @ Beispiel um an Adressen aus anderen Segmenten zu kommen

.Lfe1:
	.size main,.Lfe1-main

// .data-Section fuer initialisierte Daten
	.data
// Erster Wert der Tabelle steht fuer die Anzahl (max. 64) der Werte der Tabelle
Liste1: .byte (Liste1Ende-Liste1), -9, 8, -7, 6, -5, 4, -3, 2, -1, 0, 127, 128
Liste1Ende:

// .comm-Section fuer nicht initialisierte Daten
	.comm Liste2, ((Liste1Ende-Liste1)*4) 	@ Speicherbereich mit der Groesse*4 von Liste1 reservieren

// End of File

