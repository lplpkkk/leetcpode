typedef struct node{
    char* url;
    struct node* prev;
    struct node* next;
}node;

typedef struct {
    node* current;
} BrowserHistory;


BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* this_history=malloc(sizeof(BrowserHistory));
    this_history->current=malloc(sizeof(node));
    this_history->current->url=strdup(homepage);
    this_history->current->prev=NULL;
    this_history->current->next=NULL;

    return this_history;
}


void free_forward(node* start){
    while(start){
        node* tmp=start->next;
        free(start->url);
        free(start);
        start=tmp;
    }
    return;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    if(obj->current->next){
        free_forward(obj->current->next);
        obj->current->next=NULL;
    }

    node* new_node=malloc(sizeof(node));
    new_node->url=strdup(url);
    new_node->prev=obj->current;
    new_node->next=NULL;
    obj->current->next=new_node;
    obj->current=obj->current->next;
    return;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while(steps && obj->current->prev){
        obj->current=obj->current->prev;
        steps--;
    }
    return obj->current->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while(steps && obj->current->next){
        obj->current=obj->current->next;
        steps--;
    }
    return obj->current->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    node* cur=obj->current;
    while(cur&&cur->prev){
        cur=cur->prev;
    }
    free_forward(cur);
    free(obj);
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/
