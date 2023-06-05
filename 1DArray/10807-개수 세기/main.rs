fn solution(nums : Vec<i8>, value : i8) -> u8{
    let mut count : u8 = 0;

    for num in nums {
        if num == value {
            count += 1;
        }
    }

    count
}

fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let n : u8 = n.trim().parse().unwrap();

    let nums : Vec<i8> = {
        let mut nums = String::new();
        std::io::stdin().read_line(&mut nums).unwrap();
        nums.split_whitespace().map(|s| s.parse().unwrap()).collect()
    };

    let value : i8 = {
        let mut value = String::new();
        std::io::stdin().read_line(&mut value).unwrap();
        value.trim().parse().unwrap()
    };

    println!("{}", solution(nums, value));
}