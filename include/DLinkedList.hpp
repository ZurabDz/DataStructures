template <typename T> class DLinkedList {
private:
  struct DNode {
    T elem;
    DNode *next{nullptr};
    DNode *prev{nullptr};
  };

public:
  DLinkedList();
  ~DLinkedList();

  T const &front() const noexcept { return head->next->elem; }
  T const &back() const noexcept { return tail->prev->elem; }

  void addFront(T const &e) {add(head->next, e);}
  void addBack(T const &e) {add(tail, e);}

  void removeFront() { if (!empty()) remove(head->next);}
  void removeBack() {if (!empty()) remove(tail->prev);}

  [[nodiscard]] bool empty() const noexcept { return head->next == tail; }
  // TODO: delete == operator or implement it

private:
  DNode *head;
  DNode *tail;

protected:
  // clang diagnostic curses for static usages or taking into other namspace
  void add(DNode *v, T const &e);
  void remove(DNode *v);
};

template <typename T> void DLinkedList<T>::add(DNode *v, T const &e) {
  DNode *u = new DNode;
  u->elem = e;

  u->next = v;
  u->prev = v->prev;
  u->prev->next = u;
  v->prev = u;
}

template <typename T> void DLinkedList<T>::remove(DNode *v) {
  DNode *u = v->prev;
  DNode *w = v->next;
  u->next = w;
  w->prev = u;
  delete v;
}


template <typename T> DLinkedList<T>::DLinkedList() {
  head = new DNode();
  tail = new DNode();
  head->next = tail;
  tail->prev = head;
}

template <typename T> DLinkedList<T>::~DLinkedList<T>() {
  while (!empty()) {
    removeFront();
  }
  delete head;
  delete tail;
}