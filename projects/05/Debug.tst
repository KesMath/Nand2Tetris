// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/05/CPU-external.tst

load CPU.hdl,
output-file CPU-external.out,
compare-to CPU-external.cmp,
output-list time%S0.4.0 inM%D0.6.0 instruction%B0.16.0 reset%B2.1.2 outM%D1.6.0 writeM%B3.1.3 addressM%D0.5.0 pc%D0.5.0;


set instruction %B0011000000111001, // @12345
tick, output, tock, output;

set instruction %B1110110000010000, // D=A
tick, output, tock, output;

set instruction %B0101101110100000, // @23456
tick, output, tock, output;

set instruction %B1110000111010000, // D=A-D
tick, output, tock, output;

set instruction %B0000001111101000, // @1000
tick, output, tock, output;

set instruction %B1110001100001000, // M=D
tick, output, tock, output;

set instruction %B0000001111101001, // @1001
tick, output, tock, output;

set instruction %B1110001110011000, // MD=D-1
tick, output, tock, output;

set instruction %B0000001111101000, // @1000
tick, output, tock, output;

set instruction %B1111010011010000, // D=D-M
set inM 11111,
tick, output, tock, output;

set instruction %B0000000000001110, // @14
tick, output, tock, output;