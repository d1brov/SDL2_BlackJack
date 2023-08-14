#pragma once

#ifndef NDEBUG
	#include <iostream>
	#include <format>
	#include <string>

	#define DBG_FMT_PRINT(msg, ...) DBG_PRINT(std::format(msg, __VA_ARGS__))
	#define DBG_PRINT(msg) std::cout << msg
#else
	#define DBG_FMT_PRINT(msg, args);
	#define DBG_PRINT(msg);
#endif