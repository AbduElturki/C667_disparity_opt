## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/ALL_Dotp_pe66.oe66

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/ALL_Dotp_pe66.xdl
	$(SED) 's"^\"\(package/cfg/ALL_Dotp_pe66cfg.cmd\)\"$""\"H:/C66/All_book_Final_2016/Chapter_7_Software_Optimisation/Chapter_7_Code/dotp_ALL_SA/.config/xconfig_ALL_Dotp/\1\""' package/cfg/ALL_Dotp_pe66.xdl > $@
	-$(SETDATE) -r:max package/cfg/ALL_Dotp_pe66.h compiler.opt compiler.opt.defs
