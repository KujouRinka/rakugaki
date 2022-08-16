struct OrderedStream {
  ptr: usize,
  cache: Vec<Option<String>>,
}

impl OrderedStream {

  fn new(k: i32) -> Self {
    OrderedStream {
      ptr: 1,
      cache: vec![None; (k + 1) as usize],
    }
  }

  fn insert(&mut self, id_key: i32, value: String) -> Vec<String> {
    let mut ret = Vec::new();
    if let Some(v) = self.cache.get_mut(id_key as usize) {
      *v = Some(value);
    }
    while self.ptr < self.cache.len() {
      if let Some(v) = self.cache.get_mut(self.ptr as usize) {
        if let Some(s) = v.take() {
          ret.push(s);
        } else {
          break;
        }
      }
      self.ptr += 1;
    }
    ret
  }
}

