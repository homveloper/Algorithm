fn solution(a : i32, b : i32) -> i32{
    a + b
}

fn main () {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let t : i32 = input.trim().parse().unwrap();

    for _ in 0..t {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut iter = input.trim().split_whitespace();
        let a : i32 = iter.next().unwrap().parse().unwrap();
        let b : i32 = iter.next().unwrap().parse().unwrap();

        println!("{}", solution(a, b));
    }
}