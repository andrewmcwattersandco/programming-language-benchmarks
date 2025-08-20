import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Iterator;
import java.util.stream.Stream;

/**
 * The JsonApp class implements an application that
 * parses JSON.
 */
class JsonApp {
    public static void main(String[] args) throws IOException {
        String dir = "jsonexamples";

        try (Stream<Path> files = Files.list(Paths.get(dir))) {
            ObjectMapper mapper = new ObjectMapper(); // create once, reuse

            for (Iterator<Path> it = files.iterator(); it.hasNext(); ) {
                Path name = it.next();

                if (!name.toString().endsWith(".json")) continue;

                byte[] bytes = Files.readAllBytes(name);

                mapper.readTree(bytes);
            }
        }
    }
}
