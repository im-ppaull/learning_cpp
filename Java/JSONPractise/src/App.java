import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class App {
    public static void main(String[] args) {
        File file = new File("Java/JSONPractise/src/persons.json");

        JSONPerson jesse = new JSONPerson("Jesse", 2);
        
        Gson gson = new GsonBuilder()
                        .setPrettyPrinting()
                        .create();

        String json = gson.toJson(jesse);
        
        try {
            if (!file.exists()) {
                file.createNewFile();
            }

            try (FileWriter writer = new FileWriter(file)) {
                writer.write(json);
            }
            
            System.out.println("JSON file saved.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class JSONPerson {
    protected String name;
    private int year;

    public JSONPerson(String name, int year) {
        this.name = name;
        this.year = year;
    }
}