package dagganaswirl.models;

import java.util.Random;

public class Selection {
    
        private Random rnd;
        
	public static enum ActionType {
		CCLOCKWISE, CLOCKWISE, MIRROR_HORIZONTALLY, MIRROR_VERTICALLY, MIRROR_BOTH, SHUFFLE
	}

	private int[][] container;

	public Selection(int[][] selection) {
		this.container = selection;
	}

	public int size() {
		return this.container.length;
	}

	public int rowSize() {
		return (this.container.length != 0) ? this.container[0].length : 0;
	}

	public int get(int row, int col) {
		return this.container[row][col];
	}

	/**
	 *
	 * @param enum
	 *            action type to be done to selection
	 * @return List<Integer> Selection New selection
	 */
	public Selection doAction(ActionType type) {

		switch (type) {
		case CCLOCKWISE:
			this.turnCClockWise();
			return this;
		case CLOCKWISE:
			this.turnClockWise();
			return this;
		case MIRROR_HORIZONTALLY:
			this.mirrorHorizontally();
			return this;
		case MIRROR_VERTICALLY:
			this.mirrorVertically();
			return this;
		case MIRROR_BOTH:
			this.mirrorHorizontally();
			this.mirrorVertically();
			return this;
		case SHUFFLE:
			// this.shuffle();
			return this;
		default:
			throw new IllegalArgumentException("Invalid action type!");
		}
	}

	private void turnCClockWise() {
		int rowSize = this.rowSize();
		int [][] newArray = new int[rowSize][rowSize];

		for (int i = (rowSize - 1); i >= 0; --i) {
			for (int j = 0; j < rowSize; ++j) {
		    	newArray[(rowSize - 1) - j][i] = this.container[i][j];
		    }
		}
		this.container = newArray;
	}

	private void turnClockWise() {
		int rowSize = this.rowSize();
		int [][] newArray = new int[rowSize][rowSize];

		for (int i = (rowSize - 1); i >= 0; --i) {
			for (int j = 0; j < rowSize; ++j) {
		    	newArray[j][(rowSize - 1)- i] = this.container[i][j];
		    }
		}

		this.container = newArray;
	}

	private void mirrorHorizontally() {
		int rowSize = this.rowSize();
		int half = (int) Math.floor(rowSize / 2);

		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < half; j++) {
				this.swap(i, i, j, rowSize - (j + 1));
			}
		}
	}

	private void mirrorVertically() {
		int rowSize = this.rowSize();
		int half = (int) Math.floor(rowSize / 2);

		for (int i = 0; i < half; i++) {
			for (int j = 0; j < rowSize; j++) {
				this.swap(i, rowSize - (i + 1), j, j);
			}
		}
	}

	private void swap(int startRow, int endRow, int startCol, int endCol) {
		int temp = this.container[startRow][startCol];
		this.container[startRow][startCol] = this.container[endRow][endCol];
		this.container[endRow][endCol] = temp;
	}
        
        private void shuffle() {
                int [][] temp = this.container;
                for (int i=0; i< this.rowSize(); i++)
                    for (int j=0; i<this.rowSize(); j++)
                        this.container[i][j] =  temp[rnd.nextInt(this.rowSize())][rnd.nextInt(this.rowSize())];
        }

	public String toString() {
		String str = "";

		if (this.rowSize() == 0) {
			return "";
		}

		for (int i = 0; i < this.rowSize(); i++) {
			for (int j = 0; j < this.rowSize(); j++) {
				str += " " + this.get(i, j);
			}
			str += "\n";
		}
		return str;
	}

}
