
#TrieNode class
class Node():
    def __init__(self, val=''):
        #char value the node holds
        self.val = val
        #dictionary of its children
        self.child = {}

#Trie class
class Trie():

    #Constructor
    def __init__(self):
        self.root = Node('*')
        self.nodeCount = 0

    #Makes the trie empty
    def MAKENULL(self):
        self.root = Node()

    #Return Node Count
    def GETCOUNT(self):
        return self.nodeCount

    #Inserts word into character
    def INSERT(self, word):
        #Traversal node
        node = self.root
        #Append $ to denote end of word
        word += '$'
        #Check each character in word and insert
        for c in word:
            #If not present add increment counter
            if (c not in node.child):
                self.nodeCount += 1
                node.child[c] = Node(c)
            #Move to the next node
            node = node.child[c]


def main():
    #Create a trie
    T = Trie()

    #Read from file and insert words into trie
    F = open('alice30.txt', 'r')
    for line in F:
            wordList = line.split(' ')
            for word in wordList:
                T.INSERT(word)

    trieNodes = str(T.GETCOUNT())
    #Print out result
    print("\nTrie Implementation \n")
    print("Words Inserted from document: Alice in Wonderland")
    print("------------------------------------------------------")
    print("Total number of Trie Nodes: " + trieNodes)

main()
