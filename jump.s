.file "jump.s"
	.global Jump
      .option  code16
 	ADR     a2,Jump + 1	;t
        BX      a2
   	   .option  code32
  Jump:
  	mov pc, r0	; jump to current address
;      ADR     a2,idbx2+1
;    BX      a2
 ;       .option  code16
 ;idbx2:
 ;   MOV     pc,lr

.end
