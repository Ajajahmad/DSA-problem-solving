struct Node {
    string data;
    struct Node * next, *back;
    Node(string str){
        data = str;
        next = NULL;
        back = NULL;
    }
};
class BrowserHistory {
public:
    Node *tabs , *pointer;
    
    BrowserHistory(string homepage) {
        tabs= new Node(homepage);
        pointer = tabs;
    }
    
    void visit(string url) {
        Node *unusedUrl = pointer->next;
        while(unusedUrl!=NULL)
        {
            Node *a = unusedUrl;
            unusedUrl = unusedUrl->next;
            delete(a);
        }
        Node *temp = new Node(url);
        pointer->next  = temp;
        temp->back = pointer;
        pointer = temp;
    }
    
    string back(int steps) {
        while(pointer->back!=NULL && steps!=0)
        {
            pointer = pointer->back;
            steps--;
        }
        return pointer->data;
    }
    
    string forward(int steps) {
        while(pointer->next!=NULL && steps!=0)
        {
            pointer = pointer->next;
            steps--;
        }
        return pointer->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */