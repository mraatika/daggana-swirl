/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.models;

import dagganaswirl.models.GameBoard.Size;
import java.util.Observable;
import java.util.Timer;
import java.util.TimerTask;

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
    
    public static enum Gamemode { TIMEATTACK, LIMITEDMOVES }
    
    private static Difficulty difficulty;
    private Gamemode mode;
    private GameBoard board = null;
    private GameBoard.Size boardSize;
    private static Game game = null;
    private ScoreCounter scounter;
    private GameClock gameClock = null;
    private int moves = 0;

    private Game(Difficulty difficulty, Gamemode mode, Size boardSize) {
        Game.difficulty = difficulty;
        this.mode = mode;
        this.boardSize = boardSize;
    }

    private void init() {
        board = new GameBoard(boardSize);      
        scounter = new ScoreCounter();
  
        switch (mode) {
            case TIMEATTACK: {
                gameClock = new GameClock(difficulty);
                gameClock.start();
                break;
            }
            default : break;
        }
    }
    public static Difficulty getDifficulty() {
        return difficulty;
    }

    public void setDifficulty(Difficulty difficulty) {
        Game.difficulty = difficulty;
    }

    public Size getBoardSize() {
        return boardSize;
    }

    public void setBoardSize(Size boardSize) {
        this.boardSize = boardSize;
    }

    public int getMoves() {
        return moves;
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
    
    public void observeClock(java.util.Observer obs) {
        gameClock.addObserver(obs);
    }
    
    public void doAction(Coordinate topLeft, Coordinate bottomRight, Selection.ActionType type) {
        int[][] selectedPieces = new int[bottomRight.x-topLeft.x][bottomRight.y-topLeft.y];
        for (int i=0; i<(bottomRight.x-topLeft.x); i++)
            for (int j=0; j<(bottomRight.y-topLeft.y); j++)
                selectedPieces[i][j] = board.getPiece(topLeft.x+i,topLeft.y+j);
        Selection sel = new Selection(selectedPieces);
        sel.doAction(type);
        for (int i=0; i<(bottomRight.x-topLeft.x); i++)
            for (int j=0; j<(bottomRight.y-topLeft.y); j++)
                board.setPiece(new Coordinate(topLeft.x+i,topLeft.y+j), sel.get(topLeft.x+i, topLeft.y+j));
        moves++;
    }
    /**
     * TODO: Nothing here yet.
     */
    private class ScoreCounter {
        
    }
    
    private class GameClock extends Observable {
        
        private int remainingTime;
        private Timer timer;
        
        public GameClock(Game.Difficulty difficulty) {
            remainingTime = 1000 - (difficulty.value() * 100);
            timer = new Timer();      
        }
        
        public void start(){
            timer.schedule(new Ticker(), 0);
        }
        
        private class Ticker extends TimerTask {

            @Override
            public void run() {
                try {
                    while (remainingTime > 0) {
                        remainingTime--;
                        setChanged();
                        notifyObservers(remainingTime);
                        Thread.sleep(1000);
                    }
                }
                catch (InterruptedException ex) {}
            }
            
        }
        
    }
}
