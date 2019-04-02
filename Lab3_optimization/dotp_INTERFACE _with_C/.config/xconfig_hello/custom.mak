## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/hello_pe66.oe66

linker.cmd: package/cfg/hello_pe66.xdl
	$(SED) 's"^\"\(package/cfg/hello_pe66cfg.cmd\)\"$""\"I:/C66/All_code/Chapter_Optimisation/MPYSP/.config/xconfig_hello/\1\""' package/cfg/hello_pe66.xdl > $@
