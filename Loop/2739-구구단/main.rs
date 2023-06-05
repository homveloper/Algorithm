fn solution(n : i32) {

    const START : i32 = 1;
    const END : i32 = 10;

    for i in START..END {
        println!("{} * {} = {}", n, i, n * i);
    }
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let input : i32 = input.trim().parse().unwrap();

    solution(input);
}