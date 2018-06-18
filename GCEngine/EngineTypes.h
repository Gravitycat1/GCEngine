#pragma once
#ifndef _ENGINETYPES_H
#define _ENGINETYPES_H

using ubyte = unsigned __int8;

enum class ELogType : ubyte
{
	LT_General,
	LT_Warnning,
	LT_Error,
	LT_TOTAL
};

#endif // !_ENGINETYPES_H
