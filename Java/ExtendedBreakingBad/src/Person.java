import java.util.ArrayList;

public class Person {
    protected String name;
    
    public Person(String name) {
        this.name = name;
    }
}

class Student extends Person {
    private ArrayList<Integer> grades;

    public Student(String name, ArrayList<Integer> grades) {
        super(name);
        this.grades = grades;
    }

    public void addGrade(int grade) {
        this.grades.add(grade);
    }

    public double getAverageGrade() {
        if (grades.isEmpty())
            return 0.0;
        
        int sum = 0;
        for (int grade : grades) 
            sum += grade;
        
        return (double) sum / grades.size();
    }
}

class Professor extends Person {
    public Professor(String name) {
        super(name);
    }

    public void addGrade(Student student, int grade) {
        if (grade < 1 || grade > 5)
            return;

        student.addGrade(grade);
    }
}

class Course {
    private String label;
    private Professor professor;
    private ArrayList<Student> students;

    public Course(String label, Professor professor, ArrayList<Student> students) {
        this.label = label;
        this.professor = professor;
        this.students = students;
    }

    public void addStudent(Student student) {
        students.add(student);
    }

    public void introduceSelf() {
        System.out.printf(
            "Hi! Welcome to %s Course. I'm %s and I'll be your teacher.\n", label, professor.name
        );

        System.out.println("\nWe have here:");

        for (Student student : students) {
            System.out.println(
                student.name + " with his " + student.getAverageGrade() + " average grade."
            );
        }
    }
}