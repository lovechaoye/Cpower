void initializeList(LinkedList* list){
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

//头插法
void addHead(LinkedList* list,void* data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if(list->head == NULL){
		list->tail = node;
		node->head = node;
	}else{
		node->next = list->head;
	}
	list->head = node;
}

//尾插法
void addTail(LinkedList* list,void* data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if(list->head == NULL){
		list->head = node;

	}else{
		list->tail->next = node;
	}
	list->tail = node;
}

Node* getNode(LinkedList *list,COMPARE compare, void* data){
	Node* node = list->head;
	while(node != NULL){
		if(compare(node->data,data) == 0){
			return node;
		}else{
			node = node->next;
		}
	}
	return NULL;

}


void delete(LinkedList *list,Node* node){
	if(node == list->head){
		if(list->head->next == NULL){
			list->head = list->tail = NULL;
		}else{
			list->head = list->head = list->head->next;	
		}	
	}else{
		Node* tmp = list->head;
		while(tmp != NULL && tmp->next != node){
			tmp = tmp->next;
		}
		if(tmp != NULL){
			tmp->next = node->next;
		}
	}
	free(node);
}
	
void displayLinkedList(LinkedList* list,DISPLAY display){
	printf("\nLinked list\n");
	Node* current = list->head;
	while(current != NULL){
		display(current->data);
		current = current->next;
	}
}
