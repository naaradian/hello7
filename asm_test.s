.file "t.s"
 .include "psp_cnfg.met"
        .include "types.met"
        .include "psp_prv.met"

       ;  .file    "boot.met"
       ; .section "text", text

      ;  .global  _start
      ;  .global  _div0
      ;  .global  __loop_forever

 ;       .extern  _mw_main                  ; First C function
  ;      .extern  _initcopy

  ;    .option code32

;.seg "text",text
	  .global _asm_test
      .option  code16
       ; a1 contains the return value
       ; ADR     a2,_asm_test
	  	ADR     a2,_asm_test;+1;t
        BX      a2
   	   .option  code32
	;   	 .option  code16
 _asm_test:
   ;  mov r2,5
   ;  cmp r2,0
   ;     bne SUCCESS
   ;	 MOV      a2,#211;0xd3 ;SVC_MODE|IRQ_FIQ_BITS
  ;test   MSR      cpsr,a2
	;  SWITCH_TO_SVC a2

   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop
   nop



 ;FAIL:
 ;	NOP
  ;	nop
   ;	nop
	;nop
   ; b _asm_test
   ; SUCCESS:
    ADR     a2,idbx2+1
    BX      a2
        .option  code16
 idbx2:
    MOV     pc,lr

.end
