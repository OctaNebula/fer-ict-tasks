import java.util.Scanner;

public class Z6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.printf("Enter a, b, c > ");
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double c = scanner.nextDouble();

        double discriminant = Math.pow(b, 2) - 4 * a * c; // shamelessly stolen from Z5.java
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
