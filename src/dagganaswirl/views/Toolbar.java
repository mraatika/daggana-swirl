package dagganaswirl.views;

import dagganaswirl.controllers.GameController;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JPanel;

/**
 *
 * @author mraatika
 */
public class Toolbar extends JPanel {
	GameController controller;
	JButton newGameButton;
	JButton exitButton;
	JButton highScoresButton;

	public Toolbar(GameController controller) {
		this.controller = controller;
		setLayout(new FlowLayout(FlowLayout.CENTER, 15	, 10));
		setBackground(Color.BLACK);

		createNewGameButton();
		createHighScoresButton();
		createExitButton();
	}

	private void createNewGameButton() {
		newGameButton = new JButton("New Game");
		newGameButton.addActionListener(new NewGameListener(this.controller));
		add(newGameButton);
	}

	private void createHighScoresButton() {
		highScoresButton = new JButton("Highscores");
		highScoresButton.addActionListener(new HighScoresButtonListener(this.controller));
		add(highScoresButton);
	}

	private void createExitButton() {
		exitButton = new JButton("Exit Game");
		exitButton.addActionListener(new ExitListener(this.controller));
		add(exitButton);
	}

	class NewGameListener implements ActionListener {
		private final GameController controller;

		public NewGameListener(GameController controller) {
			this.controller = controller;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			this.controller.startGame();
		}
	}

	class HighScoresButtonListener implements ActionListener {
		private final GameController controller;

		public HighScoresButtonListener(GameController controller) {
			this.controller = controller;
		}

		@Override
		public void actionPerformed(ActionEvent e) {
			this.controller.showHighScores();
		}
	}

	class ExitListener implements ActionListener {
		private final GameController controller;

		public ExitListener(GameController controller) {
			this.controller = controller;
		}
		@Override
		public void actionPerformed(ActionEvent e) {
			this.controller.exitGame();
		}
	}

	public void setController(GameController controller) {
		this.controller = controller;
	}
}
