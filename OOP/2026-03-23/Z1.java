public class Z1 {
    public static void main(String[] args) {
        double pi = 0;
        int factor = 10;

        for (int j = 1; j < 7; j++) {
            factor = (int) Math.pow(factor, j);

            for (int i = 0; i < factor; i++) {
                pi += Math.pow(-1, i) / (2 * i + 1); // YES I'M AWARE THIS IS EXPENSIVE BUT MY CPU IS STRONG
            }

            pi = 4 * pi;
            System.out.printf("Factor = %d: %.10f\n", factor, pi);
            pi = 0;

            factor = 10;
        }
    }

}