public class Z3 {
    public static void main(String[] args) {

        int drawnNumber = 0;
        int[] drawnNumbers = new int[7];

        for (int i = 0; i < 7; i++) {

            drawnNumber = (int) (Math.random() * (40 - 1) + 1);

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
        for (int i = 0; i < 7; i++) {
            System.out.printf("%d ", drawnNumbers[i]);
        }
    }
}
