import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter your firstname: ");
        String firstname = scanner.nextLine();

        System.out.println("Enter your lastname: ");
        String lastname = scanner.nextLine();

        System.out.println("Hello " + firstname + " " + lastname + ".");

        scanner.close();
    }
}