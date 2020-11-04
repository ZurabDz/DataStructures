#include <fmt/format.h> // TODO: BLOAT WITH IOSTREAM ??
#include <new>          // new is only for educational purpuses

template <typename T> class SingleLinkedList {
private:
  struct Node {
    T elem;
    Node *next;
  };

public:
  // Can be used variadic template with just for syntax sugare
  SingleLinkedList() noexcept : head(nullptr){};
  ~SingleLinkedList() noexcept {
    while (!empty())
      removeFront();
  }

  [[nodiscard]] bool empty() const noexcept { return head == nullptr; }
  [[nodiscard]] T const &front() const noexcept { return head->elem; }

  void removeElement(T const &e) noexcept;
  void addFront(T const &e) noexcept;
  void removeFront() noexcept;
  void traverse() const noexcept;

private:
  Node *head;
};

template <typename T>
void SingleLinkedList<T>::removeElement(const T &e) noexcept {
  Node *del_ptr = head;

  if (head->elem == e) {
    head = head->next;
    delete del_ptr;
    return;
  }

  Node *predacessor;

  while (del_ptr != nullptr) {
    predacessor = del_ptr;
    del_ptr = del_ptr->next;
    if (del_ptr->elem == e) {
      predacessor->next = del_ptr->next;
      delete del_ptr;
      break;
    }
  }
}

template <typename T> void SingleLinkedList<T>::addFront(T const &e) noexcept {
  Node *v = new (std::nothrow) Node;
  v->elem = e;
  v->next = head;
  head = v;
}

template <typename T> void SingleLinkedList<T>::removeFront() noexcept {
  Node *old = head;
  head = old->next;
  // fmt::print("{} Deleted... \n", head->elem);
  delete old;
}

template <typename T> void SingleLinkedList<T>::traverse() const noexcept {
  Node *ptr = head;
  while (ptr != nullptr) {
    fmt::print("{}\n", ptr->elem);
    ptr = ptr->next;
  }
}