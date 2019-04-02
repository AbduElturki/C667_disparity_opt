## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/ConfigurationForAll_pe66.oe66

linker.cmd: package/cfg/ConfigurationForAll_pe66.xdl
	$(SED) 's"^\"\(package/cfg/ConfigurationForAll_pe66cfg.cmd\)\"$""\"L:/C66/All_labs/Chapter_SYS_BIOS/SYS_BIOS_LAB/.config/xconfig_ConfigurationForAll/\1\""' package/cfg/ConfigurationForAll_pe66.xdl > $@
