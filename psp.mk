#
# Define the following variables:
#
#     srcs          list of source files without extensions
#     srcdirs       list of directories containing source files
#
#     dups          list of files to be copied to the output directory
#     dupdirs       list of directories containing the 'dups' files
#     CR            Added CR# 285, CR# 342
#

dupdirs += psp\$(MQX_PSP_SRC_DIR)
dups    += psp.h psptypes.h psp_rev.h armth.h psp_time.h psp_math.h
dups    += psp_cnfg.$(MQX_AEXT)
dups    += $(MQX_CPU_SUPPORT).h

srcdirs += psp\$(MQX_PSP_SRC_DIR)

srcs    += \
   dispatch  ipsum  \
   int_gkis  int_inst   int_kisr  int_pvta \
   int_unx   int_vtab   int_xcpt  int_sr   \
   mem_copy  mem_zero   int_pc             \
   sc_irdyq  stack_bu   stack_de  stack_st \
   psp_iinit psp_mat1   psp_mat2  psp_mat3 \
   psp_tkti  psp_dati   psp_hoti  psp_miti \
   psp_seti  psp_msti   psp_usti  psp_nsti \
   psp_psti  psp_tips   psp_tins  psp_tius \
   psp_tims  psp_tise   psp_timn  psp_tihr \
   psp_tida  psp_tiad   psp_tiol  psp_tipr \
   psp_tisu  psp_tixd   $(MQX_CPU_SUPPORT) \
   psp_mstiq psp_gelms  psp_tinm \
   cache     mmu

ifneq ($(findstring $(MQX_CPU_SUPPORT),ep7312),)
dups     += arm720t.h
srcs     +=  \
   asm720t 
endif

ifeq ($(MQX_PSP),cotulla)
dups     += xscale.h
srcs     +=  \
   asmxscale
endif

# The I80200 has some specific functions that aren't part
# of the Xscale architecture
ifeq ($(MQX_PSP),i80200)
dups     += xscale.h
srcs     +=  \
   asmi80200 asmxscale
endif
# Start CR 997 
# The S3C2500 
ifeq ($(MQX_PSP),s3c2500)
dups     += arm940t.h
srcs     +=  \
   asarm940t 
endif

ifeq ($(MQX_PSP), arm920t)
dups     += arm920t.h
srcs     +=  \
   asm920t
endif
# End CR 997 
ifeq ($(MQX_PSP), arm946)
dups     += arm946.h
srcs     += asm946
endif

ifeq ($(MQX_PSP), at91rm9200)
dups     += arm920t.h
srcs     +=  \
   asm920t
endif

# EOF
