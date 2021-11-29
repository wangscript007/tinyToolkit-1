/**
 *
 *  作者: hm
 *
 *  说明: 核心转储
 *
 */


#include "dump.h"


TOOLKIT_TEST_CASE(Dump, Hook)
{
	tinyToolkit::debug::Dump::Hook();
}


TOOLKIT_TEST_CASE(Dump, Release)
{
	tinyToolkit::debug::Dump::Release();
}
