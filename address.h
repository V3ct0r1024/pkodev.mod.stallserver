#pragma once

namespace pkodev
{
	namespace address
	{
		// Game.exe 0 (1222073761)
		namespace GAME_13X_0
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051AA5D;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x00577580;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F230;
		}

		// Game.exe 1 (1243412597)
		namespace GAME_13X_1
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051AB6D;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x005776C0;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F370;
		}

		// Game.exe 2 (1252912474)
		namespace GAME_13X_2
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051AC3D;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x00577780;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F430;
		}

		// Game.exe 3 (1244511158)
		namespace GAME_13X_3
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051AC2D;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x00577780;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F430;
		}

		// Game.exe 4 (1585009030)
		namespace GAME_13X_4
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051AE6D;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x00577B00;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F740;
		}

		// Game.exe 5 (1207214236)
		namespace GAME_13X_5
		{
			// void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
			// Patch
			// [8B 54 24 0C 52 8D 84 24 E0 00 00 00 50 8D 4C 24 18 E8 2D 46 03 00]
			// -> 
			// [56 8D 4C 24 14 51 E8 E8 90 90 90 90 90 90 90 90 90 90 90 90 90 90]
			const unsigned int CProCirculate__Login__Patch = 0x0051A8CD;

			// void md5string(char const* msg, char str[33])
			const unsigned int md5string = 0x00577400;

			// bool WPacket::WriteString(cChar *str)
			const unsigned int WPacket__WriteString = 0x0054F0B0;
		}
	}
}