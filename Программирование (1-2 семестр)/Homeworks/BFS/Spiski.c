/*
//������ - �������� ���������� �������
//�������� ������
typedef struct list
{
    int data; //����� ��������
    struct list* next; //��������� �� ��������� �������
} list;
//������������� ������
list* init_list(int value) // �- �������� ������� ����
{
    list* checked;
    checked = (list*)malloc(sizeof(struct list));
    checked->data = value;
    checked->next = NULL;
    return(checked);
}
//���� ����������
list* getLast_list(list* last)
{
    while (last->next)
    {
        last = last->next;
    }
    return last;
}
//���������� � ������
list* add_list(list* checked, int number)
{
    list* last = getLast_list(checked);
    list* temp = (list*)malloc(sizeof(list));
    checked->next = temp;
    temp->data = number;
    temp->next = NULL;
    return(temp);
}
*/