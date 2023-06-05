use std::fmt::Write;

fn solution(a : u16 , b : u16) -> u16 {
    a + b
}

fn main() {
    let mut test_case = String::new();
    std::io::stdin().read_line(&mut test_case).unwrap();
    let test_case : i32 = test_case.trim().parse().unwrap();

    let mut output = String::new();

    for _ in 0..test_case {

        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut iter = input.trim().split_whitespace();
        let a : u16 = iter.next().unwrap().parse().unwrap();
        let b : u16 = iter.next().unwrap().parse().unwrap();

        writeln!(&mut output, "{}", solution(a,b)).unwrap();
    }

    print!("{}", output);
}