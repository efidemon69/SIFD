/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#pragma once

class pscanhelper
{
public:
    static auto pattern_to_bytes( const std::string& pattern ) -> std::vector<int>;
    static auto pscan( const std::string& pattern, int times = 0 ) -> uintptr_t;
};