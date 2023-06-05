fn solution(a : u8, b : u8) -> u8 {
    a + b
}

fn main() {
    let mut test_case = String::new();
    std::io::stdin().read_line(&mut test_case).unwrap();

    let test_case : i32 = test_case.trim().parse().unwrap();

    for i in 0..test_case {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut iter = input.trim().split_whitespace();
        let a : u8 = iter.next().unwrap().parse().unwrap();
        let b : u8 = iter.next().unwrap().parse().unwrap();

        println!("Case #{}: {} + {} = {}", i+1,a,b,solution(a,b));
    }
}   