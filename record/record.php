<?php

class Record {
    public $id;
    
    public function __construct($id) {
        $this->id = $id;
    }
}

$records = array();

for ($i = 0; $i < 67108864; $i++) {
    $record = new Record($i);
    $records[$i] = $record;
}

?>
