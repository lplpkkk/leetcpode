#if(1)
/*
 *	struct Iterator {
 *		// Returns true if the iteration has more elements.
 *		bool (*hasNext)();
 *
 * 		// Returns the next element in the iteration.
 *		int (*next)();
 *	};
 */

struct PeekingIterator {
    struct Iterator *iterator;
    bool hasPeeked;
    int next_val;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    if(!obj->hasPeeked){
        if(obj->iterator->hasNext()){
            obj->next_val=obj->iterator->next();
            obj->hasPeeked=true;
        }
    }
    return obj->next_val;
}

int next(struct PeekingIterator* obj) {
    int cur_val;

    if(obj->hasPeeked){
        cur_val=obj->next_val;
        obj->hasPeeked=false;
    }else{
        cur_val=obj->iterator->next();
    }
    return cur_val;
}

bool hasNext(struct PeekingIterator* obj) {
    return obj->hasPeeked || obj->iterator->hasNext();
}

void peekingIteratorFree(struct PeekingIterator* obj){
    free(obj);
}
/**
 * Your PeekingIterator struct will be instantiated and called as such:
 * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
 * int param_1 = peek(obj);
 * int param_2 = next(obj);
 * bool param_3 = hasNext(obj);
 * peekingIteratorFree(obj);
*/
#endif


#if(0)
struct PeekingIterator {
    struct Iterator *iterator;
    bool hasPeeked; // 標記是否已經偷看過
    int next_val;   // 緩存偷看的值
};

// 構造函數
struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false; // 初始狀態為未偷看
    return piter;
}

// 偷看下一個元素
int peek(struct PeekingIterator* obj) {
    if (!obj->hasPeeked) {
        // 如果還沒有偷看過，就去從底層迭代器取下一個值
        // 這裡需要先檢查底層迭代器是否還有元素，不過在 peek 的呼叫環境下通常可以假設有
        // 為了安全起見，這裡可以加上一個判斷，但題目設計通常不會在沒有元素時呼叫 peek
        if (obj->iterator->hasNext()) {
            obj->next_val = obj->iterator->next();
            obj->hasPeeked = true; // 標記為已偷看
        }
    }
    return obj->next_val;
}

// 返回下一個元素
int next(struct PeekingIterator* obj) {
    // 1. 儲存當前要返回的值
    int cur_val;

    // 2. 判斷值從哪裡來
    if (obj->hasPeeked) {
        // 如果已經偷看過，就返回偷看的值
        cur_val = obj->next_val;
        obj->hasPeeked = false; // 重設標記，表示下次需要重新偷看
    } else {
        // 如果還沒偷看過，就直接從底層迭代器取值
        // 這裡同樣假設有元素，或者在外部的 hasNext 判斷後才呼叫
        cur_val = obj->iterator->next();
    }
    
    return cur_val;
}

// 判斷是否還有下一個元素
bool hasNext(struct PeekingIterator* obj) {
    // 只要「偷看過」或「底層迭代器還有元素」，就表示有下一個
    return obj->hasPeeked || obj->iterator->hasNext();
}

// 釋放記憶體
void peekingIteratorFree(struct PeekingIterator* obj) {
    free(obj);
}
#endif
