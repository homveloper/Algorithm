
fn solution(need_pieces : & Vec<i8>, current_pieces : & Vec<i8>) -> Vec<i8> {
    let mut result = Vec::new();
    for i in 0..6 {
        result.push(need_pieces[i] - current_pieces[i]);
    }
    result
}

fn main() {
    let need_pieces : Vec<i8> = vec![1, 1, 2, 2, 2, 8];
    let input_pieces : Vec<i8> = {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();
        input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect()
    };

    let answer = solution(& need_pieces, & input_pieces).clone();
    let answer = answer.iter().map(|x| x.to_string()).collect::<Vec<String>>().join(" ");
    println!("{}", answer);
}