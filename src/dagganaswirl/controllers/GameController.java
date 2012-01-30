/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.controllers;

import dagganaswirl.views.GameView;
import dagganaswirl.models.*;
import dagganaswirl.models.GameBoard.Size;
import dagganaswirl.models.Selection.ActionType;
import java.util.Observable;
import java.util.Observer;

public class GameController {
	private GameView gameView;
        private Game game = null;

	public GameController() {
		this.gameView = new GameView(this);
		gameView.setLocationRelativeTo(null);
		gameView.setVisible(true);
	}

	public GameView getView() {
		return gameView;
	}

	public void setView(GameView view) {
		this.gameView = view;
	}

	public void startGame() {
		System.out.println("starting new game");
                game = Game.playGame(Game.Difficulty.EASY, Game.Gamemode.TIMEATTACK, Size.SMALL);
                game.observeClock(new GameClockObserver());
                System.out.println(game.getBoard());
                game.doAction(new Coordinate(0,0), new Coordinate(3,3), ActionType.SHUFFLE);
                System.out.println(game.getBoard());
	}

	public void exitGame() {
		System.exit(0);
	}

	public void showHighScores() {
		System.out.println("I'm so high, duuuuude!");
        }
        
        private class GameClockObserver implements Observer {

            @Override
            public void update(Observable o, Object o1) {

                //System.out.println("Rmaining seconds: " + o1);
            }
            
        }
}
