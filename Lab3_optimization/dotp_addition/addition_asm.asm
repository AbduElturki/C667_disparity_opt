

	.global Addition_In_ASM

Addition_In_ASM


	MV	A6,B5
	MV B4, A6

	MV	B6,A1
	Zero A8
	zero b6


;1
	LDDW .D1	*A4++, A11:A10


;2
	LDDW .D1	*A4++, A11:A10
|| 	[A1]	SUB .S1	A1,1,A1


;3
	LDDW .D1	*A4++, A11:A10
|| 	[A1]	SUB .S1	A1,1,A1
|| 	[A1]	B	.S2	LOOP

;4

	LDDW .D1	*A4++, A11:A10
|| 	[A1]	SUB .S1	A1,1,A1
|| 	[A1]	B	.S2	LOOP

;5
	LDDW .D1	*A4++, A11:A10
|| 	[A1]	B	.S2	LOOP

;6
	LDDW .D1	*A4++, A11:A10
||		MPY .M1	A10,A6,A7
||		MPY  .M2	A11,B5,B8
|| 	[A1]	SUB .S1	A1,1,A1
|| 	[A1]	B	.S2	LOOP

;7
	LDDW .D1	*A4++, A11:A10
||		MPY .M1	A10,A6,A7
||		MPY  .M2	A11,B5,B8
|| 	[A1]	SUB .S1	A1,1,A1
|| 	[A1]	B	.S2	LOOP


;8

LOOP	LDDW .D1	*A4++, A11:A10
||		MPY .M1	A10,A6,A7
||		ADD	.L1	A7,A8,A8
||		MPY  .M2	A11,B5,B8
||		ADD .L2 B8,B6,B6
|| 	[A1]	SUB .S1	A1,1,A1
|| 	[A1]	B	.S2	LOOP



	Add a8,b6,a4
	B B3
	nop 5















