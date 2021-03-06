########################################################################
#
# Standard MQX Compile time profiles

export MQX_PROFILE

# Normal No Debug
ifeq ($(MQX_PROFILE),no_debug)
MQX_NO_DEBUG = 1
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)nodebug.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)nodebug.bsp
ifndef MQX_VERIFICATION_TESTING
CPPFLAGS += -DMQX_CHECK_VALIDITY=0
CPPFLAGS += -DMQX_KERNEL_LOGGING=0
CPPFLAGS += -DMQX_MONITOR_STACK=0
endif
endif

# Normal Ticks
ifeq ($(MQX_PROFILE),ticks)
#MQX_NO_DEBUG = 1
#my
MQX_NO_DEBUG = 0
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)ticks.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)ticks.bsp
ifndef MQX_VERIFICATION_TESTING
CPPFLAGS += -DMQX_CHECK_VALIDITY=0
CPPFLAGS += -DMQX_KERNEL_LOGGING=0
CPPFLAGS += -DMQX_MONITOR_STACK=0
endif
# incremental changes
CPPFLAGS += -DMQX_DEFAULT_TIME_SLICE_IN_TICKS=1
CPPFLAGS += -DMQX_TIMER_USES_TICKS_ONLY=1
endif

# Fastest
ifeq ($(MQX_PROFILE),fast)
MQX_NO_DEBUG = 1
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)fast.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)fast.bsp
ifndef MQX_VERIFICATION_TESTING
CPPFLAGS += -DMQX_CHECK_VALIDITY=0
CPPFLAGS += -DMQX_KERNEL_LOGGING=0
CPPFLAGS += -DMQX_MONITOR_STACK=0
endif
CPPFLAGS += -DMQX_DEFAULT_TIME_SLICE_IN_TICKS=1
CPPFLAGS += -DMQX_TIMER_USES_TICKS_ONLY=1
# incremental changes
CPPFlAGS += -DMQX_HAS_TIME_SLICE=0
CPPFLAGS += -DMQX_IS_MULTI_PROCESSOR=0
CPPFLAGS += -DMQX_MUTEX_HAS_POLLING=0
ifndef MQX_VERIFICATION_TESTING
CPPFLAGS += -DMQX_CHECK_ERRORS=0
CPPFLAGS += -DMQX_TASK_CREATION_BLOCKS=0
CPPFLAGS += -DMQX_CHECK_MEMORY_ALLOCATION_ERRORS=0
CPPFLAGS += -DMQX_COMPONENT_DESTRUCTION=0
CPPFLAGS += -DMQX_TASK_DESTRUCTION=0
endif
endif

# Small Size
ifeq ($(MQX_PROFILE),small)
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)size.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)size.bsp
CPPFLAGS += -DMQX_DEFAULT_TIME_SLICE_IN_TICKS=1
CPPFLAGS += -DMQX_LWLOG_TIME_STAMP_IN_TICKS=1
CPPFLAGS += -DMQX_TIMER_USES_TICKS_ONLY=1
CPPFlAGS += -DMQX_HAS_TIME_SLICE=0
CPPFLAGS += -DMQX_IS_MULTI_PROCESSOR=0
CPPFLAGS += -DMQX_MUTEX_HAS_POLLING=0
ifndef MQX_VERIFICATION_TESTING
CPPFLAGS += -DMQX_CHECK_VALIDITY=0
CPPFLAGS += -DMQX_KERNEL_LOGGING=0
CPPFLAGS += -DMQX_MONITOR_STACK=0
CPPFLAGS += -DMQX_CHECK_ERRORS=0
CPPFLAGS += -DMQX_TASK_CREATION_BLOCKS=0
CPPFLAGS += -DMQX_CHECK_MEMORY_ALLOCATION_ERRORS=0
CPPFLAGS += -DMQX_COMPONENT_DESTRUCTION=0
CPPFLAGS += -DMQX_TASK_DESTRUCTION=0
endif
# incremental changes
MQX_SMALL_SIZE = 1
#MQX_NO_DEBUG = 1
#MQX_NO_DEBUG = 0
#MQX_NO_C_COMPILER_RUNTIME = 1
CPPFlAGS += -DMQX_EXIT_ENABLED=0
CPPFLAGS += -DMQX_USE_IDLE_TASK=0
CPPFLAGS += -DMQX_USE_INLINE_MACROS=0
CPPFLAGS += -DMQX_USE_LWMEM_ALLOCATOR=1
endif

# Default as shipped but with floating point I$(PS)O enabled
ifeq ($(MQX_PROFILE),float)
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)float.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)float.bsp
CPPFLAGS += -DMQX_INCLUDE_FLOATING_POINT_IO=1
else
ifdef MQX_ADD_FLOATING_POINT_IO
CPPFLAGS += -DMQX_INCLUDE_FLOATING_POINT_IO=1
endif
endif

# Default as shipped but without optimizer turned on
ifeq ($(MQX_PROFILE),debug)
MQX_PSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)debug.psp
MQX_BSP_LIB_DIR = $(MQX_ROOT)$(PS)lib$(PS)debug.bsp
MQX_NO_OPTIMIZATION = 1
endif

ifdef RTCS_FASTEST
CPPFLAGS+=-DRTCSCFG_CHECK_ERRORS=0 \
 -DRTCSCFG_CHECK_MEMORY_ALLOCATION_ERRORS=0 \
 -DRTCSCFG_CHECK_VALIDITY=0 \
 -DRTCSCFG_CHECK_ADDRSIZE=0 \
 -DRTCSCFG_LOG_SOCKET_API=0 \
 -DRTCSCFG_LOG_PCB=0
endif

########################################################################
#  Flags you can emit

# add flags to change MQX compile time options
#CPPFLAGS = -DMQX_CHECK_VALIDITY=0

# define MQX_SMALL_SIZE if you wish the compiler to emit small code
#MQX_SMALL_SIZE = 1

# define MQX_NO_DEBUG if you do not want to debug the code
#MQX_NO_DEBUG = 1
#MQX_NO_DEBUG = 0
# define MQX_NO_C_COMPILER_RUNTIME if a minimal 'C' startup code is required
#MQX_NO_C_COMPILER_RUNTIME = 1

# define MQX_COMPRESS_INITDATA if the metaware compression and copying of 
# initialized data is desired
#MQX_COMPRESS_INITDATA = 1

# define MQX_DO_PROFILING if you wish to turn on statistical profiling 
# of the code
#MQX_DO_PROFILING = 1

# define MQX_DO_CPPLUS if you are compiling for Cplusplus
MQX_DO_CPPLUS = 1

# define MQX_NO_OPTIMIZATION if you wish the compiler to not optimize the code
#MQX_NO_OPTIMIZATION = 1

# EOF
