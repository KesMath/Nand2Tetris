// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.


// initialize program

@2
M = 0

(loop)
    // read in R1 and break if it's equal to 0
    @1
    //@exiting_loop
    M;JEQ


    // add R0 to D-Register
    @0
    D = D + M    // D = D + RAM[0]

    //decrement R1 and set it to register R1
    @R1
    M = M - 1   // M[1] = M[1] - 1
    @2
    M = D        // RAM[2] = D

    @loop
    0; JMP
