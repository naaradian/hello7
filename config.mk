#MQX_NO_DEBUG       =1
#MQX_NO_OPTIMIZATION=1
RTCS_ROOT          =C:\ARC\rtcs2.95
RTCS_OS            =MQX25X
MQX_MAKEFILE_DIR   =C:\ARC\mqx2.50_atevbrm9200.met\mkscript
MQX_ROOT           =C:\ARC\mqx2.50_atevbrm9200.met
MQX_PSP            =at91rm9200
MQX_BSP            =atevbrm9200
MQX_ENDIAN         =l
MQX_COMPILER       =met
MQX_COMPILER_ROOT  =C:\ARC\MetaWare\hcarm
CPP                =C:\ARC\mktools\mkbin\cpp
AWK                =C:\ARC\mktools\mkbin\gawk
MQX_FSOFT          =1
#MQX_NO_C_COMPILER_RUNTIME =1

#MQX_PROFILE=debug
#MQX_PROFILE=fast
#MQX_PROFILE=small

#CPPFLAGS=\
# -DRTCSCFG_CHECK_ERRORS=0 \
# -DRTCSCFG_CHECK_MEMORY_ALLOCATION_ERRORS=0 \
# -DRTCSCFG_CHECK_VALIDITY=0 \
# -DRTCSCFG_CHECK_ADDRSIZE=0 \
# -DRTCSCFG_LOG_SOCKET_API=0 \
# -DRTCSCFG_LOG_PCB=0

include $(MQX_ROOT)\build\profile.mk

