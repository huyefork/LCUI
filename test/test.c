﻿#include <stdio.h>
#include <wchar.h>
#include <LCUI_Build.h>
#include <LCUI/LCUI.h>
#include "test.h"

#ifdef LCUI_BUILD_IN_WIN32
static void LoggerHandler( const char *str )
{
	OutputDebugStringA( str );
}

static void LoggerHandlerW( const wchar_t *str )
{
	OutputDebugStringW( str );
}
#endif

int main(void)
{
	int ret = 0;
#ifdef LCUI_BUILD_IN_WIN32
	_wchdir( L"F:\\代码库\\GitHub\\LCUI\\build\\VS2012\\LCUITest" );
	Logger_SetHandler( LoggerHandler );
	Logger_SetHandlerW( LoggerHandlerW );
#endif
	ret |= test_string();
	ret |= test_image_reader();
	ret |= test_css_parser();/*
	ret |= test_widget_render();
	ret |= test_char_render();
	ret |= test_string_render();*/
	printf("test result code: %d\n", ret);
	return ret;
}
