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

fn reverse(mut x: i32) -> i32 {
	let mut rev = 0;

	while x != 0 {
		let pop = x % 10; // get the last digit of the number
		x /= 10; // go to the next digit
		rev = rev * 10 + pop; // add the digit to the begining of the new number
	}

	rev
}

fn main() {
	let arg = "07:05:45PM";
	println!("{} -> {}", arg, time_conversion(arg));
}
