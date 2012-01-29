/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.controllers;

import dagganaswirl.views.GameView;
import dagganaswirl.models.Game;
import dagganaswirl.models.GameBoard.Size;
import java.util.Observable;
import java.util.Observer;

public class GameController implements Observer{
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
                game.observeClock(this);
	}

	public void exitGame() {
		System.exit(0);
	}

	public void showHighScores() {
		System.out.println("I'm so high, duuuuude!");
	}

        @Override
        public void update(Observable o, Object o1) {
            System.out.println("Time remaining: " + o1 + " seconds");
        }
}
