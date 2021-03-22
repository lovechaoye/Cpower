typedef LinkedList Stack;

void initializeStack(Stack* stack){
	initializeStack(stack);
}

void push(Stack* stack,void* data){
	addHead(stack,data);
}

void* pop(Stack* stack){
	void* data;
	Node* tmp = stack->head;
	if(stack->head == NULL){
		return NULL;
	}else if(stack->head == stack->tail){
		stack->head = stack->tail = NULL;
		data = tmp->data;
		free(tmp);
		return data;
	}else{
		stack->head = tmp->next;
		data  = tmp->data;
		free(tmp);
		return data;
	}
}
