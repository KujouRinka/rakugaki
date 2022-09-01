impl Solution {
  pub fn final_prices(prices: Vec<i32>) -> Vec<i32> {
    let mut st = Vec::with_capacity(prices.len());
    let mut ret = Vec::new();
    ret.resize(prices.len(), 0);
    for i in 0..prices.len() {
      if !match st.last() {
        None => true,
        Some(v) => { prices[*v] < prices[i] }
      } {
        while let Some(ni) = st.last() {
          if prices[*ni] < prices[i] {
            break;
          }
          ret[*ni] = prices[*ni] - prices[i];
          st.pop();
        }
      }
      st.push(i);
    }
    st.into_iter().for_each(|x| {
      ret[x] = prices[x];
    });
    ret
  }
}

