Available Captures for Queen

On an 8x8 chessboard, there is exactly one black queen and some number of white pieces. The algebraic notation of chess pieces is presented with the following:
'K' for king
'Q' for queen
'R' for rook
'B' for bishop
'N' for knight
'P' for pawn
'.' for empty square

When the queen moves, it chooses one of eight cardinal and diagnonal directions: up, down, left, right, upper-left, upper-right, lower-left, and lower-right. From an origin square, the queen might sweep through the line towards the chosen direction, until it captures a piece or reaches the chess board border then stops. The number of available captures for the queen is the number of the chess pieces it can captures. Now it is the turn for this black queen to capture, and she has to capture, what are the available captures for queen?

INPUT

The first line is an integer number N representing how many chess board setups, 1 <= N <= 10.

Each chess board setup is represented by an one-liner string of space seperated tokens:
The first token is the coordinate of the black queen with two connected alphanumeric characters;
The second token is an integer number of how many tokens following in the rest of the line.
The white pieces are notated with three connected alphanumeric characters, where the first character for a chess piece and the second and the third are for a chess board coordinate.

The chess board coordinates are notated as the following: the horizontal rows or ranks are in the range from '1' to '8'. The vertical columns or files are in the range from 'a' to 'h'.

OUTPUT

The chess board setup(s) with the maximum available captures for the queen. If there is a tie, output all setups in their lexicographical order seperated with a space.


