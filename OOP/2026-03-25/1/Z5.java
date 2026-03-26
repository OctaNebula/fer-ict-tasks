public class Z5 {
    public static void main(String[] args) {
        int lenght = args.length;
        if (lenght != 3) {
            System.out.printf("Program needs arguments for a, b, and c in ax^2 + bx = c\n");
            return;
        }

        double a = Double.parseDouble(args[0]);
        double b = Double.parseDouble(args[1]);
        double c = Double.parseDouble(args[2]);

        double discriminant = Math.pow(b, 2) - 4 * a * c;
        if (discriminant < 0) {
            System.out.printf("No solution available in R\n");
            return;
        }
        if (discriminant == 0) {
            double solution = -b / (2 * a);
            System.out.printf("One solution: %.2f\n", solution);
            return;
        }
        if (discriminant > 0) {
            double solution1 = (-b - Math.sqrt(discriminant)) / (2 * a);
            double solution2 = (-b + Math.sqrt(discriminant)) / (2 * a);
            System.out.printf("Two solutions: %.2f and %.2f\n", solution1, solution2);
            return;
        }
    }
}