// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.



// color screen black
@8192
D = A

@R1     // RAM[1] = 8192 which will serve as counter for break case 
M = D

@SCREEN
D = A   // D.Register = 16384
(loop)

    // Break occurs when R1 = 0
    @R1
    M;JEQ
    A = D

    M = -1
    A = A + 1
    D = A

    // decrement R1 counter
    @R1
    M = M - 1       // RAM[1] = RAM[1] - 1

    @loop
    0; JMP

// color screen white
