#pragma once

#ifndef NDBG

	#define TESTING

	#ifdef TESTING
		#include <iostream>
		#include <format>
		#include <string>
		#define DBG_FMT_PRINT(msg, args) std::cout << std::format(msg, ##args)
		#define DBG_PRINT(msg) std::cout << msg
	#endif

	extern int surface_counter;

#endif