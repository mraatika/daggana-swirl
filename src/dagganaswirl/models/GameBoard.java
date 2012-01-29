package dagganaswirl.models;

import java.util.Random;

public class GameBoard {
    
    public enum Size { 
        SMALL(10), 
        MEDIUM(15), 
        LARGE(20); 
        
        private int value;
        Size(int value) { this.value = value; }
        
        public int value() { return value; }
    }
    
    private Size size;
    private int[][] board;
    private int rows;
    private Random rnd;

    public GameBoard(Size size) {
        this.size = size;
        
        board = new int[size.value()][size.value()];
        
        for (int i=0; i< rows; i++)
            for (int j=0; i<rows; j++)
                board[i][j] = rnd.nextInt(Game.getDifficulty().value());
    }  

    public Size getSize() {
        return size;
    }

    public void setSize(Size size) {
        this.size = size;
    }
    
    public int getPiece(Coordinate c) {
        return board[c.x][c.y];
    }
    
    public int getPiece(int row, int col) {
        return board[row][col];
    }
    
    public void setPiece(Coordinate c, int value) {
        board[c.x][c.y] = value;
    }

}
