
#ifdef LPIT_START_SECT_DATA
	#undef LPIT_START_SECT_DATA
	#pragma clang section data = ".lpit_driver_data"
#endif

#ifdef LPIT_STOP_SECT_DATA
	#undef LPIT_STOP_SECT_DATA
	#pragma clang section data = ""
#endif

#ifdef LPIT_START_SECT_COSNT
	#undef LPIT_START_SECT_CONST
	#pragma clang section rodata = ".lpit_driver_rodata"
#endif

#ifdef LPIT_STOP_SECT_CONST
	#undef LPIT_STOP_SECT_CONST
	#pragma clang section rodata = ""
#endif

#ifdef LPIT_START_SECT_DATA_UNINIT
	#undef LPIT_START_SECT_DATA_UNINIT
	#pragma clang section bss = ".lpit_driver_bss"
#endif

#ifdef LPIT_STOP_SECT_DATA_UNINIT
	#undef LPIT_STOP_SECT_DATA_UNINIT
	#pragma clang section bss = ""
#endif

	
#ifdef LPIT_START_SECT_CODE
	#undef LPIT_START_SECT_CODE
	#pragma clang section text = ".lpit_driver_code"
#endif

#ifdef LPIT_STOP_SECT_CODE
	#undef LPIT_STOP_SECT_CODE
	#pragma clang section text = ""
#endif

