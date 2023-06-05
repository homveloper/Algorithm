fn solution(nums : Vec<u16>, x : u16) -> Vec<u16> {
    nums.iter().filter(|&num| *num < x).cloned().collect()
}

fn main() {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input).unwrap();

    let mut iter = input.trim().split_whitespace();
    let n : u16 = iter.next().unwrap().parse().unwrap();
    let x : u16 = iter.next().unwrap().parse().unwrap();

    let nums : Vec<u16> = {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        input.trim().split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect()
    };

    println!("{}", solution(nums, x).iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" "));
}