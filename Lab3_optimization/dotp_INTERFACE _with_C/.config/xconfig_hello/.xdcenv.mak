#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/CCS5_4/bios_6_35_01_29/packages;C:/CCS5_4/ccsv5/ccs_base;I:/C66/All_code/Chapter_Optimisation/MPYSP/.config
override XDCROOT = C:/CCS5_4/xdctools_3_25_00_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/CCS5_4/bios_6_35_01_29/packages;C:/CCS5_4/ccsv5/ccs_base;I:/C66/All_code/Chapter_Optimisation/MPYSP/.config;C:/CCS5_4/xdctools_3_25_00_48/packages;..
HOSTOS = Windows
endif
