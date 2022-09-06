fn main() {
  let mut op1 = String::new();
  std::io::stdin().read_line(&mut op1).unwrap();
  let lhs = op1.trim();
  let mut op2 = String::new();
  std::io::stdin().read_line(&mut op2).unwrap();
  let rhs = op2.trim().clone();

  let itovec = |x: &str| {
    let v = x.chars().rev().map(|x| x as u8 - '0' as u8).collect::<Vec<_>>();
    v
  };
  let lhs = itovec(lhs);
  let rhs = itovec(rhs);
  let mut ret = Vec::with_capacity(std::cmp::max(lhs.len(), rhs.len()) + 1);
  let mut carry = 0;
  ret = if lhs.len() < rhs.len() {
    lhs.iter().chain(std::iter::repeat(&0)).zip(rhs.iter())
  } else {
    rhs.iter().chain(std::iter::repeat(&0)).zip(lhs.iter())
  }
    .map(|(l, r)| {
      let v = l + r + carry;
      carry = v / 10;
      v % 10
    })
    .collect::<Vec<_>>();
  if carry == 1 {
    ret.push(1);
  }
  let print_val = ret
    .iter()
    .rev()
    .fold(String::with_capacity(ret.len()), |mut acc, x| {
      acc.push((*x + '0' as u8) as char);
      acc
    });
  println!("{}", print_val);
}

