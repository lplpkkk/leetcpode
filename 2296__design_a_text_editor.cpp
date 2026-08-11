class TextEditor {
private:
    struct ListNode{
        char c;
        ListNode* next;
        ListNode* prev;

        ListNode(char thisnode): c(thisnode),next(nullptr),prev(nullptr){};
    };

    ListNode* cursor;
    ListNode* head;

public:
    TextEditor() {
        
        head=new ListNode('#');
        cursor=head;
    }
    
    void addText(string text) {
        
        for(char c:text){
            ListNode* node= new ListNode(c);

            node->next=cursor->next;
            node->prev=cursor;

            if(cursor->next){
                cursor->next->prev=node;
            }
            
            cursor->next=node;

            cursor=node;
        }

    }
    
    int deleteText(int k) {
        int del_char=0;

        while(k>0&&cursor!=head){
            ListNode*  del=cursor;

            cursor->prev->next=cursor->next;

            if(cursor->next){
                cursor->next->prev=cursor->prev;
            }

            cursor=cursor->prev;

            delete del;
            del_char++;
            k--;
        }

        return del_char;
    }
    
    string cursorLeft(int k) {
        
        while(k>0 &&cursor!=head){
            cursor=cursor->prev;
            k--;
        }

        string ans;
        ListNode* cur=cursor;

        for(int i=0;i<10&&cur!=head;i++){
            ans.push_back(cur->c);
            cur=cur->prev;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
    
    string cursorRight(int k) {
        while(k>0 &&cursor->next!=nullptr){
            cursor=cursor->next;
            k--;
        }

        string ans;
        ListNode* cur=cursor;

        for(int i=0;i<10&&cur!=head;i++){
            ans.push_back(cur->c);
            cur=cur->prev;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
