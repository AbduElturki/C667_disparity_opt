## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/clock_pe66.oe66

linker.cmd: package/cfg/clock_pe66.xdl
	$(SED) 's"^\"\(package/cfg/clock_pe66cfg.cmd\)\"$""\"K:/C66/All_code/Chapter_CCS5/Print_Functions/.config/xconfig_clock/\1\""' package/cfg/clock_pe66.xdl > $@
