#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti_CCS7/bios_6_41_04_54/packages;C:/ti_CCS7/ccsv7/ccs_base;G:/2017_18/Turkey/Book_Labs_CCS7/Chapter_07_SYSBIOS_TI_RTOS/clock1/.config
override XDCROOT = C:/ti_CCS7/xdctools_3_30_05_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti_CCS7/bios_6_41_04_54/packages;C:/ti_CCS7/ccsv7/ccs_base;G:/2017_18/Turkey/Book_Labs_CCS7/Chapter_07_SYSBIOS_TI_RTOS/clock1/.config;C:/ti_CCS7/xdctools_3_30_05_60/packages;..
HOSTOS = Windows
endif
