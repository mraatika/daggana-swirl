/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.controllers;

import dagganaswirl.views.GameView;

public class GameController {
	private GameView gameView;

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
	}

	public void exitGame() {
		System.exit(0);
	}

	public void showHighScores() {
		System.out.println("I'm so high, duuuuude!");
	}
}
