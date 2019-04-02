#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TI/uia_2_00_00_28/packages;C:/TI/bios_6_40_01_15/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_code/Chapter16_Debugging/Systen_Analyzer_Example/.config
override XDCROOT = C:/CCS6/xdctools_3_30_01_25_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TI/uia_2_00_00_28/packages;C:/TI/bios_6_40_01_15/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_code/Chapter16_Debugging/Systen_Analyzer_Example/.config;C:/CCS6/xdctools_3_30_01_25_core/packages;..
HOSTOS = Windows
endif
