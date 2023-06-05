fn solution(a : u8 , b : u8) -> u8 {
    a + b
}

fn main() {

    loop {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut iter = input.trim().split_whitespace();

        if iter.clone().count() == 0 {
            break;
        }

        let a : u8 = iter.next().unwrap().parse().unwrap();
        let b : u8 = iter.next().unwrap().parse().unwrap();

        println!("{}", solution(a,b));
    }
}