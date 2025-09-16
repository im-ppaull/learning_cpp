import java.lang.Math;

public class Person {
    protected String name;

    public Person(String name) {
        this.name = name;
    }
}

class Professor extends Person {
    private String teaches;

    public Professor(String name, String teaches) {
        super(name);
        this.teaches = teaches;
    }

    public void introduceSelf() {
        System.out.printf(
            "My name is %s, and I will be your %s professor.\n", this.name, this.teaches
        );
    }

    public int grade(String paper) {
        int grade = (int)(Math.random() * 4) + 1;
        return grade;
    }
}

class Student extends Person {
    private int year;

    public Student(String name, int year) {
        super(name);
        this.year = year;
    }

    public void introduceSelf() {
        System.out.printf(
            "Hi! I'm %s, and I'm in year %s.\n", this.name, this.year
        );
    }

    public void setYear(int year) {
        this.year = year;
    }
}