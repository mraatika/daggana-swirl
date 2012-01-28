/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.views;

import dagganaswirl.controllers.GameController;
import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.ButtonGroup;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

/**
 *
 * @author mraatika
 */
public class OptionsView extends JPanel {
	private final GameController controller;

	public OptionsView(GameController controller) {
		this.controller = controller;

		/**
		 * @todo select a layout manager
		 */

		setBackground(Color.RED);

		JLabel diffLbl = new JLabel("Difficulty");
		add(diffLbl);
		JRadioButton diffBtnHard = new JRadioButton("Hard");
		JRadioButton diffBtnMedium = new JRadioButton("Normal");
		JRadioButton diffBtnEasy = new JRadioButton("Easy");

		ButtonGroup btnGroup = new ButtonGroup();
		btnGroup.add(diffBtnHard);
		btnGroup.add(diffBtnMedium);
		btnGroup.add(diffBtnEasy);

		add(diffBtnHard);
		add(diffBtnMedium);
		add(diffBtnEasy);
	}
}
