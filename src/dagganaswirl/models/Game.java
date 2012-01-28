/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.models;

import dagganaswirl.models.GameBoard.Size;

/**
 *
 * @author c1mmo ja Mitukka
 */
public class Game {
    
    public enum Difficulty { 
        EASY(4), 
        MEDIUM(5), 
        HARD(6); 
        
        private int value;
        Difficulty(int value) { this.value = value; }
        
        public int value() { return value; }
    }
    
    public static enum Gamemode { TIMEATTACK, JOTAIN }
    
    private static Difficulty difficulty;
    private Gamemode mode;
    private GameBoard.Size boardSize;
    private static Game game = null;
    private ScoreCounter scounter;
    private static boolean gameOn;

    private Game(Difficulty difficulty, Gamemode mode, Size boardSize) {
        this.difficulty = difficulty;
        this.mode = mode;
        this.boardSize = boardSize;
    }

    private void init() {
        scounter = new ScoreCounter();
    }
    public static Difficulty getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(Difficulty difficulty) {
        this.difficulty = difficulty;
    }

    public Size getBoardSize() {
        return boardSize;
    }

    public void setBoardSize(Size boardSize) {
        this.boardSize = boardSize;
    }

    public Gamemode getMode() {
        return mode;
    }

    public void setMode(Gamemode mode) {
        this.mode = mode;
    }
    
    public static Game playGame(Difficulty difficulty, Gamemode mode, Size boardSize) {
        if (game != null)
            return game;
        else {
            game = new Game(difficulty, mode, boardSize);
            game.init();
            return game;
        }
    }
}
