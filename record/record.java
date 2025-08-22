class Record {

    int id;

    void setId(int i) {
        id = i;
    }
}

/**
 * The RecordApp class implements an application that
 * creates objects.
 */
class RecordApp {
    static Record[] records;

    public static void main(String[] args) {
        try {
            records = new Record[16777216];

            for (int i = 0; i < records.length; i++) {
                Record r = new Record();

                r.setId(i);
                records[i] = r;
            }
        } catch (OutOfMemoryError e) {
            System.err.println("record: out of memory: " + e.getMessage());
            System.exit(1);
        }
    }
}
