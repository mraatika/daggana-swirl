/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.views;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.imageio.ImageIO;
import javax.swing.JPanel;

class PanelWithImage extends JPanel {
	private BufferedImage image;

	public void setImage(String imageUrl) {
		try {
			this.image = ImageIO.read(new File(imageUrl));
		} catch (IOException ex) {
			Logger.getLogger(PanelWithImage.class.getName()).log(Level.SEVERE, null, ex);
		}

		this.setPreferredSize(new Dimension(image.getWidth(), image.getHeight()));
	}

	@Override
	public void paintComponent(Graphics g) {
		g.drawImage(image, 0, 0, null);
	}
}
