#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/pdk_C6678_1_1_2_6/packages;C:/ti/bios_6_41_04_54/packages;C:/ti/uia_2_00_02_39/packages;H:/packages;H:/C66/All_book_Final_2016/Chapter_7_Software_Optimisation/Chapter_7_Code/dotp_ALL_SA/.config
override XDCROOT = C:/ti/xdctools_3_32_00_06_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/pdk_C6678_1_1_2_6/packages;C:/ti/bios_6_41_04_54/packages;C:/ti/uia_2_00_02_39/packages;H:/packages;H:/C66/All_book_Final_2016/Chapter_7_Software_Optimisation/Chapter_7_Code/dotp_ALL_SA/.config;C:/ti/xdctools_3_32_00_06_core/packages;..
HOSTOS = Windows
endif
