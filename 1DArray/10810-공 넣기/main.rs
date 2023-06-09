fn solution(n : u8, input : Vec<(u8, u8,u8)>) -> Vec<u8> {
    let mut answer = vec![0; n as usize];

    for (i, j, k) in input.iter() {
        for index in *i..*j+1 {
            answer[(index as usize) - 1] = *k;
        }
    }

    answer
}

fn main() {
    let (n, m) = {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        let mut iter = input.split_whitespace();
        let n: u8 = iter.next().unwrap().parse().unwrap();
        let m: u8 = iter.next().unwrap().parse().unwrap();
        (n, m)
    };

    let input : Vec<(u8, u8, u8)> = {
        let mut array = Vec::new();

        for _ in 0..m {
            let mut input = String::new();
            std::io::stdin().read_line(&mut input).unwrap();
            let mut iter = input.split_whitespace();
            let i: u8 = iter.next().unwrap().parse().unwrap();
            let j: u8 = iter.next().unwrap().parse().unwrap();
            let k: u8 = iter.next().unwrap().parse().unwrap();
            array.push((i, j, k));
        }

        array
    };

    let answer = solution(n, input);
    println!("{}", answer.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" "));
}