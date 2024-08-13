/*
*
*   SIFD - Simple Internal Function Disassembler
*   A project made by myself (rokadontmiss on discord)
*   The point of this project is just to simply demonstrate how to achieve this, i know the code is not perfect, its designed for beginners.
*   I wrote all this in not even 1 hour+ so feel free to upload changes on github.
*
*/

#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include <iostream>
#include <cstdint>
#include <cstring>

#undef min

#include "../Zydis\Zydis.h"
#include "../workspace/disasm/disasm.h"
#include "../workspace/patternscan/pscan.h"