const NORMAL: u8 = 0;
const SLASH: u8 = 1;
const BLOCK_COMMENT: u8 = 2;
const BLOCK_COMMENT_STAR: u8 = 3;

impl Solution {
  pub fn remove_comments(source: Vec<String>) -> Vec<String> {
    let mut state = NORMAL;
    let mut output = Vec::new();
    source.into_iter()
      .for_each(|s| {
        let mut s_to_push = if state == BLOCK_COMMENT && !output.is_empty() {
          output.pop().unwrap()
        } else {
          String::new()
        };
        for (i, &ch) in s.as_bytes().into_iter().enumerate() {
          match state {
            NORMAL => {
              if ch == b'/' && i != s.len() - 1 {
                state = SLASH;
                continue;
              }
              s_to_push.push(ch as char)
            }
            SLASH => {
              if ch == b'/' {
                state = NORMAL;
                break;
              } else if ch == b'*' {
                state = BLOCK_COMMENT;
              } else {
                s_to_push.push(s.as_bytes()[i - 1] as char);
                s_to_push.push(s.as_bytes()[i] as char);
                state = NORMAL;
              }
            }
            BLOCK_COMMENT => {
              if ch == b'*' {
                state = BLOCK_COMMENT_STAR;
              }
            }
            BLOCK_COMMENT_STAR => {
              if ch == b'/' {
                state = NORMAL;
              } else if ch != b'*' {
                state = BLOCK_COMMENT;
              }
            }
            _ => unreachable!()
          }
        }
        if !s_to_push.is_empty() {
          output.push(s_to_push);
        }
      });
    output
  }
}

