fn solution(total_price : i32, products : Vec<(i32, i32)>) -> String {

    let mut sum = 0;

    for (price, count) in products {
        sum += price * count;
    }

    let answer = 
        if total_price == sum {
            String::from("Yes")
        } else {
            String::from("No")
        };

    answer
}

fn main() {
    let mut total_price = String::new();
    std::io::stdin().read_line(&mut total_price).unwrap();
    let total_price : i32 = total_price.trim().parse().unwrap();

    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let n : i32 = n.trim().parse().unwrap();

    let mut products : Vec<(i32, i32)> = Vec::new();

    for _ in 0..n {
        let mut input = String::new();
        std::io::stdin().read_line(&mut input).unwrap();

        let mut iter = input.trim().split_whitespace();
        let price : i32 = iter.next().unwrap().parse().unwrap();
        let count : i32 = iter.next().unwrap().parse().unwrap();

        products.push((price, count));
    }

    println!("{}", solution(total_price, products) );
}