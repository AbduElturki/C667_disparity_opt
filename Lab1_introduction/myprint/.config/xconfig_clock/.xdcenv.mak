#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/CCS_studio_5_4/bios_6_35_01_29/packages;C:/CCS_studio_5_4/ccsv5/ccs_base;K:/C66/All_code/Chapter_CCS5/Print_Functions/.config
override XDCROOT = C:/CCS_studio_5_4/xdctools_3_25_00_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/CCS_studio_5_4/bios_6_35_01_29/packages;C:/CCS_studio_5_4/ccsv5/ccs_base;K:/C66/All_code/Chapter_CCS5/Print_Functions/.config;C:/CCS_studio_5_4/xdctools_3_25_00_48/packages;..
HOSTOS = Windows
endif
