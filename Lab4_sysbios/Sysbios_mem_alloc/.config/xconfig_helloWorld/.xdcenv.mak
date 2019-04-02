#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TI/uia_2_00_02_39/packages;C:/TI/bios_6_41_04_54/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_book_Final/ALL_Chapters/Chapter_9_SYSBIOS/Chapter_9_Code/.config
override XDCROOT = C:/CCS6/xdctools_3_31_00_24_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TI/uia_2_00_02_39/packages;C:/TI/bios_6_41_04_54/packages;C:/CCS6/ccsv6/ccs_base;L:/C66/All_book_Final/ALL_Chapters/Chapter_9_SYSBIOS/Chapter_9_Code/.config;C:/CCS6/xdctools_3_31_00_24_core/packages;..
HOSTOS = Windows
endif
