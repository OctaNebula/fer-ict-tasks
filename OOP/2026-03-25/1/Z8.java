import java.util.Scanner;

public class Z8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // input the string
        String result = "";

        while (true) {

            String current = scanner.nextLine();

            if (current.equalsIgnoreCase("quit")) { // if its quit, quit
                break;
            }

            current = current.trim(); // trim the string
            if (current.isEmpty()) { // if its empty, skip
                continue;
            }
            String currentwords[] = current.split("\\s+"); // convert the string into an array of strings

            String chosenWord = currentwords[(int) (Math.random() * currentwords.length)];

            result += chosenWord + " ";
        }
        System.out.printf("%s", result);
    }
}
