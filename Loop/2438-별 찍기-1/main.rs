fn solution(n : u8) -> String {
    let mut answer = String::new();

    for i in 0..n {
        for _ in 0..i+1 {
            answer.push_str("*");
        }
        answer.push_str("\n");
    }

    answer
}

fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let n : u8 = n.trim().parse().unwrap();

    println!("{}", solution(n));
}