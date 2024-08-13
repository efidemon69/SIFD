/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
* 
*/

#include "workspace/includes.h"

auto DllMain( HMODULE hmod, DWORD call, LPVOID res ) -> BOOL APIENTRY
{
    UNREFERENCED_PARAMETER( hmod );
    UNREFERENCED_PARAMETER( res );

    if ( call == 0x1 )
    {
        uintptr_t address = pscanhelper::pscan( "your hex sig here" ); // The format of the sig must be an hexadecimal byte sequence, ex: (69 69 ?? 69 ? 69)
        if ( address )
        {
            std::cout << "[+] Pattern found at address: " << std::hex << address << std::endl;
            disasmhelper::disassemble_instructions( reinterpret_cast< void* >( address ), 0x100 );
        }
        else
        {
            std::cout << "[-] Pattern not found!" << std::endl;
        }
    }

    return TRUE;
}