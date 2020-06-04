use std::collections::HashMap;

// Given five positive integers, find the minimum and maximum values that can be
// calculated summing exactly four of the five integers
fn min_max_sum(a: &mut Vec<i32>) {
	let mut min = 0;
	let mut max = 0;

    a.sort_unstable();

    for i in 0..a.len()-1 { min += a[i]; } 
    for i in 1..a.len() { max += a[i]; } 
}

// Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
fn time_conversion(s: &str) -> String {
	if s.ends_with("AM") {
		if s.starts_with("12") {
			let mut str_hours = "00".to_string();
			str_hours.push_str(s.get(2..s.len()-2).unwrap());
			return str_hours;
		} else {
			return s.get(0..s.len()-2).unwrap().to_string();
		}
	} else {
		if s.starts_with("12") {
			return s.get(0..s.len()-2).unwrap().to_string();
		} else {
			let mut hours = s.get(0..2).unwrap().parse::<u8>().unwrap();
			hours += 12;
			let mut str_hours = hours.to_string();
			str_hours.push_str(s.get(2..s.len()-2).unwrap());
			str_hours
		}
	}
}

fn bon_appetit(bill: Vec<i32>, k: i32, b: i32) {
	let mut total_sum = 0;
	let mut sum_k = 0;

	for i in bill {
		total_sum += i;
		if i != k { sum_k += i; }	
	}

	if sum_k / 2 == b { println!("bon app"); }
	else { println!("{}", (total_sum / 2) - (sum_k / 2)); }
}

// Sam's house has an apple tree and an orange tree.
// His house starts at point s, and ends at point t.
// The apple tree is to the left of his house, and the orange tree is to its right.
// The apple tree is at point a, and the orange tree is at point b.
// When a fruit falls from its tree, it lands d units of distance from its tree of origin along the x-axis.
// A negative value of d means the fruit fell d units to the tree's left
// and a positive value of means it falls units to the tree's right.
// Given the value of d for m apples and n oranges
// determine how many apples and oranges will be in the inclusive range [s, t].
fn apples_oranges(apples: Vec<i32>, oranges: Vec<i32>, s: i32, t: i32, a: i32, b: i32) {
	let mut count_apples = 0;
	let mut count_oranges = 0;
	
	for d in apples {
		if d + a >= s && d + a <= t { count_apples += 1; }
	}

	for d in oranges {
		if d + b <= t && d + b >= s { count_oranges += 1; }
	}

	println!("apples : {}\noranges : {}", count_apples, count_oranges);
}

// You will be given two arrays of integers and asked to determine
// all integers that satisfy the following two conditions:
// - The elements of the first array are all factors of the integer being considered
// - The integer being considered is a factor of all elements of the second array
// You must determine how many such numbers exist.
fn get_total_x(mut a: Vec<i32>, mut b: Vec<i32>) -> u16 {
	let mut count = 0;

	a.sort_unstable();
	b.sort_unstable();

	let mut x = a[a.len()-1];

	while x <= b[0] {
		let mut ok = false;

		for i in &a {
			if x % *i == 0 {
				ok = true;
			} else {
				ok = false;
				break;
			}
		}
		if ok {
			for i in &b {
				if *i % x == 0 {
					ok = true;
				} else {
					ok = false;
					break;
				}
			}
		}

		if ok { count += 1; }
		x += 1;
	}

	count
}

// Given an array of integers, return indices of the two numbers such that they add up to
// a specific target.
fn two_sum(a: Vec<i32>, target: i32) -> Option<(usize, usize)> {
	let mut map = HashMap::new();

	for i in 0..a.len() {
		let compl = target - a[i];

		if map.contains_key(&compl) {
			return Some((*map.get(&compl).unwrap(), i));
		}

		map.insert(a[i], i);
	}

	None
}

fn main() {
	// let arg = "07:05:45PM";
	// println!("{} -> {}", arg, time_conversion(arg));

	// let apples = vec![-2, 2, 1];
	// let oranges = vec![5, -6];
	// apples_oranges(apples, oranges, 7, 11, 5, 15);

	// let mut a = vec![2, 4];
	// let mut b = vec![16, 32, 96];
	// println!("{}", get_total_x(a, b));

	// let a = vec![2, 7, 11, 15];
	// println!("{:?}", two_sum(a, 9).unwrap());
}
