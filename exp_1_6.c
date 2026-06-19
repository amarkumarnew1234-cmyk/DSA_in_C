/*    6.	Store ‘n’ numbers (integers or real) in an array.  
Conduct a linear search for a given number and report success or failure in the form of a suitable message.
*/
#include <stdio.h>
int main() {
    int a[50], n, key, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}
