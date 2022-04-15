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
        records = new Record[112813858];

        for (int i = 0; i < records.length; i++) {
            Record r = new Record();

            r.setId(i);
            records[i] = r;
        }
    }
}
