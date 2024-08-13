# SIFD
A simple internal function disassembler from hex signature for beginners.

## Overview

This project is desinged to help you understand how to:

- Use the Zydis library for disassembling x86/x64 instructions.
- Read memory from a running process. (from level 0 noob to level 100 mafia boss)
- Search for a specific pattern in the memory and disassemble instructions at that location.

## Features

- **Memory Reading**: You know what it does... right?
- **Pattern Scanning**: Searches for byte patterns in the process memory.
- **Disassembly**: Disassembles instructions using Zydis.

## Requirements

- **Windows**: The project is designed to run on Windows (whatever the version).
- **Visual Studio**: For building the project (big L to cmake users).
- **Zydis Library**: Ensure you have the Zydis library installed and properly linked.

## Demonstration

![So we get the signature of the stuff we want](https://cdn.discordapp.com/attachments/1142220291859292411/1272847353447190590/Untitled.png?ex=66bc76f9&is=66bb2579&hm=86dc374b2dbfd50728d5e156708dc7c52d3d6021ca0bac3b8927f80b5b5ca02a&)

```cpp
mov     rax, [rbp+4C8h]
.text:000000014000188B                 mov     [rsp+5C0h+var_560], rax
.text:0000000140001890                 mov     [rsp+5C0h+var_570], 40000015h
.text:0000000140001898                 mov     [rsp+5C0h+var_56C], 1
.text:00000001400018A0                 call    cs:IsDebuggerPresent
.text:00000001400018A6                 mov     ebx, eax
.text:00000001400018A8                 xor     ecx, ecx        ; lpTopLevelExceptionFilter
```

Converted into a signature -> ``48 8B 85 ? ? ? ? 48 89 44 24 ? C7 44 24 ? ? ? ? ? C7 44 24 ? ? ? ? ? FF 15 ? ? ? ? 8B D8 33 C9``
Then we put the signature here:
```cpp
uintptr_t address = pscanhelper::pscan( "48 8B 85 ? ? ? ? 48 89 44 24 ? C7 44 24 ? ? ? ? ? C7 44 24 ? ? ? ? ? FF 15 ? ? ? ? 8B D8 33 C9" );
```

Once you have done that (make sure the signature is valid and correctly points to a logic bunch of instructions) you can compile and run, then appreciate the true mafia boss power!!!
![magic](https://cdn.discordapp.com/attachments/1142220291859292411/1272859698558799913/Screenshot_2024-08-13_120945.png?ex=66bc8278&is=66bb30f8&hm=f77a95c6949d24867ec5207434fd839bb79c7a33dfe6ce6bdbd184df09a5eb1f&)

You after using this:
![so real](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRIrQ3TjxRy209umolEBUlvWGgYqEbAd8QJmg&s)
