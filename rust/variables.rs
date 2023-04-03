fn main() {
    let _age:i8 = 19;
    let float = 0.1;
    let ch = 'c';
    let mut _name:&str = "John";
    const SECOND_NAME:&str = "Doe";
    let _third_name:&str = "Wong";
    _name = "Lazy";
    println!("Hi! {} {} {}", _name, SECOND_NAME, _third_name);

    let name = String::from("Wong");
    let _third_name: &str = &name;
    println!("The value of _third_name is: {}", _third_name);

    let name2 = String::from("Lee");
    let _third_name: &str = &name2;
    println!("The value of _third_name is: {}", _third_name);

}