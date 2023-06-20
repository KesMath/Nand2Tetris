## :floppy_disk:Nand2Tetris 2-Pass Hack Assembler (Project-Centered Course):floppy_disk:

This repository contains the Hack Assembler project from the Nand2Tetris course. The Hack Assembler is a tool used to convert assembly language code written in the Hack assembly language into binary machine code that can be executed by the Hack computer.

## About the Project

The Hack Assembler is part of the Nand2Tetris course, which provides a hands-on approach to building a complete computer system from the ground up. It starts with basic logic gates and progresses to a fully functional computer with a CPU, memory, and I/O devices.

The Hack Assembler specifically focuses on the assembly language used by the Hack computer architecture. It takes assembly code written in the Hack assembly language and translates it into binary machine code. The resulting binary code can be executed directly on the Hack hardware or on the Hack software simulator.

## Directory Description
```hack_assembler/assembler/binary/codegen.cc```: test <br>
```hack_assembler/assembler/driver/assembler.cc```: test<br>    
```hack_assembler/assembler/parser/parsers.cc```:  
```hack_assembler/assembler/parser/tokens.hh```:   
```hack_assembler/assembler/symbol_table/symboltable.cc```: 
```hack_assembler/assembler/utility/util.cc```:
```hack_assembler/assembler/utility/util.hh```:
```hack_assembler/assembler/Makefile```:     

## Usage

To get started with the Hack Assembler, follow these steps:


Navigate to the Hack Assembler directory:


    cd Nand2Tetris/hack_assembler/assembler


To use the Hack Assembler, follow these steps:


    Run the Hack Assembler using the following command:

    make asm
    make run-all 


The Hack Assembler will output the resulting binary code that's to be run on Hack's CPU Emulator:
```Add.hack```
```Max.hack```
```MaxL.hack```
```Pong.hack```
```PongL.hack```
```Rect.hack```
```RectL.hack```

## Demo