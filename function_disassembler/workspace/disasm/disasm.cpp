/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#include "../../workspace/includes.h"

auto disasmhelper::disassemble_instructions( void* address, size_t length ) -> void
{
    ZydisDecoder decoder;
    ZydisDecoderInit( &decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_STACK_WIDTH_64 );

    ZydisFormatter formatter;
    ZydisFormatterInit( &formatter, ZYDIS_FORMATTER_STYLE_INTEL );

    // Limit the length of code we read, 4 KB as default, feel free to change for your needs.
    length = std::min( length, static_cast< size_t >( 0x1000 ) ); 

    // Creates a vector to hold the bytes read from memory and then read memory from the current process starting at 'address' and store it in 'code'.
    std::vector<uint8_t> code( length );
    if ( !ReadProcessMemory( GetCurrentProcess( ), address, code.data( ), length, nullptr ) )
    {
        std::cout << "[-] Failed to read memory at address: 0x" << address << std::endl;
        return;
    }

    ZydisDecodedInstruction instruction; // Will hold the decoded instruction.
    uint64_t runtime_address = reinterpret_cast< uint64_t >( address ); // Starting address for disassembly.
    size_t offset = 0; // Offset in the code buffer.
    ZydisDecodedOperand operands[ ZYDIS_MAX_OPERAND_COUNT ]; // Array to hold operands for each instruction.

    std::cout << "[+] Disassembled instructions: " << std::endl;
    while ( offset < length )
    {
        // Decodes an instruction from the code buffer starting at 'offset'.
        ZyanStatus status = ZydisDecoderDecodeFull( &decoder, code.data( ) + offset, length - offset, &instruction, operands );
        if ( ZYAN_SUCCESS( status ) )
        {
            // We store the formatted instruction string in the following buffer then format the decoded instruction to a human readable string (would take us years to understand the result without that)
            char buffer[ 256 ];
            ZydisFormatterFormatInstruction( &formatter, &instruction, operands, instruction.operand_count_visible, buffer, sizeof( buffer ), runtime_address, ZYAN_NULL );
            std::cout << "[>] 0x" << std::hex << runtime_address << ": " << buffer << std::endl; // wow, what's this for???

            // Well here we just update the offset and runtime address for the next instruction..
            offset += instruction.length;
            runtime_address += instruction.length;
        }
        else
        {
            std::cout << "[-] Failed to decode instruction at offset " << offset << std::endl;
            break;
        }
    }
}
