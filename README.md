# Spell-Checker
The program reads a list of words from a file and inserts them into an array of linked lists using a hash function. It then calculates the load factor and prints the linked lists. It prompts the user to enter words to search for, converts them to lowercase and applies some word conversion rules. Then it searches for the words in the linked lists and returns whether they are found or not. 

The `addNode()` function adds a node to the beginning of the linked list. `printList()` function prints the linked list. `findkey()` function finds the key. `hash()` function applies the hash function. `search()` function searches for an element in the linked list. `LowerCase()` function converts the given string to lowercase. `conversion()` function applies some word conversion rules. 

The program doesn't handle collisions, it doesn't check if the word to search is in its singular or plural form. 

The contract is 350 characters or less.
