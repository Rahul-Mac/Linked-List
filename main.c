#include "LinkedList.h"

int main()
{
	LinkedList *first = NULL;
	add_at_end(1, &first);
	add_at_end(2, &first);
	add_at_end(3, &first);
	add_at_end(4, &first);
	add_at_end(5, &first);
	print(&first);
	delete_at_end(&first);
	print(&first);
	add_at_start(0, &first);
	print(&first);
	delete_at_start(&first);
	print(&first);
	printf("\n%d", linked_list_length(&first));
	add_at_position(99, &first, 2);
	print(&first);
	add_at_position(88, &first, 0);
	print(&first);
	add_at_position(77, &first, linked_list_length(&first) - 1);
	print(&first);
	delete_at_position(&first, 3);
	print(&first);
	delete_at_position(&first, 0);
	print(&first);
	delete_at_position(&first, linked_list_length(&first) - 1);
	print(&first);
	printf("\n%d", search_node(&first, 77));
	printf("\n%d", get_node(&first, 3));
	delete_all(&first);
	print(&first);
	add_at_end(8, &first);
	add_at_end(7, &first);
	add_at_end(6, &first);
	add_at_end(5, &first);
	add_at_end(4, &first);
	add_at_end(3, &first);
	add_at_end(2, &first);
	add_at_end(1, &first);
	print(&first);
	sort_linked_list(&first);
	print(&first);
	reverse_linked_list(&first);
	print(&first);
	return 0;
}