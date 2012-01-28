/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dagganaswirl.models;

import dagganaswirl.models.Selection.ActionType;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author mraatika
 */
public class SelectionTest {
	
	private int[][] generateList(int rowSize) {
		int[][] list = new int[rowSize][rowSize];

		for (int i = 0; i < rowSize; i++) {
			for (int j = 0; j < rowSize; j++) {
				list[i][j] = j + (i * rowSize) + 1;
			}
		}

		return list;
	}

	private void checkList(int[][] expected, Selection actual) {

		assertEquals(expected[0].length, actual.size());

		for (int i = 0; i < expected.length; i++) {
			for (int j = 0; j < expected[0].length; j++) {
				assertEquals(expected[i][j], actual.get(i, j));
			}
		}
	}

	@BeforeClass
	public static void setUpClass() throws Exception {
	}

	@AfterClass
	public static void tearDownClass() throws Exception {
	}

	@Before
	public void setUp() {
	}

	@After
	public void tearDown() {
	}

	@Test
	public void testHorizontalMirroring3x3() {
		int[][] sl = generateList(3);
		Selection s = new Selection(sl);

		int[][] exp = {
			{3,2,1},
			{6,5,4},
			{9,8,7}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_HORIZONTALLY));

		System.out.println("HORIZ3x3:\n" + s.toString());
	}

	@Test
	public void testHorizontalMirroring4x4() {
		int[][] sl = generateList(4);
		Selection s = new Selection(sl);

		int[][] exp = {
			{4,3,2,1},
			{8,7,6,5},
			{12,11,10,9}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_HORIZONTALLY));

		System.out.println("HORIZ4x4:\n" + s.toString());
	}

	@Test
	public void testVertMirroring3x3() {
		int[][] sl = generateList(3);
		Selection s = new Selection(sl);

		int[][] exp = {
			{7,8,9},
			{4,5,6},
			{1,2,3}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_VERTICALLY));

		System.out.println("VERT3x3:\n" + s.toString());
	}

	@Test
	public void testVertMirroring4x4() {
		int[][] sl = generateList(4);
		Selection s = new Selection(sl);

		int[][] exp = {
			{13,14,15,16},
			{9,10,11,12},
			{5,6,7,8},
			{1,2,3,4}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_VERTICALLY));

		System.out.println("VERT4x4:\n" + s.toString());
	}

	@Test
	public void testMirrorBoth3x3() {
		int[][] sl = generateList(3);
		Selection s = new Selection(sl);

		int[][] exp = {
			{9,8,7},
			{6,5,4},
			{3,2,1}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_BOTH));

		System.out.println("BOTH3x3:\n" + s.toString());
	}


	@Test
	public void testMirrorBoth4x4() {
		int[][] sl = generateList(4);
		Selection s = new Selection(sl);

		int[][] exp = {
			{16,15,14,13},
			{12,11,10,9},
			{8,7,6,5,4},
			{4,3,2,1}
		};

		checkList(exp, s.doAction(ActionType.MIRROR_BOTH));

		System.out.println("BOTH4x4:\n" + s.toString());
	}

	@Test
	public void testTurnClockwise3x3() {
		int[][] sl = generateList(3);

		int[][] exp = {
			{7,4,1},
			{8,5,2},
			{9,6,3}
		};

		Selection s = new Selection(sl);
		s = s.doAction(ActionType.CLOCKWISE);

		System.out.println(s.toString());

		checkList(exp, s);
	}

	@Test
	public void testTurnClockwise4x4() {
		int[][] sl = generateList(4);

		int[][] exp = {
			{13,9,5,1},
			{14,10,6,2},
			{15,11,7,3},
			{16,12,8,4}
		};

		Selection s = new Selection(sl);
		s = s.doAction(ActionType.CLOCKWISE);

		System.out.println(s.toString());

		checkList(exp, s);
	}

	@Test
	public void testTurnCClockWise3x3() {
		int[][] sl = generateList(3);

		int[][] exp = {
			{3,6,9},
			{2,5,8},
			{1,4,7}
		};

		Selection s = new Selection(sl);
		s = s.doAction(ActionType.CCLOCKWISE);

		System.out.println(s.toString());

		checkList(exp, s);
	}

	@Test
	public void testTurnCClockWise4x4() {
		int[][] sl = generateList(4);

		int[][] exp = {
			{4,8,12,16},
			{3,7,11,15},
			{2,6,10,14},
			{1,5,9,13}
		};

		Selection s = new Selection(sl);
		s = s.doAction(ActionType.CCLOCKWISE);

		System.out.println(s.toString());

		checkList(exp, s);
	}

	@Test
	public void testRowSizeCountEmptySelection() {
		int[][] sl = new int[0][0];
		Selection s = new Selection(sl);

		assertEquals(0, s.rowSize());
	}

	@Test
	public void testRowSizeCount3x3() {
		int[][] sl = generateList(3);
		Selection s = new Selection(sl);

		assertEquals(3, s.rowSize());
	}

	@Test
	public void testRowSizeCount10x10() {
		int[][] sl = generateList(10);
		Selection s = new Selection(sl);

		assertEquals(10, s.rowSize());
	}
}
