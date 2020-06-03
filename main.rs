// Given five positive integers, find the minimum and maximum values that can be
// calculated summing exactly four of the five integers
fn min_max_sum(a: Vec<i32>) {
    let mut min = 0, max = 0;

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

// When a fruit falls from its tree, it lands d units of distance from its tree of origin along the x-axis.
// A negative value of d means the fruit fell d units to the tree's left
// and a positive value of means it falls units to the tree's right.
// Given the value of d for m apples and n oranges
// determine how many apples and oranges will be in the inclusive range [s, t].
fn apples_oranges(apples: Vec<i32>, oranges: Vec<i32>, s: i32, t: i32, a: i32, b: i32) {}

fn main() {
	let arg = "07:05:45PM";
	println!("{} -> {}", arg, time_conversion(arg));
}
