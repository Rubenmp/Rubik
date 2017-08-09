# Rubik's cube

## Introduction
The rubik's cube will be read from file or keyboard.
The standard position for the rubik's cube is: green side in front of you and white side up.
If your rubik's cube has different patterns or colours, look at this:

-Example 1: If the center of the left side is red, in all stickers you should select orange.

-Example 2: If the center of the back side is black, in your black stickers you should select blue.

The program will read 54 colours, one side each time.

## Colours
You can use three different options (simultaneously is possible, not recommended):
   W/w/1 for white
   O/o/2 for orange
   G/g/3 for green
   R/r/4 for red
   L/l/5 for blue
   Y/y/6 for yellow

You will be able to change the colours if you made mistakes. The program represents Rubik's cube in two dimensions with green side in front of user (centered blue sticker represents that the colour of the side is blue):

![Colours](./img/colours.jpeg "Colours")

It would be represented in a file as
``` bash
w w w w w w w w w
o o o o o o o o o
g g g g g g g g g
r r r r r r r r r
l l l l l l l l l
y y y y y y y y y

```


## Movements
The rubik's cube has 12 different movements and double movements: F2, B2, R2, L2, U2, D2.
"FBRLUD" movements in clockwise
"fbrlud" the opposite movement.

F(ront), B(ack), R(igth), L(eft), U(p), D(own)

![Movements](./img/movements.jpg "Movements")

[Image from](http://rubiksolucion.blogspot.com.es/2012/07/notacion-cubo-de-rubik-3x3x3.html)

## Arguments
Usage:
``` bash
$ ./Rubik [option] [<input_file> [<output_file>]]
```
<input_file> represents a Rubik's cube which we want to solve, <output_file> is the optional file to send the solution.

| Option | Description |
|----|--
| -e | explanation of valid <input_file> (<output_file> has the same format) |
| -h | print this help and exit |
| -i | interactive mode of resolution, without extra arguments |
| -m | explain valid movements |
| -r | random Rubik's cube solution |
