template<typename T>
class MyCircularQueueHelper {
 public:
  MyCircularQueueHelper(int k)
      : _v(k), _front(0),
        _back(0), _size(0), _cap(k) {}

  bool enQueue(T value) {
    if (isFull())
      return false;
    _v[_back] = std::move(value);
    _back = (_back + 1) % _cap;
    ++_size;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    _front = (_front + 1) % _cap;
    --_size;
    return true;
  }

  T &Front() {
    return _v[_front];
  }

  T &Rear() {
    auto i = _back;
    if (_back == 0)
      i = _cap - 1;
    else
      i = _back - 1;
    return _v[i];
  }

  bool isEmpty() {
    return _size == 0;
  }

  bool isFull() {
    return _size == _cap;
  }

 private:
  vector<T> _v;
  typename vector<T>::size_type _front;
  typename vector<T>::size_type _back;
  typename vector<T>::size_type _size;
  typename vector<T>::size_type _cap;
};

class MyCircularQueue {
 public:
  MyCircularQueue(int k) : _q(k) {}

  bool enQueue(int value) {
    return _q.enQueue(value);
  }

  bool deQueue() {
    return _q.deQueue();
  }

  int Front() {
    if (isEmpty())
      return -1;
    return _q.Front();
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return _q.Rear();
  }

  bool isEmpty() {
    return _q.isEmpty();
  }

  bool isFull() {
    return _q.isFull();
  }

 private:
  MyCircularQueueHelper<int> _q;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

