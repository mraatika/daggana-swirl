package dagganaswirl.views;

import dagganaswirl.controllers.GameController;
import java.awt.BorderLayout;
import java.awt.Color;
import javax.swing.*;
/**
 *
 * @author mraatika
 */
public class GameView extends JFrame {
	GameController controller;

	public GameView(GameController controller) {
		this.controller = controller;

		setTitle("Daggana-Swirl");
		setDefaultLookAndFeelDecorated(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);

		setSize(600, 600);
		setLayout(new BorderLayout(0, 0));

		PanelWithImage logoPanel = new PanelWithImage();
		logoPanel.setImage("res/dsw.jpg");
		add(logoPanel, BorderLayout.PAGE_START);


		OptionsView optionsView = new OptionsView(this.controller);
		add(optionsView, BorderLayout.CENTER);

		Toolbar toolbar = new Toolbar(this.controller);
		add(toolbar, BorderLayout.PAGE_END);
	}

	public GameController getController() {
		return this.controller;
	}

	public void setController(GameController controller) {
		this.controller = controller;
	}
}
