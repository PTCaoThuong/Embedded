
#ifdef SPI_START_SECT_DATA
	#undef SPI_START_SECT_DATA
	#pragma clang section data = ".spi_driver_data"
#endif

#ifdef SPI_STOP_SECT_DATA
	#undef SPI_STOP_SECT_DATA
	#pragma clang section data = ""
#endif

#ifdef SPI_START_SECT_COSNT
	#undef SPI_START_SECT_CONST
	#pragma clang section rodata = ".spi_driver_rodata"
#endif

#ifdef SPI_STOP_SECT_CONST
	#undef SPI_STOP_SECT_CONST
	#pragma clang section rodata = ""
#endif

#ifdef SPI_START_SECT_DATA_UNINIT
	#undef SPI_START_SECT_DATA_UNINIT
	#pragma clang section bss = ".spi_driver_bss"
#endif

#ifdef SPI_STOP_SECT_DATA_UNINIT
	#undef SPI_STOP_SECT_DATA_UNINIT
	#pragma clang section bss = ""
#endif

	
#ifdef SPI_START_SECT_CODE
	#undef SPI_START_SECT_CODE
	#pragma clang section text = ".spi_driver_code"
#endif

#ifdef SPI_STOP_SECT_CODE
	#undef SPI_STOP_SECT_CODE
	#pragma clang section text = ""
#endif

