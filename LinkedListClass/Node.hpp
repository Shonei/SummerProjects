template <class T1, class T2>
class Node
{
    public:
        Node(const T1& d, const T2& k)
        { value = d; key = k; };
        ~Node();
        T1 value;
        T2 key;            
};