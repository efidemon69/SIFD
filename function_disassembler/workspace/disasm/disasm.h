/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#pragma once

class disasmhelper
{
public:
    static auto disassemble_instructions( void* address, size_t length ) -> void;
};