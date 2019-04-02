#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/TI/uia_2_00_03_43/packages;C:/TI/bios_6_40_01_15/packages;C:/TI/ccsv6/ccs_base;L:/C66/All_book_Final_2016/Chapter_9_SYSBIOS/Chapter_9_Code/Event2/CLK_SWI_TASK_HWI_with_Events/.config
override XDCROOT = C:/TI/xdctools_3_31_01_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/TI/uia_2_00_03_43/packages;C:/TI/bios_6_40_01_15/packages;C:/TI/ccsv6/ccs_base;L:/C66/All_book_Final_2016/Chapter_9_SYSBIOS/Chapter_9_Code/Event2/CLK_SWI_TASK_HWI_with_Events/.config;C:/TI/xdctools_3_31_01_33_core/packages;..
HOSTOS = Windows
endif
