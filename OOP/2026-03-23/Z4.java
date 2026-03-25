import lotto.LottoGenerator;
import java.util.Scanner;

public class Z4 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.printf("Enter total balls and balls to draw > ");

        while (true) {
            int total = scanner.nextInt();
            int drawCount = scanner.nextInt();

            if (drawCount > total) {
                break;
            }

            int[] balls = LottoGenerator.drawUsingMathRandom(total, drawCount);
            System.out.println("Draw: " + java.util.Arrays.toString(balls));

        }

    }
}
