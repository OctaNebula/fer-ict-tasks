package lotto;

import java.util.Random;

public class LottoGenerator {
    public static int[] drawUsingMathRandom(int totalBalls, int ballsToDraw) {
        int drawnNumber = 0;
        int[] drawnNumbers = new int[ballsToDraw];

        for (int i = 0; i < ballsToDraw; i++) {

            drawnNumber = (int) (Math.random() * (totalBalls) + 1);

            boolean isDuplicate = false;
            for (int j = 0; j < i; j++) {
                if (drawnNumbers[j] == drawnNumber) {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate) {
                i--;
                continue;
            }

            drawnNumbers[i] = drawnNumber;
        }

        java.util.Arrays.sort(drawnNumbers);
        return drawnNumbers;
    }

    public static int[] drawUsingRandomClass(int totalBalls, int ballsToDraw) {
        Random rand = new Random();
        int drawnNumber = 0;
        int[] drawnNumbers = new int[ballsToDraw];

        for (int i = 0; i < ballsToDraw; i++) {

            drawnNumber = rand.nextInt(totalBalls) + 1;

            boolean isDuplicate = false;
            for (int j = 0; j < i; j++) {
                if (drawnNumbers[j] == drawnNumber) {
                    isDuplicate = true;
                    break;
                }
            }

            if (isDuplicate) {
                i--;
                continue;
            }

            drawnNumbers[i] = drawnNumber;
        }

        java.util.Arrays.sort(drawnNumbers);
        return drawnNumbers;
    }

}
