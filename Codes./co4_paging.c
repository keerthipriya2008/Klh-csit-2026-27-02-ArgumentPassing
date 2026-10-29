#include <stdio.h>

int main()
{
    int logical_address;
    int page_size;

    int page_table[] = {5, 3, 7, 1};

    int number_of_pages = 4;

    printf("====================================\n");
    printf("      CO4 - VIRTUAL MEMORY\n");
    printf("====================================\n");

    printf("Enter logical address: ");
    scanf("%d", &logical_address);

    printf("Enter page size: ");
    scanf("%d", &page_size);

    if (page_size <= 0)
    {
        printf("Invalid page size.\n");
        return 1;
    }

    int page_number = logical_address / page_size;

    int offset = logical_address % page_size;

    printf("\nLogical Address: %d\n",
           logical_address);

    printf("Page Size: %d\n",
           page_size);

    printf("\nPage Number: %d\n",
           page_number);

    printf("Offset: %d\n",
           offset);

    if (page_number >= number_of_pages)
    {
        printf("\nPage fault: Page is not present in page table.\n");
        return 0;
    }

    int frame_number = page_table[page_number];

    int physical_address =
        (frame_number * page_size) + offset;

    printf("\nPage Table:\n");

    printf("----------------------\n");
    printf("Page       Frame\n");
    printf("----------------------\n");

    for (int i = 0; i < number_of_pages; i++)
    {
        printf("%d          %d\n",
               i,
               page_table[i]);
    }

    printf("\nFrame Number: %d\n",
           frame_number);

    printf("Physical Address: %d\n",
           physical_address);

    return 0;
}