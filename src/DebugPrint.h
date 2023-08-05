#pragma once

#ifndef NDEBUG
	#include <iostream>
	#include <format>
	#include <string>
	#define DBG_FMT_PRINT(msg, args) std::cout << std::format(msg, ##args)
	#define DBG_PRINT(msg) std::cout << msg

	extern int surface_counter;
	extern int texture_counter;
#else

	#define DBG_FMT_PRINT(msg, args);
	#define DBG_PRINT(msg);

#endif