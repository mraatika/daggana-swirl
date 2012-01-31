/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.models;

import dagganaswirl.models.GameBoard.Size;
import java.util.Observable;
import java.util.Timer;
import java.util.TimerTask;
import java.util.ArrayList;

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
    private ScoreCounter scoreCounter;
    private GameClock gameClock = null;
    private int moves = 0;

    private Game(Difficulty difficulty, Gamemode mode, Size boardSize) {
        Game.difficulty = difficulty;
        this.mode = mode;
        this.boardSize = boardSize;
    }

    private void init() {
        board = new GameBoard(boardSize);      
        scoreCounter = new ScoreCounter();
  
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

    public GameBoard getBoard() {
        return board;
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
    
    public void observeScoreCounter(java.util.Observer obs) {
        scoreCounter.addObserver(obs);
    }
    
    public void doAction(int topLeftRow, int topLeftCol, int bottomRightRow, int bottomRightCol, Selection.ActionType type) {
        int[][] selectedPieces = new int[bottomRightRow-topLeftRow][bottomRightCol-topLeftCol];
        for (int i=0; i<(selectedPieces.length); i++)
            for (int j=0; j<(selectedPieces.length); j++)
                selectedPieces[i][j] = board.getPiece(topLeftRow+i,topLeftCol+j);
        Selection sel = new Selection(selectedPieces);
        sel.doAction(type);
        for (int i=0; i<(selectedPieces.length); i++)
            for (int j=0; j<(selectedPieces.length); j++)
                board.setPiece(topLeftRow+i, topLeftCol+j, sel.get(i, j));
        scoreCounter.countScore();
        moves++;
    }
    
    private class ScoreCounter extends Observable {

        private long score = 0;
        ArrayList<CoordinateList> pieceTypeLists;
        private int[] debug;
        private int groupSize;
        
        public ScoreCounter() {
            pieceTypeLists = new ArrayList<CoordinateList>();
            for (int i=0; i<difficulty.value(); i++)
                pieceTypeLists.add(new CoordinateList());
        }
        
        public long getScore() {
            return score;
        }
        
        public void countScore() {
            
            for (int i=0; i<boardSize.value(); i++)
                for (int j=0; j<boardSize.value(); j++)
                {
                    int pieceType = board.getPiece(i, j);
                    pieceTypeLists.get(pieceType).add(new Coordinate(i, j));
                }
                    
            for (CoordinateList l : pieceTypeLists)
                for (Coordinate c : l)
                    if (!c.getChecked()) {    
                        groupSize = 1;
                        checkCoordinate(c, board.getPiece(c.i, c.j));
                        if (groupSize > 3)
                            score += groupSize * groupSize;
                    }
                                 
            setChanged();
            notifyObservers(score);
            
            for (ArrayList<Coordinate> a : pieceTypeLists)
                a.clear();
            score = 0;
        }
        
        private void checkCoordinate(Coordinate coord, int pieceType) {
            
            coord.setChecked();
            
            int leftSideIndex = pieceTypeLists.get(pieceType).contains(coord.i, coord.j-1);
            if (leftSideIndex != -1 && !pieceTypeLists.get(pieceType).get(leftSideIndex).getChecked()) {
                groupSize++;
                checkCoordinate(pieceTypeLists.get(pieceType).get(leftSideIndex), pieceType);
            }
            int topSideIndex = pieceTypeLists.get(pieceType).contains(coord.i-1, coord.j);
            if (topSideIndex != -1 && !pieceTypeLists.get(pieceType).get(topSideIndex).getChecked()) {
                groupSize++;
                checkCoordinate(pieceTypeLists.get(pieceType).get(topSideIndex), pieceType);
            } 
            int rightSideIndex = pieceTypeLists.get(pieceType).contains(coord.i, coord.j+1);
            if (rightSideIndex != -1 && !pieceTypeLists.get(pieceType).get(rightSideIndex).getChecked()) {
                groupSize++;
                checkCoordinate(pieceTypeLists.get(pieceType).get(rightSideIndex), pieceType);
            }
            int bottomSideIndex = pieceTypeLists.get(pieceType).contains(coord.i+1, coord.j);
            if (bottomSideIndex != -1 && !pieceTypeLists.get(pieceType).get(bottomSideIndex).getChecked()) {
                groupSize++;
                checkCoordinate(pieceTypeLists.get(pieceType).get(bottomSideIndex), pieceType);
            }   
        }
        
        private class Coordinate {
            
            public int i,j;
            private boolean checked = false;

            public Coordinate(int i, int j) {
                this.i = i;
                this.j = j;
            }
            
            public synchronized boolean getChecked() {
                return checked;
            }
            public synchronized void setChecked() {
                checked = true;
            }
        }
        
        private class CoordinateList extends ArrayList<Coordinate> {
            
            public int contains(int i, int j) {
                for (int k=0; k<this.size(); k++)
                    if (this.get(k).i == i && this.get(k).j == j)
                        return k;
                return -1;
            }
        }
        
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
