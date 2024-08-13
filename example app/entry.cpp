/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#include <Windows.h>
#include <iostream>

auto awesomefunction( ) -> int
{
	int ptr = 10;
	(int*)ptr;

	//printf( "ptr: %p", ptr );
	return ptr;
}

auto main( ) -> int
{
	LoadLibraryA( "function_disassembler.dll" );
	awesomefunction( );

	for ( ;; );
	return true;
}