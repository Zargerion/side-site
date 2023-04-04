use std::io;
use std::fs::File;

pub struct Input {

}

impl Input {
    pub fn read_line() -> String {
        let mut name = String::new();
        io::stdin()
            .read_line(&mut name)
            .expect("Не удалось прочитать строку");
        name.trim().to_string()

    }
}
pub struct FileReader {

}

impl FileReader {
    pub fn read_txt_file(file_path: String) -> String {
        let file = File::open(file_path).expect("Не удалось открыть файл");
        let reader = io::BufReader::new(file);
        let mut s = String::new();

        for line in io::BufRead::lines(reader) {
           s += &line.unwrap();
        }

        s
    } 

}