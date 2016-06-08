template <class T1, class T2>
class Node
{
    public:
        Node(const T1& d, const T2& k);
        ~Node();
        void changeValue(const T1& newValue);
        Node<T1, T2> operator== (const Node<T1, T2>&);
        T1 getValue();
        T2 getKey();
        void remove();
        void addBefore(Node<T1, T2>);
        void addAfter(Node<T1, T2>);
    private:
        T1 value;
        T2 key;  
        Node<T1, T2>* next;
        Node<T1, T2>* prev;          
};