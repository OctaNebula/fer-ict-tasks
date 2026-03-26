public class Z7 {
    public static void main(String[] args) {
        double initial = Double.parseDouble(args[0]);
        double interestRate = Double.parseDouble(args[1]);
        int years = Integer.parseInt(args[2]);

        for (int i = 1; i < years + 1; i++) {
            double capital = initial + initial * interestRate * i;
            System.out.printf("Year %d; %.2f\n", i, capital);
        }
    }
}
