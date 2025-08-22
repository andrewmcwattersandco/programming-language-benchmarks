const NRECORDS: usize = 8_388_608;

#[allow(dead_code)]
struct Record {
    id: i32,
}

fn main() {
    let mut records = Vec::with_capacity(NRECORDS);
    
    for i in 0..NRECORDS {
        let r = Record { id: i as i32 };
        records.push(r);
    }
}
