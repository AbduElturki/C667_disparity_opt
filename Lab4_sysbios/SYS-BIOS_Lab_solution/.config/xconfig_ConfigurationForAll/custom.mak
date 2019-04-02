## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/ConfigurationForAll_pe66.oe66

linker.cmd: package/cfg/ConfigurationForAll_pe66.xdl
	$(SED) 's"^\"\(package/cfg/ConfigurationForAll_pe66cfg.cmd\)\"$""\"C:/2017/Final_book_2017/Naim_Dahnoun_Book_Final/Chapter_07_SYSBIOS_TI_RTOS/CLK_SWI_TASK_HWI/.config/xconfig_ConfigurationForAll/\1\""' package/cfg/ConfigurationForAll_pe66.xdl > $@
