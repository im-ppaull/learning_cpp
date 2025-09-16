

public class App {
    public static void main(String[] args) throws Exception {
        // Professor
        Professor walter = new Professor("Walter", "chemistry");

        walter.introduceSelf();
        walter.grade("my paper");

        // Student
        Student jesse = new Student("Jesse", 2);

        jesse.introduceSelf();
        jesse.setYear(3);
        jesse.introduceSelf();
    }
}
