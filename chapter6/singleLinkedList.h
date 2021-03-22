typedef void(*DISPLAY)(void*);

typedef int(*COMPARE)(void*,void*);


// node 定义一个节点
typedef struct _node{
	void* data;
	struct _node* next;
} Node;

// LinkedList 表示链表，持有指向头结点和尾节点的指针，当前指针用来辅助遍历链表
typedef struct _linkedlist{
	Node* head;
	Node* tail;
	Node* current;
} LinkedList;

// 定义的操作
void initializeList(LinkedList*); // 初始化链表

void addHead(LinkedList*,void*);  // 给链表的头节点添加数据

void addTail(LinkedList*,void*);  // 给链表的尾节点添加数据

void delete(LinkedList*,Node*);   // 从链表删除节点

Node* getNode(LinkedList*,COMPARE,void*);	// 返回包含指定数据的节点指针

void displayLinkedList(LinkedList*,DISPLAY); // 打印链表
