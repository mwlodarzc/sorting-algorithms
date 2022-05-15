#ifndef DOUBLY_LINKED_LIST_HH
#define DOUBLY_LINKED_LIST_HH
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T elem;
        Node *next;
        inline static int created = 0;
        inline static int exists = 0;

    public:
        Node()
        {
            created++;
            exists++;
        }
        Node(const T &elem_) : elem{elem_}
        {
            created++;
            exists++;
        }
        Node(const T &elem_, Node &next_) : elem{elem_}, next{&next_}
        {
            created++;
            exists++;
        };
        ~Node() { exists--; }
        static int existing_number() { return exists; }
        static int created_number() { return created; }
    };

private:
    Node *header;

public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const T &front() const;
    void addFront(const T &elem);
    void removeFront();
    void insertion_sort();
};
// // std::cout << first_before_sorted->next->elem << " " << first_before_checked->next->elem << std::endl;

template <typename T>
void LinkedList<T>::insertion_sort()
{
    Node *fb_sorted, *fb_checked, *tmp = NULL;
    addFront(T());
    fb_sorted = header->next;
    if (!empty())
        while (fb_sorted->next != NULL)
        {
            if (fb_sorted->elem > fb_sorted->next->elem)
            {
                fb_checked = header;
                while (fb_checked->next->elem < fb_sorted->next->elem)
                {
                    fb_checked = fb_checked->next;
                }
                tmp = fb_sorted->next;
                fb_sorted->next = tmp->next;
                tmp->next = fb_checked->next;
                fb_checked->next = tmp;
            }
            else
                fb_sorted = fb_sorted->next;
        }
    removeFront();
}
template <typename T>
bool LinkedList<T>::empty() const
{
    if (header == NULL)
        return true;
    return false;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    header = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (!this->empty())
        removeFront();
    delete header;
}

template <typename T>
const T &LinkedList<T>::front() const
{
    if (this->empty())
        throw std::out_of_range("List is empty!");
    return header->elem;
}

template <typename T>
void LinkedList<T>::addFront(const T &elem)
{
    Node *tmp = new Node(elem, *header);
    header = tmp;
}

template <typename T>
void LinkedList<T>::removeFront()
{
    Node *tmp = header;
    header = header->next;
    delete tmp;
}
#endif
