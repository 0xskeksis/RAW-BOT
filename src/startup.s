Reset_Handler:
	LDR R0, =_data_load
	LDR R1, =_data_start
	LDR R2, =_data_end
.data_loop:
	LDR R3, [R0], #4
	STR R3, [R1], #4
	CMP R1, R2
	BLO .data_loop
	LDR R0, =_bss_start
	LDR R1, =_bss_end
	MOV	R3, #0
.bss_loop:
	STR R3, [R0], #4
	CMP R0, R1
	BLO .bss_loop
.main: 
	BL main
	B .main
