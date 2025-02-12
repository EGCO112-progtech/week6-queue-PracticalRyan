

typedef struct
{
  NodePtr headPtr, tailPtr;
  int size;
} Queue;

void enqueue_struct(Queue *q, int x)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node)
  {
    /*Finish enqueue */
    if (q->size == 0) // First node
    {
      q->headPtr = new_node;
    }
    else
    {
      q->tailPtr->nextPtr = new_node;
    }
    new_node->data = x;
    q->tailPtr = new_node;
  }
  q->size++;
}

int dequeue_struct(Queue *q)
{
  NodePtr t = q->headPtr;
  int value = t->data;
  if (q->size > 0)
  {
    NodePtr t = q->headPtr;
    // Move tail if last node
    q->headPtr = t->nextPtr;
    if (q->size == 1)
    {
      q->tailPtr = NULL;
    }
    free(t);

    q->size--;
    return value;
  }
  printf("Empty queue\n");
  return -1;
}
