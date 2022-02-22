#pragma once
#include "address.h"

namespace pkodev
{
	namespace pointer
	{
		// void md5string(char const* msg, char str[33])
		typedef void(__cdecl* md5string_Ptr)(const char*, char*);
		md5string_Ptr md5string = (md5string_Ptr)(void*)(pkodev::address::MOD_EXE_VERSION::md5string);

		// bool WPacket::WriteString(cChar *str)
		typedef bool(__thiscall* WPacket__WriteString__Ptr)(void*, const char*);
		WPacket__WriteString__Ptr WPacket__WriteString = (WPacket__WriteString__Ptr)(void*)(pkodev::address::MOD_EXE_VERSION::WPacket__WriteString);
	}
}