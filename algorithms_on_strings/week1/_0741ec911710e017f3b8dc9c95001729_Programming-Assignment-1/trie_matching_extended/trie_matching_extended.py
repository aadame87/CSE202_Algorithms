# python3
import sys

NA = -1

class Node:
	#def __init__ (self):
		#self.next = [NA] * 4
		#self.patternEnd = False
    def __init__(self, pattern=None, children=None):
        if pattern is None:
            pattern = False

        if children is None:
            children = dict()

        self.pattern = pattern
        self.children = children


def outgoing_edge(tree, node_id, symbol):
    node = tree.get(node_id)
    if node is not None:
        return node.children.get(symbol)
    return None


def build_trie(patterns):
    tree = dict()
    # write your code here
    tree[0] = Node()
    max_node = 0
    for pattern in patterns:
        current_node = 0
        for idx in range(len(pattern)):
            current_symbol = pattern[idx]
            edge = outgoing_edge(tree, current_node, current_symbol)
            if edge is not None:
                current_node = tree[current_node].children[current_symbol]
            else:
                node = tree.get(current_node)
                if node is not None:
                    node.children[current_symbol] = max_node + 1
                else:
                    tree[current_node] = Node()
                    tree[current_node].children[current_symbol] = max_node + 1
                current_node = max_node + 1
                max_node = current_node

        if tree.get(current_node) is None:
            tree[current_node] = Node(pattern=True)
        else:
            tree[current_node].pattern = True

    return tree

def is_leaf(current_node, tree):
    node = tree[current_node]
    return node.pattern and (len(node.children) is 0)


def find_edge(tree, current_node, symbol):
    node = tree.get(current_node)
    if node is not None:
        for child in node.children:
            if symbol is child:
                return node.children[symbol]
    return None


def is_pattern(current_node, tree):
    node = tree.get(current_node)
    if node:
        return node.pattern
    return False

def prefix_trie_matching(text, tree):
    symbol_pos = 0
    current_node = 0
    pat_found = False
    while symbol_pos < len(text):
        symbol = text[symbol_pos]
        edge = find_edge(tree, current_node, symbol)
        if edge is not None:
            current_node = edge
            if tree[current_node].pattern:
                break
        else:
            break
        symbol_pos += 1

    if is_leaf(current_node, tree):
        pat_found = True
    elif is_pattern(current_node, tree):
        pat_found = True

    return pat_found

def solve (text, n, patterns):
    tree = build_trie(patterns)

    result = []

    txt = text

    offset = 0

    while len(txt) > 0:
        pat_found = prefix_trie_matching(txt, tree)
        if pat_found is True:
            result.append(offset)

        txt = txt[1:]
        offset += 1

	return result

text = sys.stdin.readline ().strip ()
n = int (sys.stdin.readline ().strip ())
patterns = []
for i in range (n):
	patterns += [sys.stdin.readline ().strip ()]

ans = solve (text, n, patterns)

sys.stdout.write (' '.join (map (str, ans)) + '\n')
