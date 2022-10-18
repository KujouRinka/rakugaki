// MLE code
use std::io::Read;

fn main() {
  let mut args = String::new();
  std::io::stdin().read_line(&mut args).unwrap();
  let args: Vec<_> = args.trim().split_ascii_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();
  let (range, query_cnt) = (args[0], args[1]);
  let mut sifter = Vec::with_capacity(range - 1);
  (2..=range).for_each(|x| { sifter.push(x) });
  let mut cur_primer_pos = 0;
  while cur_primer_pos < sifter.len() {
    let MOD = sifter[cur_primer_pos];
    let mut new_sifter: Vec<_> = sifter.iter()
      .take(cur_primer_pos + 1)
      .chain(
        sifter.iter()
          .skip(cur_primer_pos + 1)
          .filter(|x| **x % MOD != 0)
      )
      .map(|x| *x)
      .collect();
    std::mem::swap(&mut sifter, &mut new_sifter);
    cur_primer_pos += 1;
  }

  let mut query = String::new();
  std::io::stdin().read_to_string(&mut query).unwrap();
  let query: Vec<_> = query.trim().split_ascii_whitespace().map(|x| x.parse::<usize>().unwrap()).collect();
  query.into_iter().for_each(|x| {
    println!("{}", sifter[x - 1]);
  })
}

