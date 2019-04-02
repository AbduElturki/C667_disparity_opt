## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/System_config_pe66.oe66

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/System_config_pe66.xdl
	$(SED) 's"^\"\(package/cfg/System_config_pe66cfg.cmd\)\"$""\"H:/C66/All_book_Final/ALL_Chapters/Chapter_9_SYSBIOS/test/CCS6_ws4/CLK_SWI_TASK_HWI/.config/xconfig_System_config/\1\""' package/cfg/System_config_pe66.xdl > $@
	-$(SETDATE) -r:max package/cfg/System_config_pe66.h compiler.opt compiler.opt.defs
