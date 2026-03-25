public class Z2 {
    public static void main(String[] args) {
        double pi = 0;
        int i = 1;

        do {
            pi += 1.0 / Math.pow(i, 2);
            i++;
            // System.out.printf("Current pi: %.12f\n", Math.sqrt(pi * 6));
        } while ((int) (Math.sqrt(pi * 6) * 100000) != 314159);

        System.out.printf("We need %d sumands\n", i - 1);
    }
}
