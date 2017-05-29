# Fillit

The task is to find a minimum size square field to fill with a sudoku tetraminos that are provided in map. You should provide a map(map examples you can find in maps_fillit folder or generate with Tetriminos-generator-master)

## Prerequisites

To compile download this repository files.
Also make sure that you have installed *gcc*.
The programm have been developed under OS Yosemite.



## Compiling

To compile a binary for a project use a command

    make
    
## Usage

    ./fillit [map]

## Examples

*Content of map:*

    ..#.
    .###
    ....
    ....
    
    ....
    .##.
    .##.
    ....
    
    .#..
    .#..
    .#..
    .#..
    
    .#..
    ##..
    .#..
    ....
    
*Solution is*

    .A..C
    AAADC
    BBDDC
    BB.DC
