#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TI/bios_6_35_04_50/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_labs/Chapter_SYS_BIOS/SYS_BIOS_LAB/.config
override XDCROOT = C:/TI/xdctools_3_25_00_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TI/bios_6_35_04_50/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_labs/Chapter_SYS_BIOS/SYS_BIOS_LAB/.config;C:/TI/xdctools_3_25_00_48/packages;..
HOSTOS = Windows
endif
