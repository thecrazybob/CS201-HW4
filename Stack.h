// Mohammed Sohail
// 22001513

class Stack {

    public:
        Stack();
        Stack(const Stack& aStack);
        ~Stack();

        bool isEmpty() const;
        bool push(string newItem);
        bool pop();
        bool pop(string& stackTop);
        bool getTop(string& stackTop) const;

    private:
        struct StackNode {              // a node on the stack
           string item;                 // a data item on the stack
           StackNode *next;             // pointer to next node
        };

        StackNode *topPtr;              // pointer to first node in the stack

};
