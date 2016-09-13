.file "jump.s"
 ;.include "psp_cnfg.met"
  ;      .include "types.met"
   ;     .include "psp_prv.met"
  
    ;  .global _asm_test
	.global jump
      .option  code16
       ; a1 contains the return value
       ; ADR     a2,_asm_test
	
; 	ADR     a2,_asm_test;+1	;t
	ADR     a2,jump;+1	;t
        BX      a2
   	   .option  code32
	;   	 .option  code16
 ;_asm_test:
jump:
  	mov pc, r0	; jump to current address
     ;   mov r0,#0
	;	mov pc,r0
   ;  mov r2,5
   ;  cmp r2,0
   ;     bne SUCCESS
   ;	 MOV      a2,#SVC_MODE|IRQ_FIQ_BITS
   ;  MSR      cpsr,a2
  ;	  SWITCH_TO_SVC a2

;   nop
 ;  nop
  ; nop
 ;  nop
; FAIL:
 ;	NOP
 ;	nop
 ;	nop
 ;	nop
   ; b _asm_test
 ;   SUCCESS:
 ;   ADR     a2,idbx2+1
  ;  BX      a2
   ;     .option  code16
; idbx2:
 ;;   MOV     pc,lr

.end
