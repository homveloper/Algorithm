fn solution(nums : Vec<i32>) -> (i32, i32) {
    (nums.iter().min().unwrap().clone(), nums.iter().max().unwrap().clone())
}

fn main() {
    let n : i32 = {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().parse().unwrap()
    };

    let nums : Vec<i32> = {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect()
    };

    let (min, max) = solution(nums);

    println!("{} {}",min, max);
}