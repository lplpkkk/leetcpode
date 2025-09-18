use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct Task {
    priority: i32,
    task_id: i32,
}

impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        self.priority.cmp(&other.priority)
            .then_with(|| self.task_id.cmp(&other.task_id))
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct TaskManager {
    task_info: HashMap<i32, (i32, i32)>,
    heap: BinaryHeap<Task>,
}

impl TaskManager {
    fn new(tasks: Vec<Vec<i32>>) -> Self {
        let mut task_info = HashMap::new();
        let mut heap = BinaryHeap::new();
        
        for task in tasks {
            let user_id = task[0];
            let task_id = task[1];
            let priority = task[2];
            
            task_info.insert(task_id, (priority, user_id));
            heap.push(Task { priority, task_id });
        }
        
        Self { task_info, heap }
    }
    
    fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {
        self.task_info.insert(task_id, (priority, user_id));
        self.heap.push(Task { priority, task_id });
    }
    
    fn edit(&mut self, task_id: i32, new_priority: i32) {
        if let Some(info) = self.task_info.get_mut(&task_id) {
            info.0 = new_priority;
            self.heap.push(Task { priority: new_priority, task_id });
        }
    }
    
    fn rmv(&mut self, task_id: i32) {
        self.task_info.remove(&task_id);
    }
    
    fn exec_top(&mut self) -> i32 {
        while let Some(task) = self.heap.pop() {
            if let Some(&(priority, user_id)) = self.task_info.get(&task.task_id) {
                if priority == task.priority {
                    self.task_info.remove(&task.task_id);
                    return user_id;
                }
            }
        }
        -1
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * let obj = TaskManager::new(tasks);
 * obj.add(userId, taskId, priority);
 * obj.edit(taskId, newPriority);
 * obj.rmv(taskId);
 * let ret_4: i32 = obj.exec_top();
 */

/*
solution from gemini -->

use std::collections::{BinaryHeap, HashMap};
use std::cmp::Ordering;

// Task 結構體，包含所有必要資訊
#[derive(Debug, Eq, PartialEq, Clone)]
struct Task {
    priority: i32,
    task_id: i32,
    user_id: i32,
}

// 為 BinaryHeap 實現自定義排序，使其成為最大堆
// 優先級高的排在前面；如果優先級相同，task_id 高的排在前面
impl Ord for Task {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.priority != other.priority {
            // 比較優先級，降序排列
            self.priority.cmp(&other.priority)
        } else {
            // 如果優先級相同，比較 task_id，降序排列
            self.task_id.cmp(&other.task_id)
        }
    }
}

impl PartialOrd for Task {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

// ---

struct TaskManager {
    tasks: BinaryHeap<Task>,
    // HashMap 儲存 task_id 到 (user_id, priority) 的映射，作為真實狀態的來源
    task_map: HashMap<i32, (i32, i32)>,
}

impl TaskManager {
    // 構造函式
    pub fn new(tasks: Vec<Vec<i32>>) -> Self {
        let mut manager = Self {
            tasks: BinaryHeap::new(),
            task_map: HashMap::new(),
        };
        for task_data in tasks {
            manager.add(task_data[0], task_data[1], task_data[2]);
        }
        manager
    }

    // 新增任務
    pub fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {
        if self.task_map.get(&task_id).is_none() {
            self.task_map.insert(task_id, (user_id, priority));
            self.tasks.push(Task {
                priority,
                task_id,
                user_id,
            });
        }
    }

    // 編輯任務
    pub fn edit(&mut self, task_id: i32, new_priority: i32) {
        if let Some(entry) = self.task_map.get_mut(&task_id) {
            // 更新哈希表中的優先級
            entry.1 = new_priority;
            // 由於無法直接更新堆，我們推入一個新的任務
            self.tasks.push(Task {
                priority: new_priority,
                task_id,
                user_id: entry.0,
            });
        }
    }

    // 移除任務
    pub fn rmv(&mut self, task_id: i32) {
        // 惰性移除，只從哈希表中刪除
        self.task_map.remove(&task_id);
    }

    // 執行最高優先級的任務
    pub fn exec_top(&mut self) -> i32 {
        while let Some(task) = self.tasks.pop() {
            if let Some(&(user_id, priority)) = self.task_map.get(&task.task_id) {
                // 檢查任務是否有效且優先級匹配
                if priority == task.priority {
                    self.task_map.remove(&task.task_id);
                    return user_id;
                }
            }
        }
        -1
    }
}
*/

/*
struct TaskManager {

}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TaskManager {

    fn new(tasks: Vec<Vec<i32>>) -> Self {
        
    }
    
    fn add(&self, user_id: i32, task_id: i32, priority: i32) {
        
    }
    
    fn edit(&self, task_id: i32, new_priority: i32) {
        
    }
    
    fn rmv(&self, task_id: i32) {
        
    }
    
    fn exec_top(&self) -> i32 {
        
    }
}
*/

/**
 * Your TaskManager object will be instantiated and called as such:
 * let obj = TaskManager::new(tasks);
 * obj.add(userId, taskId, priority);
 * obj.edit(taskId, newPriority);
 * obj.rmv(taskId);
 * let ret_4: i32 = obj.exec_top();
 */
