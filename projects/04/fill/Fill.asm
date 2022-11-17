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



// COLOR SCREEN BLACK

// ########### SETUP ###########
@8192
D = A

@R1     // RAM[1] = 8192 which will serve as counter for break case 
M = D

// ####### END OF SETUP #######
@SCREEN
D = A   // D.Register = 16384


(loop)

    // ######### TEMPORARILY STORING D-REGISTER VALUE IN RAM[2] ############# 
    @R2
    M = D   // RAM[2] = D


    // ######### BREAK CASE #############
    @R1
    D = M  // D = RAM[1]
    @END   // Break occurs when R1 = 0
    D;JEQ

    // ######## SETTING A-REGISTER BACK TO ORIGINAL VALUE STORED IN D-REGISTER  ###########
    @R2
    D = M
    A = D

    // ############ LOOP BODY ############
    M = -1
    A = A + 1
    D = A

    @R1
    M = M - 1       // RAM[1] = RAM[1] - 1

    @loop
    0; JMP
    // ######### END OF LOOP BODY #########


// ####### INFINITE LOOP TO HAULT CPU PROGRAM COUNTER #######
(END)
@R2
M = 0   // RAM[2] = 0 ... cleanup register
@END
0;JMP





// COLOR SCREEN WHITE
