/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#include "../../workspace/includes.h"

// CBA to really explain what the following codes does since its all just a basic patternscan, there's a lot of examples on github that you could learn from.

auto pscanhelper::pattern_to_bytes( const std::string& pattern ) -> std::vector<int>
{
    std::vector<int> bytes;
    const char* start = pattern.c_str( );
    const char* end = start + pattern.length( );

    for ( const char* current = start; current < end; ++current )
    {
        if ( *current == ' ' || *current == '\t' ) continue;
        if ( *current == '?' )
        {
            ++current;
            if ( *current == '?' ) ++current;
            bytes.push_back( -1 );
        }
        else bytes.push_back( strtoul( current, const_cast< char** >( &current ), 16 ) );
    }

    return bytes;
}

auto pscanhelper::pscan( const std::string& pattern, int times ) -> uintptr_t
{
    uintptr_t moduleAddress = reinterpret_cast< uintptr_t >( GetModuleHandle( NULL ) );
    const auto patternBytes = pattern_to_bytes( pattern );
    const auto dosHeader = reinterpret_cast< PIMAGE_DOS_HEADER >( moduleAddress );
    const auto ntHeaders = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< uint8_t* >( moduleAddress ) + dosHeader->e_lfanew );
    const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
    const auto scanBytes = reinterpret_cast< uint8_t* >( moduleAddress );

    const auto s = patternBytes.size( );
    const auto d = patternBytes.data( );

    size_t nFoundResults = 0;

    for ( auto i = 0ul; i < sizeOfImage - s; ++i )
    {
        bool found = true;
        for ( auto j = 0ul; j < s; ++j )
        {
            if ( scanBytes[ i + j ] != d[ j ] && d[ j ] != -1 )
            {
                found = false;
                break;
            }
        }

        if ( found )
        {
            if ( times != 0 )
            {
                if ( nFoundResults < times )
                {
                    nFoundResults++;
                    found = false;
                }
                else return reinterpret_cast< uintptr_t >( &scanBytes[ i ] );
            }
            else return reinterpret_cast< uintptr_t >( &scanBytes[ i ] );
        }
    }

    return NULL;
}