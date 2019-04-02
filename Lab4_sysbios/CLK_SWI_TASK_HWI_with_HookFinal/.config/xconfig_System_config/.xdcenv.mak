#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/uia_2_00_02_39/packages;C:/ti/bios_6_40_04_47/packages;C:/ti/ccsv6/ccs_base;H:/C66/All_book_Final/ALL_Chapters/Chapter_9_SYSBIOS/test/CCS6_ws4/CLK_SWI_TASK_HWI/.config
override XDCROOT = C:/ti/xdctools_3_30_06_67_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/uia_2_00_02_39/packages;C:/ti/bios_6_40_04_47/packages;C:/ti/ccsv6/ccs_base;H:/C66/All_book_Final/ALL_Chapters/Chapter_9_SYSBIOS/test/CCS6_ws4/CLK_SWI_TASK_HWI/.config;C:/ti/xdctools_3_30_06_67_core/packages;..
HOSTOS = Windows
endif
