fn solution(n : i32) -> String {
    let mut answer = String::new();

    let n = n / 4;

    for _ in 0..n {
        answer.push_str("long ");
    }

    answer.push_str("int");

    answer
}

fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let n : i32 = n.trim().parse().unwrap();

    println!("{}", solution(n));
}