The goal of this problem is to fill a board of N rows and N columns with white and black stones.

Initially, white and black stones are placed,randomly, in all cells of the first column and the first row.

The figure below gives an example of a board with N = 6.



![image](https://www.thehuxley.com/api/v1/problems/image/a068cdd197fca9a2d6b576adc3d356c0513865e58.png)



Once the starting stones have been placed, the other cells on the board will be filled with a white or black stone according to the following rule.



Consider the cell in position (i,j),for i > 1 and j > 1. To know the color of the stone in this cell, you need to know the color of the stones in the three cells {(i, j − 1), (i − 1,j − 1), (i − 1 , j)}. The figure also illustrates which cells are used to determine the color of the stone in the cell (i,j). If there are more white stones than black in these three cells, the color of the stone in the cell (i, j)will be black. If there are more black stones than white, the color will be white.

Note that by this definition, the first cell to be filled will be (2, 2), because it will be the only empty for which we will already know the color of the three stonesrequired. In the example of the figure, the stone in the cell (2, 2) will be black, because there are two white and one black between cells {(2, 1), (1, 1 ), (1, 2)}.

In this problem, given N and the color of the starting stones, your program should compute the color of the stone that will be placed in the cell (N,N).



## Input format

The first row of the entry contains an Integer N,representing the number of rows and columns in the board.

The following N lines each contain integer N defining the starting board.

The integers in the first row and in the first column of the board will always be 0 or 1,representing a white or black stone, respectively.

The other integers will always be 9,indicating that the corresponding cell is initially empty.



## Output format

Your program should print a line containing an integer representing the color of the stone that will be placed in the cell (N,N):



- 0 if it's white,
- 1 if it's black.



### Examples used for testing:



Entrance         |			Output	

6                |		1

0 0 1 0 0 0      |

1 9 9 9 9 9      |

0 9 9 9 9 9      |

0 9 9 9 9 9      |

1 9 9 9 9 9      |

1 9 9 9 9 9      |



Entrance          |			Output	

4                 |		1

0 0 1 0           |

1 9 9 9           |

0 9 9 9           |

0 9 9 9           |



Entrance         |			Output	

4                |		0

0 0 1 0          |

0 9 9 9          |

1 9 9 9          |

1 9 9 9          |



Entrance        |			Output	

2     		    |		0

0 1     		|

1 9     		|