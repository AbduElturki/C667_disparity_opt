#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/bios_6_35_01_29/packages;C:/ti/ccsv6/ccs_base;C:/2017/Final_book_2017/Naim_Dahnoun_Book_Final/Chapter_07_SYSBIOS_TI_RTOS/CLK_SWI_TASK_HWI/.config
override XDCROOT = C:/ti/xdctools_3_25_00_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/bios_6_35_01_29/packages;C:/ti/ccsv6/ccs_base;C:/2017/Final_book_2017/Naim_Dahnoun_Book_Final/Chapter_07_SYSBIOS_TI_RTOS/CLK_SWI_TASK_HWI/.config;C:/ti/xdctools_3_25_00_48/packages;..
HOSTOS = Windows
endif
