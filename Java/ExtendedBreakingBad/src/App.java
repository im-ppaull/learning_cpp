import java.util.ArrayList;
import java.util.Arrays;

public class App {
    public static void main(String[] args) throws Exception {
        Professor walter = new Professor("Walter");

        Student jesse = new Student("Jesse", new ArrayList<>());
        Student walterjr = new Student("Walter Jr", new ArrayList<>(Arrays.asList(1, 3, 2)));

        Course chemistry = new Course("Chemistry", walter, new ArrayList<>());

        chemistry.addStudent(jesse);
        chemistry.addStudent(walterjr);

        walter.addGrade(jesse, 4);

        chemistry.introduceSelf();
    }
}
