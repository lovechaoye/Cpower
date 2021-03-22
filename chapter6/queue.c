typedef LinkedList Queue;

void initializeQueue(Queue* queue){
	initializeList(queue);
}

void enqueue(Queue* queue,void* node){
	addHead(queue,node);
}

void *dequeue(Queue *queue){
	Node* tmp = queue->head;
	void* data;
	if(queue->head == NULL){
		data = NULL;
	} else if(queue->head == queue->tail){
		queue->head = queue->tail = NULL;
		data = tmp->data;
		free(tmp);
	}else{
		while(tmp->next != queue->tail){
			tmp = tmp->next;
		}
		queue->tail = tmp;
		tmp = tmp->next;
		data = tmp->data;
		free(tmp);
	}
	return data;
}
