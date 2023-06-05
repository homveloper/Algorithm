fn solution(n : i32) -> i32 {
    let mut sum = 0;
    for i in 1..n+1 {
        sum += i;
    }
    sum
}

fn main () {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();
    let input : i32 = input.trim().parse().unwrap();

    println!("{}", solution(input));
}