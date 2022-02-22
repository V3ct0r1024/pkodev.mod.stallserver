#include <Windows.h>
#include <memory>

#include "address.h"
#include "pointer.h"

#include "loader.h"

namespace pkodev
{
    namespace global
    {
        // Size of patch in bytes
        const unsigned int patch_size{ 22 }; // 22 bytes

        // Patch bytes for function
        // void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
        char patch_bytes[patch_size] = {
            (char)0x56, (char)0x8D, (char)0x4C, (char)0x24,
            (char)0x14, (char)0x51, (char)0xE8, (char)0x90,
            (char)0x90, (char)0x90, (char)0x90, (char)0x90,
            (char)0x90, (char)0x90, (char)0x90, (char)0x90,
            (char)0x90, (char)0x90, (char)0x90, (char)0x90,
            (char)0x90, (char)0x90
        };

        // Copy of original bytes of function 
        // void CProCirculate::Login(const char *accounts, const char *password, const char* passport)
        char original_bytes[patch_size]{ 0x00 };
    }
}

// Write MD5 hash instead of encrypted password to login packet
void __stdcall WriteHashMD5(void* packet, const char* password);

// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // Nothing to do . . .
    return TRUE;
}

// Get mod information
void GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void Start(const char* path)
{
    // Access type
    DWORD access = PAGE_EXECUTE_READWRITE;

    // Calculate offset to function WritePassword() from patch start address
    const unsigned int offset = (
        reinterpret_cast<unsigned int>(&WriteHashMD5) - pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch - 0x07 - 0x04
   );

    // Write the offset to patch
    // patch + 0x07
    std::memcpy(reinterpret_cast<void*>(pkodev::global::patch_bytes + 0x07), reinterpret_cast<const void*>(&offset), sizeof(offset));

    // Change the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch), 
        pkodev::global::patch_size, access, &access);

    // Read original bytes
    ReadProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch),
        reinterpret_cast<LPVOID>(pkodev::global::original_bytes), pkodev::global::patch_size, nullptr);

    // Write patch bytes
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch),
        reinterpret_cast<LPCVOID>(pkodev::global::patch_bytes), pkodev::global::patch_size, nullptr);

    // Rollback the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch), 
        pkodev::global::patch_size, access, &access);
}

// Stop the mod
void Stop()
{
    // Access type
    DWORD access = PAGE_EXECUTE_READWRITE;

    // Change the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch), 
        pkodev::global::patch_size, access, &access);

    // Write original bytes
    WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch),
        reinterpret_cast<LPCVOID>(pkodev::global::original_bytes), pkodev::global::patch_size, nullptr);

    // Rollback the access protection of the proccess
    VirtualProtect(reinterpret_cast<LPVOID>(pkodev::address::MOD_EXE_VERSION::CProCirculate__Login__Patch), 
        pkodev::global::patch_size, access, &access);
}

// Write MD5 hash instead of encrypted password to login packet
void __stdcall WriteHashMD5(void* packet, const char* password)
{
    // Buffer for MD5 hash of password
    char md5_hash[33]{ 0x00 };

    // Get MD5 hash of password
    pkodev::pointer::md5string(password, md5_hash);

    // Write MD5 hash to the packet
    pkodev::pointer::WPacket__WriteString(packet, md5_hash);
}
